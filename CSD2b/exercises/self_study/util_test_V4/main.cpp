#include <iostream>
#include "utils.h"
using namespace std;












//=============================================================================//


int main() {
  cout << endl;
  cout << "Starting program...\n" << endl;
  using namespace Utils;
  //======================================================//









  cout << "test1:" << endl;

  float calculateAmp = 100;
  float calculateFreq = 36.0;


  vtoa midiVel1(calculateAmp);
  // float amplitude = static_cast<decltype(calculateAmp)>(calculateAmplitude);

  // mtof midiPitch1(calculateFreq);

  // NOTE: typedef here?


  // decltype(calculateFreq) frequency = static_cast<decltype(frequency)>(midiPitch1);


  // double frequency2 = midiPitch1.operator double*();
  // mtof

  string example_string = "abc";
  const char* test = example_string.c_str();

  cout <<
    "\nTest2\nValue in test: " << test <<
    "\nOf type: " << typeid(test).name()
  << endl;










//=============================================================================//


  #if DEBUG
  cout << "\nProgram finished... shutting down" << endl;
  #endif

  cout << endl;
  return 0;
}
