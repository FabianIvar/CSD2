#include "sine.h"
#include "math.h"

Sine::Sine (float _frequency, float _samplerate)
  : Oscillator(_frequency, _samplerate) {
    #if DEBUG
      std::cout << "Sine Constructor" << std::endl;
    #endif
  }

void Sine::setAmplitude(float amp) {
  this->amplitude = amp;
}

void Sine::setFrequency(float freq) {
  this->frequency = freq;
}

void Sine::calculate() {
  sample = sin(static_cast<float>(M_PI) * 2.0f * phase) * amplitude;
}
