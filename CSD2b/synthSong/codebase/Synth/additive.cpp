#include "additive.h"

// NOTE: would be cool to be able to
// change the wavetype after initialization
// maybe with a 'setwavetype' function.
Additive::Additive(
  float frequency,
  float samplerate,
  int waveType,
  int voicesAmt)
  : Synth(frequency, samplerate),
  waveType(waveType),
  voicesAmt(voicesAmt), {}

void Additive::calculate() {
  if (waveType == 0){ // Sine
    for (int i = 0; i < voicesAmt; i++) {

    }
  }
  else if (waveType == 1) { // Square

  }
  else if (waveType == 2) { // Saw

  }

}
