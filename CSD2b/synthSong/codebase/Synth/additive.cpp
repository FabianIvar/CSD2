#include "additive.h"

// NOTE: would be cool to be able to
// change the wavetype after initialization
// maybe with a 'setwavetype' function.
Additive::Additive(
  float frequency,
  float samplerate,
  int waveType,
  float voicesAmt)
  : Synth(frequency, samplerate),
  waveType(waveType),
  voicesAmt(voicesAmt), {
    devisor = 1.0f / voicesAmt;
  }

Additive::~Additive() {
  std::cout << "Additive Type Destroyed" << std::endl;

}

// NOTE: there should be at least one voice.
void Additive::calculate() {

  if (waveType == 0){ // Sine
    for (int i = 0; i < voicesAmt; i++) {
        voices.push_back(new Sine(220.0f, samplerate));
    }
  }
  else if (waveType == 1) { // Square
    for (int i = 0; i < voicesAmt; i++) {

    }
  }
  else if (waveType == 2) { // Saw
    for (int i = 0; i < voicesAmt; i++) {

    }
  }

}
