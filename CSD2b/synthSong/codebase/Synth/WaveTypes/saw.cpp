#include "saw.h"

Saw::Saw (float _frequency, float _samplerate)
  : Oscillator(_frequency, _samplerate) {
    #if DEBUG
      std::cout << "Saw Constructor" << std::endl;
    #endif
  }

void Saw::setAmplitude(float amp) {
  this->amplitude = amp;
}

void Saw::setFrequency(float freq) {
  this->frequency = freq;
}

void Saw::calculate() {
  sample = (phase * 2.0f - 1.0f) * amplitude;
}
