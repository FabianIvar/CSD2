#pragma once
#include "../utils/interpolation.hpp"
#include "../utils/bufferToolkit.hpp"
#define DEBUG 0

using namespace BufferToolkit;
using namespace Interpolation;

struct CircularBuffer {
  CircularBuffer(int size, float distRW);
  ~CircularBuffer();
  void resetSize(int size);

  inline void setDistRW(float distRW) {
    m_distRW = distRW;
    int numSamples = static_cast<int>(m_distRW);
    m_readH = m_writeH - numSamples + m_size;
    wrap(m_readH);
    m_remainder = m_distRW - numSamples;
  }

  inline float read() {
    int high = m_readH+1;
    wrap(high);
    return linear<float>(m_remainder, m_buffer[m_readH], m_buffer[high]);
  }

  inline void write(float val) { m_buffer[m_writeH] = val; }

  inline void tick() {
    incrWriteH();
    incrReadH();
  }

private:
  inline void incrWriteH() { m_writeH++; wrap(m_writeH); }
  inline void incrReadH() { m_readH++; wrap(m_readH); }
  inline void wrap(int& head) { if (head >= m_size) head -= m_size; }

  void allocateBuffer();


//-----[ variables ]-----

  float* m_buffer;
  int m_size;
  int m_readH;
  int m_writeH;
  float m_distRW;
  float m_remainder;
};
