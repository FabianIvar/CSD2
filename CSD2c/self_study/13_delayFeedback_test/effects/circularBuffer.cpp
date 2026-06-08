#include "circularBuffer.hpp"
#include <iostream>

CircularBuffer::CircularBuffer(uint size, uint distRW) :
  m_size(size), m_readH(0), m_writeH(0)
{
  allocateBuffer();
  setDistRW(distRW);
}

CircularBuffer::~CircularBuffer() { releaseBuffer(); }

void CircularBuffer::resetSize(uint size) {
  m_size = size;
  releaseBuffer();
  allocateBuffer();
}

void CircularBuffer::allocateBuffer() {
  m_buffer = allocate<float>(m_size);
}

void CircularBuffer::releaseBuffer() { free(m_buffer); }

void CircularBuffer::setDistRW(uint distRW) {
  m_distRW = distRW;
  m_readH = m_writeH - m_distRW + m_size; // offset
  wrap(m_readH);
}

uint CircularBuffer::getDistRW() {
  return m_distRW;
}
