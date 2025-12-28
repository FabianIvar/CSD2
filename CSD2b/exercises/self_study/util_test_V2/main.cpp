#include <iostream>
#include <sstream>
#include "utils.h" // denk ik?
using namespace std;
using namespace utils;

#define DEBUG 0


// std::string utils::color(std::string textInput, std::string color) {
//   #if DEBUG
//   cout << "utils::color" << endl;
//   #endif
//
//   std::string ansiColors[14] = {
//     "red",
//     "green",
//     "yellow",
//     "blue",
//     "magenta",
//     "cyan",
//     "white",
//     "brightBlack",
//     "brightRed",
//     "brightGreen",
//     "brightYellow",
//     "brightBlue",
//     "brightMagenta",
//     "brightCyan"
//   };
//
//   std::string ansiCode;
//
//   for (int i = 0; i < 14; i++) {
//     if (!(color.compare(ansiColors[i]))) {
//       if (i <= 6) {
//         // ANSI code 30 is black and not visable in the terminal
//         ansiCode = to_string(31 + i);
//       }
//       else {
//         // Starting from 90 are the bright variants of the colors
//         ansiCode = to_string(90 + i);
//       }
//     }
//   }
//
//   std::string prefix = "\x1B[" + ansiCode + "m";
//   std::string suffix = "\033[0m";
//   std::string output = prefix + textInput + suffix;
//
//   #if DEBUG
//   cout << "outut: " << output << endl
//   #endif
//
//   return output;
// }
//
// float utils::arrSum(float inputArray[], int start, int stop) {
//
//     float output = 0;
//     for (int i = start; i <= stop; i++) {
//       output += inputArray[i];}
//
//     return output;
// }
//
// float utils::constrain(float inputValue, float minimum, float maximum) {
//
//   return min(maximum, max(minimum, inputValue));
// }
//
// double utils::noteSampleDur(int bpm, float lenQNotes, double sampleRate) {
//   #if DEBUG
//   cout << "utils::noteSampleDur" << endl;
//   #endif
//
//   /* lenQNotes means the note length expressed as amount of quarter notes.
//   lenQNotes = 2.0 means 2 quarter notes, so a half note.
//   With a bpm of 120, a quarter note is: 60/ 120 = 0,5
//   With a sampleRate of 44100 samples per second,
//   The amount of samples in 0,5 seconds is 44100 * 0,5 = 22050 samples */
//
//   double noteTimeDurSec = (60 / bpm) * lenQNotes;
//   double durInSamples = sampleRate * noteTimeDurSec;
//
//   #if DEBUG
//   cout << "durInSamples" << endl;
//   #endif
//
//   return durInSamples;
// }
//
// double utils::mtof(int midiPitch) {
// /* Source - https://git.jaydee.systems/chromaticsol/CSD2/src/commit/c8c69fe00e59fb6191f1c6304b2514295bc0057d/CSD2b/SynthTests/Codebase/utils.cpp
// By Vida, slightly modified to fit this project. */
//
//   double frequency = 440 * pow(2.0, (midiPitch - 69));
//   return frequency;
// }
//
// double utils::velToAmp(int midiVel) {
//   double amplitude = midiVel / 127;
//   return amplitude;
// }

//============================================================================//

// template<typename T> string utils::pToString(const T& pointer) {
//   stringstream ss;
//   ss << static_cast<void*>(pointer);
//   return ss.str();
// }

int main() {
  #if DEBUG
  cout << "Starting program...\n" << endl;
  #endif

  /*
  arg1 = text,
  arg2 = color
  */
  string colorTest = color("color test", "red");
  cout << colorTest << endl;

  /*
  arg1 = inputArray,
  arg2 = starting value,
  arg3 is stop value (stop value is included)
  */
  float testArray[] = {1.0,2.0,3.0,1.0,2.0,3.0};
  float summedArray = arrSum(testArray, 0, 3);
  cout << "Array summing test: " << summedArray << endl;

  /*
  arg1 = value to constrain,
  arg2 = minimum value
  arg3 = maximum value
  */
  int bigInt = 15;
  float constrainedInt = constrain(bigInt, 0, 10);
  cout << "Constraining test: " << constrainedInt << endl;

  /*
  arg1 = relative note length expressed in amount of quarter notes
  arg2 = sampleRate
  */
  int durationInSamples = noteSampleDur(120, 0.5f, 44100.0);
  cout << "durationInSamples test: " << durationInSamples << endl;

  // arg1 = MIDI pitch
  float frequency = mtof(36);
  cout << "frequency test: " << frequency << endl;

  // arg1 = MIDI velocity
  float amplitude = velToAmp(100);
  cout << "amplitude test: " << amplitude << endl;

  // arg1 = T pointer
  // float testValue = 5.5f;
  // float* pointer = &testValue;
  // string pointerToString = pToString<float*>(pointer);
  // cout <<
  //   "Address to string,\nPointer Address: " << pointer <<
  //   "\nAddress as string: " << pointerToString <<
  //   "\nIs of type: " << typeid(pointerToString).name() << endl;



  #if DEBUG
  cout << "\nProgram finished... shutting down" << endl;
  #endif




  cout << endl;
  return 0;
}
