#include <iostream>
#include "utils.h"
using namespace std;

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
  }

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
  string suffix = "\033[0m"
  string output = prefix + textInput + suffix;

  #if DEBUG
  cout << "outut: " << output << endl
  #endif

  return output;
}

// QUESTION: do you need brackets when making an array?
auto utils::arrSlice(auto inputArray[], int startPos, int stopPos) {

  #if DEBUG
  cout << "utils::arrSlice" << endl;
  #endif

  int inputArrayLength = sizeof(inputArray) / sizeof(inputArray[0]);
  int slicedArrayLength = stopPos - startPos;
  auto slicedArray[slicedArrayLength] = 0;

  for (int i = 0; i <= slicedArrayLength; i++) {
      slicedArray[i] = inputArray[(i + startPos)]
  }

  #if DEBUG
  cout <<
    "inputArray: " << to_string(inputArray) <<
    "\narrayLength: " << arrayLength <<
    "\nstartPos: " << startPos <<
    "\nstopPos: " << stopPos <<
    "\nslicedArrayLength: " << slicedArrayLength <<
    "slicedArray: " << to_string(slicedArray) << endl;
  #endif

  return slicedArray;
}

float utils::arrSum(float inputArray[]) {
  int inputArrayLength = sizeof(inputArray) / sizeof(inputArray[0]);


  /* NOTE: accumulate() might only be able to return ints,
  if a bug arises this might be the issue.
  Also inputArrayLength is an int and inputArray is a float.
  I don't know if this is allowed. */
  
  float summedArray = accumulate(inputArray, )
}

/* TODO:
- mtof
- velToAmp
- arrSum
- noteTimeDur (time in ms) -> different from qNoteLength
*/

/* DONE:
- color
- arrSlice

*/
