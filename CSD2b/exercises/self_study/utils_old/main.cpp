#include <iostream>
#include "utils.h" // denk ik?
using namespace std;
using namespace utils;

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
  int durationInSamples = noteSampleDur(0.5f, 44100);
  cout << "durationInSamples test: " << durationInSamples << endl;

  // arg1 = MIDI pitch
  float frequency = mtof(36);
  cout << "frequency test: " << frequency << endl;

  // arg1 = MIDI velocity
  float amplitude = velToAmp(100);
  cout << "amplitude test: " << amplitude << endl;

  cout << "\nProgram finished... shutting down" << endl;

  return 0;
}
