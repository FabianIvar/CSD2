//
// Created by Ciska Vriezenga on 06/12/2022.
//

#include "sine.h"
#include "math.h"

Sine::Sine (float frequency, float samplerate)
  : Oscillator (frequency, samplerate) {

  #if DEBUG
  std::cout << "Sine::Sine constructor\n";
  #endif
}

void Sine::calculate() {
  sample = sin(M_PI * 2 * phase) * amplitude;
}
