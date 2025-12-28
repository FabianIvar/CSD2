#include <iostream>
#include <cmath>
using namespace std;
#include "utils.h"
using namespace Utils;

#define DEBUG_MAIN 1



int main() {
  cout << endl;
  #if DEBUG_MAIN
  cout <<
    "Starting program...\n"
  << endl;
  #endif

//============================================================================//

  int midiPitch = 36;
  Mtof m(midiPitch);

  int frequency = static_cast<int>(m);

  cout <<
    "midiPitch: " << midiPitch <<
    "\nFrequency: " << frequency
  << endl;

  cout << "test1:" << endl;
  // template Utils::mtof<float*>::mtof(float*);
  // float midiPitch = 36.5f;
  // float* midiPtichPtr = midiPitch;
  //
  // // Utils::mtof mtof(midiPtich);
  // float* frequency = midiPtich.operator float*();

// NOTE: typedef here?


// float* frequency = static_cast<float*>(midiPitch1);


// double frequency2 = midiPitch1.operator double*();
// mtof

//============================================================================//
  #if DEBUG_MAIN
  cout <<
    "\nProgram finished... shutting down"
  << endl;
  #endif

  cout << endl;
  return 0;
}
