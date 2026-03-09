#include <iostream>
#include "interpolation.hpp"
using namespace Interpolation;

#define OLD_SIZE 9
#define NEW_SIZE 18

int main() {
  std::cout << std::endl;
  #if DEBUG
  std::cout <<
    "Starting program...\n"
  << std::endl;
  #endif
//============================================================================//


  unsigned int oldSize = OLD_SIZE;
  unsigned int newSize = NEW_SIZE;
  float* valuesOld = newBuffer(oldSize);

  // fill initialized buffer (buffer was initialized with 0)
  for (uint i = 0; i < oldSize; i++) valuesOld[i] = (float)i;

  // Printing uninterpolated buffer from index 0 to size
  logBuffer(valuesOld, oldSize);

  // create new buffer
  float* valuesNew = newBuffer(newSize);

  // fill new buffer interpolate previous buffer
  uint oldBuffPos = 0;
  for (unsigned int i = 0; i < newSize -1; i++) {

    if (isEven(i)){
      valuesNew[i] = valuesOld[oldBuffPos];
      oldBuffPos++;
      std::cout << "oldBuffPos:" << oldBuffPos << "\n\nbang\n" << std::endl;
      }
    else {
      valuesNew[i] = nearestNeighbour<float>(
        valuesOld[oldBuffPos] + 0.5, valuesOld[oldBuffPos],
        valuesOld[oldBuffPos+1]);
        std::cout << "valuesOld + 0.5: " << valuesOld[oldBuffPos] + 0.5 <<
          "\nvaluesOld[oldBuffPos]: " << valuesOld[oldBuffPos] <<
          "\nvaluesOld[oldBuffPos+1]: " << valuesOld[oldBuffPos+1]
          << "\nvaluesNew[i]: " << valuesNew[i] << std::endl;
    }
  }

  logBuffer(valuesNew, newSize);


//============================================================================//


  std::cout << std::endl;
  bool running = true;
  std::string input;

  while (running) {
    std::getline(std::cin, input);
    if (input == "q") running = false;
  }

  free(valuesOld);
  free(valuesNew);


//============================================================================//
  #if DEBUG
  std::cout <<
    "\nProgram finished... shutting down"
  << std::endl;
  #endif

  std::cout << std::endl;
  return 0;
}
