#include <iostream>
#include <sstream>
#include "utils.h"
using namespace std;

std::string utils::color(std::string textInput, std::string color) {
  #if DEBUG
  cout << "utils::color" << endl;
  #endif

  std::string ansiColors[14] = {
    "red",
    "green",
    "yellow",
    "blue",
    "magenta",
    "cyan",
    "white",
    "brightBlack",
    "brightRed",
    "brightGreen",
    "brightYellow",
    "brightBlue",
    "brightMagenta",
    "brightCyan"
  };

  std::string ansiCode;

  for (int i = 0; i < 14; i++) {
    if (!(color.compare(ansiColors[i]))) {
      if (i <= 6) {
        // ANSI code 30 is black and not visable in the terminal
        ansiCode = to_string(31 + i);
      }
      else {
        // Starting from 90 are the bright variants of the colors
        ansiCode = to_string(90 + i);
      }
    }
  }

  std::string prefix = "\x1B[" + ansiCode + "m";
  std::string suffix = "\033[0m";
  std::string output = prefix + textInput + suffix;

  #if DEBUG
  cout << "outut: " << output << endl
  #endif

  return output;
}

float utils::arrSum(float inputArray[], int start, int stop) {

    float output = 0;
    for (int i = start; i <= stop; i++) {
      output += inputArray[i];}

    return output;
}

float utils::constrain(float inputValue, float minimum, float maximum) {

  return min(maximum, max(minimum, inputValue));
}

double utils::noteSampleDur(int bpm, float lenQNotes, double sampleRate) {
  #if DEBUG
  cout << "utils::noteSampleDur" << endl;
  #endif

  /* lenQNotes means the note length expressed as amount of quarter notes.
  lenQNotes = 2.0 means 2 quarter notes, so a half note.
  With a bpm of 120, a quarter note is: 60/ 120 = 0,5
  With a sampleRate of 44100 samples per second,
  The amount of samples in 0,5 seconds is 44100 * 0,5 = 22050 samples */

  double noteTimeDurSec = (60 / bpm) * lenQNotes;
  double durInSamples = sampleRate * noteTimeDurSec;

  #if DEBUG
  cout << "durInSamples" << endl;
  #endif

  return durInSamples;
}

double utils::mtof(int midiPitch) {
/* Source - https://git.jaydee.systems/chromaticsol/CSD2/src/commit/c8c69fe00e59fb6191f1c6304b2514295bc0057d/CSD2b/SynthTests/Codebase/utils.cpp
By Vida, slightly modified to fit this project. */

  double frequency = 440 * pow(2.0, (midiPitch - 69));
  return frequency;
}

double utils::velToAmp(int midiVel) {
  double amplitude = midiVel / 127;
  return amplitude;
}

//============================================================================//

template<typename T> string utils::pToString(const T& pointer) {
  stringstream ss;
  ss << static_cast<void*>(pointer);
  return ss.str();
}

//
// std::string utils::pToString(float* pointer) {
//   std::stringstream ss;
//   ss << static_cast<void*>(pointer);
//   return ss.str();
// }
//
// std::string utils::pToString(double* pointer) {
//   std::stringstream ss;
//   ss << static_cast<void*>(pointer);
//   return ss.str();
// }

/* TODO:
*/

/* DONE:
- constrain !! might not work lol
- velToAmp
- mtof
- color
- arrSlice
- arrSum
- noteSampleDur (time in ms) -> different from qNoteLength

*/
