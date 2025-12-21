#include <iostream>
#include <numeric>
#include "utils.h"
#include <cmath>
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
        ansiCode = to_string(83 + i);
      }
    }
  }

  string suffix = "\033[0m";
  string prefix = "\x1B[" + ansiCode + "m";
  string output = prefix + textInput + suffix;

  #if DEBUG
  cout << "outut: " << output << endl;
  #endif

  return output;
}

// template <typename T>
// T arrSum(T arr[], int start, int stop) {
//   T output = 0;
//
//   for (int i = start; i <= stop; i++) {
//     output += arr[i];
//   }
//   return output;
// }

// template <typename T>
// T utils::constrain(T inputValue, T minimum, T maximum) {
//   return min(maximum, max(minimum, inputValue));
// }

float utils::noteSampleDur(float lenQNotes, int sampleRate) {
  #if DEBUG
  cout << "utils::noteSampleDur" << endl;
  #endif

  /* lenQNotes means the note length expressed as amount of quarter notes.
  lenQNotes = 2.0 means 2 quarter notes, so a half note.
  With a bpm of 120, a quarter note is: 60/ 120 = 0,5
  With a sampleRate of 44100 samples per second,
  The amount of samples in 0,5 seconds is 44100 * 0,5 = 22050 samples */

  float noteTimeDurSec = (60.0f/120.0f) * lenQNotes;
  int durInSamples = sampleRate * noteTimeDurSec;

  #if DEBUG
  cout << ">>> " << lenQNotes << " " << sampleRate << " " << noteTimeDurSec << " " << endl;
  #endif

  return durInSamples;
}

float utils::mtof(int midiPitch) {
/* Source - https://git.jaydee.systems/chromaticsol/CSD2/src/commit/c8c69fe00e59fb6191f1c6304b2514295bc0057d/CSD2b/SynthTests/Codebase/utils.cpp
By Vida, slightly modified to fit this project. */

  float frequency = 440.0f * pow(2.0f, (midiPitch - 69.0f) / 12.0f);
  return frequency;
}

float utils::velToAmp(int midiVel) {
  float amplitude = midiVel / 127.0f;
  return amplitude;
}
