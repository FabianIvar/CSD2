#include <iostream>
using namespace std;

#define SIZE 7
#define DIST 3


struct Buffer {

  typedef unsigned int uint;

  Buffer(float* writeH, float* readH) :
    writeH(writeHead), readH(readHead), buff(buffer) {
      size = arrlen(buffer);
    }

  void incr() {
    float* heads[2] = {writeHead, readHead};
    for (float* i : heads) {
      i++;
      if (i > sizeof(float) * size) cout << "test" << endl;
      wrap(i);
    }
  }

  void wrap(head) {

  }

  uint arrLen(float array){
    return sizeof(array) / sizeof(array[0]);
  }

private:
  float buffer[] = {1.0f,2.0f,3.0f,4.0f,5.0f,6.0f};
  float* writeHead;
  float* readHead;
  uint size;
};



int main() {
  cout << endl;
  #if DEBUG
  cout <<
    "Starting program...\n"
  << endl;
  #endif
//============================================================================//

  typedef unsigned int uint;

  // float buffer[SIZE] = {1.0f,2.0f,3.0f,4.0f,5.0f,6.0f};
  // float* writeHead = &buffer[0];
  // float* readHead = writeHead - sizeof(float) * DIST;

  for (float i : buffer) cout << i << " | ";

  for (uint i = 0; i < 8; i++) {
    if (writehead)
    cout << "\n\n" << i << " writehead address: " << writehead
         << "\nwritehead value: " << *writehead;
    utility::incr();

  }

//============================================================================//
  #if DEBUG
  cout <<
    "\nProgram finished... shutting down"
  << endl;
  #endif

  cout << endl;
  return 0;
}
