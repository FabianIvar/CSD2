/* Dit is een update van '01_circular_buffer_test'.
Hierbij zorg ik dat de 'indexes' van de read en write
heads floats zijn, wat later logischer is voor interpolatie. */

#include <iostream>
#include <thread>
#include "utils/writeToFile.hpp"
#include "oscillators/square.hpp"
#include "circBuffer.hpp"

//================================================



int main(int argc, char **argv) {

  typedef std::string str;

  float freq = 960; // 50 samples for one cycle??


/* First argument is the size of the circular
   buffer in samples */
/* Second argument is the distance between the
   readhead and the write head */
  CircBuffer CircBuffer(200, 12);

/* NOTE: Debug functions like 'logAllSettings'
   might be really useful */

/* makes square object initialized with
   a frequency of 960 and a samplerate of 48000 */
  Oscillator* square = new Square(960, 48000);

  const str sourcePath = SOURCE_DIR;

/* First argument is the path the output will
   write to */
/* Second argument (boolean) is for toggling
   if the output file can be overwritten. */
  WriteToFile fileWriter(
    sourcePath + "/utils/output.csv", true);

  float squareSample = 0;
  for (int i = 0; i < 200; i++) {
    squareSample = square->getSample();

    CircBuffer.write(squareSample);
    std::cout << CircBuffer.read();
    fileWriter.write(std::to_string(
      squareSample + CircBuffer.read()) + "\n");
    CircBuffer.tick();
    square->tick();
  }

  std::cout << "\n-=<( DONE )>=- "
    "\nWrote the sum of the oscillator and the "
    "delayed value to output.csv" << std::endl;

    return 0;
}
