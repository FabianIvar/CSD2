#include <iostream>
#include <cmath>
// #include <vector>
#include "utils.h"

using namespace std;
using namespace Utils;

#define STARTUP_MESSAGE 1



int main() {
  cout << endl;
  #if STARTUP_MESSAGE
  cout <<
    "Starting program...\n"
  << endl;
  #endif

  double sampleRate = 44100.0;

//============================================================================//


  float midiPitch = 36.0;
  mtof m(midiPitch);
  float frequency = m.output;

  double midiVel = 100;
  vtoa v(midiVel);
  double amplitude = v.output;

  int notConstrained = 14;
  constrain c(notConstrained, 0, 10);
  int constrained = c.output;

  // NOTE: add a bpm option maybe?
  double noteLength = 2; // two quarter notes, so a half note
  double samples = lenToSamples(noteLength, sampleRate);

  vector<float> noteLengths = {2, 1, 0.5, 0.25, 4, 1};
  vectorSum sum(noteLengths, 0, noteLengths.size());
  float summedVector = sum.output;

  // output messages
  cout <<
    color("Midi Pitch to Frequency", "brightRed") <<
    "\nPitch: " << midiPitch <<
    "\nFrequency: " << frequency <<
    typeid(frequency).name() <<

    color("\n\nMidi Velocity to Amplitude\n", "brightYellow") <<
    "midiVel: " << midiVel <<
    "\nAmplitude: " << amplitude <<
    typeid(amplitude).name() <<

    color("\n\nConstrain\n", "brightGreen") <<
    "Unconstrained value: " << notConstrained <<
    "\nConstrained: " << constrained <<
    typeid(constrained).name() <<

    color("\n\nNote Length to amount of samples", "brightCyan") <<
    "\nNote length: " << noteLength <<
    "\nAmount of samples: " << samples <<
    typeid(samples).name() <<

    color("\n\nVector Sum", "brightBlue") <<
    "\nSummed Vector: " << summedVector <<
    typeid(summedVector).name()
  << endl;


//============================================================================//
  #if STARTUP_MESSAGE
  cout <<
    "\nProgram finished... shutting down"
  << endl;
  #endif

  cout << endl;
  return 0;
}
