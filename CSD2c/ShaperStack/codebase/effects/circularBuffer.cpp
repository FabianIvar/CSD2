#include "circularBuffer.hpp"


CircularBuffer::CircularBuffer(int size, float distRW) : m_size(size),
  m_readH(0), m_writeH(0) {

  std::cout << "CircularBuffer Constructor" << std::endl;
  allocateBuffer();
  setDistRW(distRW);
}

CircularBuffer::~CircularBuffer() {
  free(m_buffer);
  std::cout << "CircularBuffer Destroyed" << std::endl;
}

void CircularBuffer::resetSize(int size) {
  m_size = size;
  free(m_buffer);
  allocateBuffer();
}

void CircularBuffer::allocateBuffer() { m_buffer = allocate<float>(m_size); }
