/* Dit is een update van '01_circular_buffer_test'.
Hierbij zorg ik dat de 'indexes' van de read en write
heads floats zijn, wat later logischer is voor interpolatie. */

#include <iostream>
#include <thread>
#include "utils/writeToFile.hpp"
#include "oscillators/square.hpp"
#include "circBuffer.hpp"
#include "interpolation.hpp"

using namespace Interpolation;

#define BUFFER_SIZE 200
#define DEBUG 1


//======[Prepare]======

int main(int argc, char **argv) {

  typedef const std::string str;

  float freq = 960; // 50 samples for one cycle??

  CircBuffer buffer(BUFFER_SIZE, 12); // (size | dist)

  Oscillator* square = new Square(960, 48000); // (freq | rate)

  str sourcePath = SOURCE_DIR;

  WriteToFile buffExamle( // (path | overwrite)
    sourcePath + "/utils/circBuffer_test.csv", true);

  WriteToFile interpExample( // Interpolation example
    sourcePath + "/utils/interpolation_test.csv", true);

  float squareSample = 0;


// ======[Circular buffer example]======

  std::cout << "\n-=<(Circular Buffer Test)>=-" << std::endl;
  for (int i = 0; i < BUFFER_SIZE; i++) { // Plot for results
    squareSample = square->getSample();

    buffer.write(squareSample);
    std::cout << buffer.readH();
    buffExamle.write(std::to_string(0.5*(squareSample + buffer.readH())) + "\n");
    buffer.tick();
    square->tick();
  }

  std::cout <<
    "\nWrote results of circular buffer example to 'output.csv'\n"
  << std::endl;


// ======[Interpolation example]======

  std::cout << "-=<(Interpolation Test)>=-" << std::endl;

  std::cout << nearestNeighbour<float>(0.1, 1.0, 3.0) << std::endl;
  std::cout << linear<float>(0.1, 1.0, 3.0) << std::endl;
  std::cout << bilinear<float>(2.3, 2, 3, 20, 30) << std::endl;


// ======[Iterating through buffer]======

  float fpIndex = 0.0f;

  while (fpIndex < (BUFFER_SIZE - 1)) {
    float remainder = fpIndex - static_cast<int>(fpIndex);
    uint i = static_cast<size_t>(fpIndex);

    float output = linear<float>(remainder, buffer.read(i), buffer.read(i+1));

    interpExample.write(std::to_string(output) + "\n");

    fpIndex += 0.5f; // incrValue

    #if DEBUG
      std::cout << "output: " << output << std::endl;
    #endif
  }






  return 0;
}
