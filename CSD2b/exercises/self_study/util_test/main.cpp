#include <iostream>
#include "utils.h" // denk ik?
using namespace std;
using namespace utils;

#define DEBUG 1

int main() {
  #if DEBUG
  cout << "Starting program...\n" << endl;
  #endif

  float testArray[] = {1,2,3,1,2,3};
  float summedArray = arrSum(testArray);
  cout << "Array summing test: " << summedArray << endl;

  int bigInt = 15;
  float constrainedInt = constrain(bigInt, 0, 10);
  cout << "Constraining test: " << constrainedInt << endl;

  double durationInSamples = noteSampleDur(120, 2, 44100);
  cout << "durationInSamples test: " << durationInSamples << endl;

  double frequency = mtof(36);
  cout << "frequency test: " << frequency << endl;

  double amplitude = velToAmp(100);
  cout << "amplitude test: " << amplitude << endl;

  cout << "\nProgram finished... shutting down" << endl;

  return 0;
}
