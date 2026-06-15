#include "circularBuffer.hpp"
#include <iostream>

CircularBuffer::CircularBuffer(uint size, float distRW) :
  m_size(size), m_readH(0.0f), m_writeH(0.0f) {
  allocateBuffer();
  setDistRW(distRW);
}

CircularBuffer::~CircularBuffer() {
  releaseBuffer();
  #if DEBUG
    std::cout << "Circular Buffer Destroyed" << std::endl;
  #endif
}

void CircularBuffer::resetSize(uint size) {
  m_size = size;
  releaseBuffer();
  allocateBuffer();
}

void CircularBuffer::allocateBuffer() {
  m_buffer = allocate<float>(m_size);
}

void CircularBuffer::releaseBuffer() { free(m_buffer); }

void CircularBuffer::setDistRW(float distRW) {
  // NOTE: smoothing sould be applied
  m_distRW = distRW;
  m_readH = m_writeH - m_distRW;
  wrap(m_readH);
}

uint CircularBuffer::getDistRW() {
  return m_distRW;
}
