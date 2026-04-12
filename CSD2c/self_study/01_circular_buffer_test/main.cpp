#include <iostream>
#include <thread>
#include "writeToFile.hpp"
#include "oscillators/square.hpp"
#include "circBuffer.hpp"

// #define SAMPLERATE = 48000

/* NOTE:

- argc en argv?
- First argument of CircBuffer is the size of the
  buffer in samples

- Waarom schrijven naar een csv file?
  kan je daar goed de output op zien ofzo?
*/

/* Wat dit programma doet:

Dit programma doet aan multithreading, waarschijnlijk
kan je dan in het CMakeLists.txt aangeven dat sommige
processen tegelijk verlopen? misschien zorgt <thread>
er gewoon voor dat dat gebeurt. IDK :).

verder maakt het een squarewave die door een circular
buffer heen gaat, en schrijft de output van de eerste
200 samples naar een .csv bestand, die je vervolgens
kan plotten met plot.py

*/

//================================================

int main(int argc, char **argv) {

  typedef std::string str;

  float freq = 960; // 50 samples for one cycle

  /* creates a CircBuffer object initialized with
     approximately a quarter cycle.
     (4*12=48) (second argument) */

  CircBuffer CircBuffer(200, 12);

  // Dit is waarschijnlijk voor debug.
  // CircBuffer.logAllSettings();

  /* makes square object initialized with
     a frequency of 960 and a samplerate of 48000 */
  Oscillator* square = new Square(960, 48000);

  const str sourcePath = SOURCE_DIR;
  // last argument (boolean) is for asking of file can be overwritten.
  WriteToFile fileWriter(sourcePath + "/output.csv", true);

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

  std::cout << "\n***** DONE ***** "
    << "\nWrote the sum of the oscillator and the"
    << "delayed value to output.csv." << std::endl;

    return 0;

}
