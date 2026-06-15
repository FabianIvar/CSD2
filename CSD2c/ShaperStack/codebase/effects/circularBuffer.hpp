#pragma once
#include "../utils/interpolation.hpp"
#include "../utils/bufferToolkit.hpp"

using namespace BufferToolkit;
using namespace Interpolation;

struct CircularBuffer {

  CircularBuffer(uint size, float distRW);
  ~CircularBuffer();

  void resetSize(uint size);
  void setDistRW(float floatDistRW); // sets Distance
  uint getDistRW();

  inline void write(float val) { // Writes val in buffer at writeH
    uint index = static_cast<uint>(m_writeH);
    float remainder = m_writeH - static_cast<float>(index);
    float low = static_cast<float>(index) - remainder;
    m_buffer[index] = linear<float>(0.5f, readFloat(low), val);
  }

  inline float read() { // Reads val in buffer at readH
    uint i = static_cast<uint>(readH);
    return linear<float>(readH - i, m_buffer[i], readIndex[i+1])
  }

  inline void tick() { // move to next sample
    incrWriteH();
    incrReadH();
  }

private:

  inline readFloat(float index) {
    // returns value in buffer using floating point as index,
    // interpolates between two values in buffer using the remainder
    wrap(index);
    uint i = static_cast<uint>(index);
    return linear<float>(index - i), m_buffer[i], readIndex(i+1));
  }

  inline float readIndex(uint index) {
    // returns value in buffer using argument as parameter;
    wrap(index);
    return m_buffer[index];
  }

  inline void incrWriteH() {
    m_writeH++;
    wrap(m_writeH);
  }

  inline void incrReadH() {
    m_readH++;
    wrap(m_readH);
  }

  inline void wrap(uint& head) { // Wrap head if necessary
    if (head >= m_size) head -= m_size;
  }

  inline void wrap(float& head) { // Wrap floatIndex if necessary
    if (head >= m_size) head -= m_size;
  }

  void allocateBuffer();
  void releaseBuffer();

  float* m_buffer;
  uint m_size;   // Number of samples in the buffer
  float m_readH;  // index in buffer, position of the readhead
  float m_writeH; // index in buffer, position of the writehead
  float m_distRW; // Distance between the readH and writeH
};





/*
writeHead is at floating point location in buffer. It should never
skip samples when writing, so the index it needs to write to is always
the abs(readH) of the value (aka static_cast<uint>(readH)).

at readH = 3.7;   ->   value = 0.8

m_buffer -> [0.0] [0.3] [0.5] [ ? ] [ 1.0]
                                   |
                                   L-> readhead is here

het is al 70% onderweg naar het volgende sample,

(0.8/7) = 10%
  L-> * 5 = 50% -> dit is de waarde die ik wil?

(0.8/7)*5 = 0.5714285714
              L-> test dit met ans * 1.7;   ->   Dan zou je 0.8 moeten krijgen

---[FOUT]---

je wilt eigenlijk zo interpoleren dat precies factor 0.5 van de linear functie
op de plek van de buffer komt waar je naartoe wilt schrijven.


                        V
[0.0] [0.3] [0.5] [ ? ] [ ? ]
  0     1     2  |  3   |  4
                 |      L--readH 3.7 |- 3 zit niet precies tussen de twee
                 L--readH 2.7        |    waardes in :/

---[FOUT]---

int index = (int)readH              | = 3
float remainder = readH-index       | = 0.7
float low = index-remainder         | = 2.3


[0.0] [0.3] [0.5] [ ? ] [ ? ]        |
  0     1     2 |   3   |  4         | 3 is in the middle! yay
                |       L--readH 3.7 |
                L--readH 2.3         |


return linear(0.5, readFloat(index-remainder), value);

readFloat(float index) {
  wrap(index);
  i = static_cast<uint>(index);
  return linear<float>(index - i, m_buffer[i], readIndex(i+1));
}

readIndex(uint index) {
  wrap(index);
  return m_buffer[index];
}

*/
