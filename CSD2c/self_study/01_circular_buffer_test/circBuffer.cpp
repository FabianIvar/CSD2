#include "circBuffer.hpp"
#include <iostream>
#include <cstring>

CircBuffer::CircBuffer(uint size, uint distRW) :
  size(size), valReadH(0), valWriteH(0) {
    allocateBuffer();
    setDistRW(distRW);
  }

CircBuffer::~CircBuffer() {
  releaseBuffer();
}

void CircBuffer::resetSize(uint size)
{
  this->size = size;
  releaseBuffer();
  allocateBuffer();
}

/* NOTE:
'malloc' (memory allocate) and 'free()' (free memory)
are alternatives for new and delete. New calls the
constructor. malloc only allocates the memory. Also,
new will throw on failure while malloc returns Null.
new is an operator and malloc() is a function.

*/

void CircBuffer::allocateBuffer() {
  // Allocates buffer
  buffer = (float*)malloc(size * sizeof(float));
  // Initializes buffer with 0
  memset(buffer, 0, size * sizeof(float));
}

void CircBuffer::releaseBuffer() {
  // free data allocated with malloc and memset
  free(buffer);
}

void CircBuffer::setDistRW(uint distRW) {
  this->distRW = distRW;
  valReadH = valWriteH - distRW + size;
  wrapHeads(valReadH);
}

uint CircBuffer::getDistanceRW() {
  return distRW;
}
