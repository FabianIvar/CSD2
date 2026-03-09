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
  float* valuesOld = allocate<float>(oldSize);

  // fill initialized buffer (buffer was initialized with 0)
  for (uint i = 0; i < oldSize; i++) valuesOld[i] = (float)i;

  // Printing uninterpolated buffer from index 0 to size
  logArray<float>(valuesOld, oldSize, "valuesOld");


  /* diff is the amount of values that should be added or deleted
  depending on if the new buffer is bigger or smaller than the old buffer */
  int diff = std::abs(int(newSize - oldSize));
  std::cout << "\ndiff: " << diff << std::endl;

  int stepSize = newSize/diff;
  std::cout << "stepsize: " << stepSize << std::endl;
  uint test1 = 5;
  uint test2 = 10;
  std::cout << "uint test: " << test1 * test2 << std::endl;

  uint* targetIds = allocate<uint>(diff);

  std::cout << "targetIds: " << targetIds << std::endl;

  /* the new (resized) buffer should contain the previous buffer with the
  missing values distributed evenly (euclidean), or the extra values deleted.
  make an array containing the target indexes */
  for (int i = 0; i < diff; i++) {
    targetIds[size_t(i)] = i * stepSize;
  }

  logArray<uint>(targetIds, diff, "targetIds");

  std::cout << "\n" << std::endl;

  // create new buffer
  float* valuesNew = allocate<float>(newSize);
  uint counter = 0;

  if (newSize > oldSize) {
    for (uint i = 0; i < oldSize; i++) {

      if (i == targetIds[counter]) {
        valuesNew[i+counter] = valuesOld[i-counter];
        counter++;
        std::cout << "value: " << valuesNew[i+counter]
          << " <> counter: " << counter
          << " <> index: " << i << std::endl;
        if (i > 0) {
          valuesNew[i+counter] = valuesOld[i-counter];
        }
        else {
          valuesNew[i+counter] = valuesOld[i];
        }
        std::cout << "  value: " << valuesNew[i+counter]
          << " <> counter: " << counter
          << " <> index: " << i << std::endl;

      }
      else {
        valuesNew[i] = valuesOld[i-counter];
        std::cout << "    value: " << valuesNew[i+counter]
          << " <> counter: " << counter
          << " <> index: " << i << std::endl;
      }
    }
  }

  //
  //     if (contains<uint>(targetIds, diff, i)) {
  //       valuesNew[i+counter] = valuesOld[i];
  //
  //       std::cout << "value: " << valuesNew[i+counter]
  //       << " <> counter: " << counter
  //       << " <> index: " << i << std::endl;
  //     }
  //     else {
  //       valuesNew[i+counter] = valuesOld[i];
  //       std::cout << "  value: " << valuesNew[i+counter]
  //       << " <> counter: " << counter
  //       << " <> index: " << i << std::endl;
  //       counter++;
  //     }
  //
  //
  //   }
  // }




  logArray<float>(valuesNew, newSize, "valuesNew");


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
