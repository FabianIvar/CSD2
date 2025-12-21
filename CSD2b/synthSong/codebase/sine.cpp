#include "sine.h"
#include "math.h"

Sine::Sine (double frequency, double samplerate)
  : Oscillator (frequency, samplerate) {

  #if DEBUG
  std::cout << "Sine::Sine constructor\n";
  #endif
}

void Sine::calculate() {
  sample = sin(M_PI * 2 * phase) * amplitude;
}
