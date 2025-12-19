#include <iostream>
#include <numeric>
#include "utils.h"
using namespace std;

#define DEBUG 1

string utils::color(string textInput, string color) {
  #if DEBUG
  cout << "utils::color" << endl;
  #endif

  string ansiColors[14] = {
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
    "brightCyan",
  };

  string ansiCode;

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

  string prefix = "\x1B[" + ansiCode + "m";
  string suffix = "\033[0m";
  string output = prefix + textInput + suffix;

  #if DEBUG
  cout << "outut: " << output << endl;
  #endif

  return output;
}

float utils::arrSum(float inputArray[]) {
  #if DEBUG
  cout << "utils::arrSum" << endl;
  #endif

  int inputArrayLength = sizeof(inputArray[6]) / sizeof(inputArray[0]);


  /* NOTE: accumulate() might only be able to return ints,
  if a bug arises this might be the issue.
  Also inputArrayLength is an int and inputArray is a float.
  I don't know if this is allowed. */

  float summedArray = accumulate(inputArray, inputArray + inputArrayLength, 0);

  #if DEBUG
  cout <<
    "inputArrayLength: " << inputArrayLength <<
    "\nsummedArray: " << to_string(summedArray) << endl;
  #endif

  return summedArray;
}

float utils::constrain(float inputValue, float minimum, float maximum) {
  // NOTE: will return the value with the highest resolution.

  float constrainedValue = min(maximum, max(minimum, inputValue));

  return constrainedValue;
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
