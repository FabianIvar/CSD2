#include <iostream>
#include <typeinfo>
using namespace std;

namespace BufferTools {
  typedef unsigned int uint;

  template<typename A>
  inline A* allocate(uint size) {
    A* buffer = (A*)malloc(size * sizeof(A));
    memset(buffer, 0.0f, size * sizeof(A));
    return buffer;
  }

  template<typename L>
  void logArray(L* buffer, uint size, std::string arrName) {
    // Printing buffer from 0 to size
    std::cout << "\n" + arrName + ": ";
    for (uint i = 0; i < size; i++) std::cout << buffer[i] << ", ";
  }

}

int main() {
  cout << endl;
  #if DEBUG
  cout <<
    "Starting program...\n"
  << endl;
  #endif
//============================================================================//

  float* testBuffer = BufferTools::allocate<float>(5);
  auto& refToTestBuffer = testBuffer;
  BufferTools::logArray<float>(testBuffer, 10, "testBuffer");
  BufferTools::resetSize<float>(refToTestBuffer, 10);
  BufferTools::logArray<float>(testBuffer, 10, "testBuffer");

  float arrayGuy[] = {1.0f, 2.0f, 3.0f};
  float (&aliasToArrayGuy)[] = arrayGuy;

  // float* test = &aliasToThisGuy;

  cout << "\n\n" <<
    *aliasToArrayGuy << " of type: " << typeid(*aliasToArrayGuy).name()
  << endl;

//============================================================================//
  #if DEBUG
  cout <<
    "\nProgram finished... shutting down"
  << endl;
  #endif

  cout << endl;
  return 0;
}
