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


//======[Prepare]======

int main(int argc, char **argv) {

  typedef std::string str;

  float freq = 960; // 50 samples for one cycle??


  CircBuffer CircBuffer(200, 12); // (size | dist)

  Oscillator* square = new Square(960, 48000); // (freq | rate)

  const str sourcePath = SOURCE_DIR;

  WriteToFile fileWriter( // (path | overwrite)
    sourcePath + "/utils/buffer.csv", true);

  float squareSample = 0;


// ======[Circular buffer example]======

  std::cout << "\n-=<(Circular Buffer Test)>=-" << std::endl;
  for (int i = 0; i < 200; i++) { // Plot for results
    squareSample = square->getSample();

    CircBuffer.write(squareSample);
    std::cout << CircBuffer.read();
    fileWriter.write(std::to_string(CircBuffer.read()) + "\n");
    CircBuffer.tick();
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

    return 0;
}
