#pragma once
#include "../utils/interpolation.hpp"
#include "../utils/bufferToolkit.hpp"

using namespace BufferToolkit;
using namespace Interpolation;

struct CircularBuffer {

  CircularBuffer(uint size, uint distRW);
  CircularBuffer(uint size, float distRW);
  ~CircularBuffer();

  void resetSize(uint size);
  void setDistRW(uint distRW); // sets Distance
  void setDistRW(float distRW); // sets Distance
  uint getDistRW();

  inline void writeH(float val) { // Writes val in buffer at writeH
    m_buffer[m_writeH] = val; }

  inline void write(int index, float value) {
    uint i = static_cast<uint>(index);
    wrap(i);
    m_buffer[i] = value;
  }

  inline float readH() { // Reads val in buffer at readH
    return m_buffer[m_readH]; }

  inline float read(int index) { // Reads val at index
    uint i = static_cast<uint>(index);
    wrap(i);
    return m_buffer[i];
  }

  inline float readInterpolated(float indexFloat) {
    int index = static_cast<int>(indexFloat);
    float remainder = indexFloat - index;

    return linear<float>(remainder, read(index), read(index + 1));
  }

  inline void tick() { // move to next sample
    incrWriteH(); // incr = increase
    incrReadH();
  }

private:

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

  inline void wrap(uint& head) { // Wrap head if necessary
    if (head >= m_size) head -= m_size;
  }

  void allocateBuffer();
  void releaseBuffer();

  float* m_buffer;
  uint m_size;   // Number of samples in the buffer
  uint m_readH;  // index in buffer, position of the readhead
  uint m_writeH; // index in buffer, position of the writehead
  uint m_distRW; // Distance between the readH and writeH
  uint m_floatDistRW; // Distance between the readH and writeH as float
};
