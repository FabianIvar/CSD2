#include "sine.h"
#include "math.h"

Sine::Sine (float frequency, float samplerate)
  : Oscillator(frequency, samplerate) {
    #if DEBUG
      std::cout << "Sine Constructor" << std::endl;
    #endif
  }

void Sine::calculate() {
  sample = sin(static_cast<float>(M_PI) * 2.0f * phase) * amplitude;
}
