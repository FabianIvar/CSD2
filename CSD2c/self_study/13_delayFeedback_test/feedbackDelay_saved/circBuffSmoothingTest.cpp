#include "circularBuffer.hpp"
#include <iostream>

CircularBuffer::CircularBuffer(uint size, float distRW)
  : m_size(size), m_writeH(0) {

  for (float i : m_readH) i = 0.0f;

  setDistRW(distRW);


  m_buffer = allocate<float>(m_size);


  #if DEBUG
    std::cout << "CircularBuffer Constructor" << std::endl;
  #endif
}

CircularBuffer::~CircularBuffer() {
  free(m_buffer);

  #if DEBUG
    std::cout << "CircularBuffer Destroyed" << std::endl;
  #endif
}

float CircularBuffer::getDistRW() { return m_distRW; }
uint CircularBuffer::getSize() { return m_size; }

void CircularBuffer::resetSize(uint targetSize) {
  m_size = targetSize;
  free(m_buffer);
  m_buffer = allocate<float>(m_size);
}
