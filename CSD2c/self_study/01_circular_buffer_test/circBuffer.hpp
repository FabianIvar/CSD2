#pragma once

typedef unsigned int uint;

/* QUESTION:

- Why unsigned int?
  because malloc uses an unsigned integral value which
  represents the memory block in bytes.
  sizeof() returns an unsigned int.

*/


struct CircBuffer {
  /* size = the number of samples in the buffer this
     is the first argument of the buffer object */

  CircBuffer(uint size, uint distRW); // constructor
  ~CircBuffer(); // destructor

  void resetSize(uint size);

  /* For setting the distance between the read head
     and the write head */
  void setDistRW(uint distRW);
  uint getDistanceRW();

  /* 'write()' Writes a value (val) at the position
     of the write-head */
  inline void write(float val) {
    buffer[valWriteH] = val;}

  /* 'read()' Reads a value at the position of the
     read-head */
  inline float read() {
    return buffer[valReadH];}

  // move to next sample
  inline void tick() { // incr stands for increase
    incrWriteH();
    incrReadH();
  }

  //! inline void tick() {
  //!   for (uint i : heads) {
  //!     i++;
  //!     if (i >= size) i -= size;
  //!   }
  //! }

  inline void incrHeads(uint& head) {

  }

private:
  // increase write and read heads and wrap if necessary
  /* NOTE: Kinda duplicate code, also I think wrapping
     can be done with pointer arithmetic
     BUT maybe it is useful to seperate increasing readhead
     and writehead? for idk reverse delay and stuff idk*/

  inline void incrWriteH() {
    valWriteH++;
    wrapHeads(valWriteH);
  }

  inline void incrReadH() {
    valReadH++;
    wrapHeads(valReadH);
  }

  inline void wrapHeads(uint& head) {
    if (head >= size) head -= size;
  }

  /* allocate memory and release methods (member functions),
     used to alter the buffer size.
     allocate makes sure there is memory available for the buffer
     and release empties the buffer.*/

  void allocateBuffer();
  void releaseBuffer();

  float* buffer;
  uint size;
  uint valReadH;
  uint valWriteH;
  uint distRW;
  //! uint heads[2] = {valReadH&, valWriteH&};
};
