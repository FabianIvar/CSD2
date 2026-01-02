#include "sine.h"
#include "math.h"

Sine::Sine (float _frequency, float _samplerate)
  : Oscillator(_frequency, _samplerate) {
    #if DEBUG
      std::cout << "Sine Constructor" << std::endl;
    #endif
  }

void Sine::calculate() {
  sample = sin(static_cast<float>(M_PI) * 2.0f * phase) * amplitude;
}
