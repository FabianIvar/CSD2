#include "circBuffer.hpp"
#include <iostream>

CircBuffer::CircBuffer(uint size, uint distRW) :
  m_size(size), m_readH(0), m_writeH(0)
{
  allocateBuffer();
  setDistRW(distRW);
}

CircBuffer::~CircBuffer() { releaseBuffer(); }

void CircBuffer::resetSize(uint size) {
  m_size = size;
  releaseBuffer();
  allocateBuffer();
}

void CircBuffer::allocateBuffer() {
  m_buffer = allocate<float>(m_size);
}

void CircBuffer::releaseBuffer() { free(m_buffer); }

void CircBuffer::setDistRW(uint distRW) {
  m_distRW = distRW;
  m_readH = m_writeH - m_distRW + m_size; // offset
  wrap(m_readH);
}

uint CircBuffer::getDistRW() {
  return m_distRW;
}
