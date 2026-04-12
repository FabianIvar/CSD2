#pragma once

typedef unsigned int uint;

struct CircBuffer {

  CircBuffer(uint size, uint distRW);
  ~CircBuffer();

  void resetSize(uint size);

  /* 'setDistRW' sets the distance between the read
     head and the write head */
  void setDistRW(uint distRW); // sets Distance
  uint getDistRW();

  inline void write(float val) { // Writes val in buffer at writeH
    m_buffer[m_writeH] = val; }

  inline float read() { // Reads val in buffer at readH
    return m_buffer[m_readH]; }

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

  void allocateBuffer();
  void releaseBuffer();

  float* m_buffer;
  uint m_size;   // Number of samples in the buffer
  uint m_readH;  // index in buffer, position of the readhead
  uint m_writeH; // index in buffer, position of the writehead
  uint m_distRW; // Distance between the readH and writeH
};
