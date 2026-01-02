#include "square.h"

Square::Square(float _frequency, float _samplerate)
  : Oscillator(_frequency, _samplerate) {
    #if DEBUG
      std::cout << "Square Constructor" << std::endl;
    #endif
  }

void Square::setAmplitude(float amp) {
  this->amplitude = amp;
}

void Square::setFrequency(float freq) {
  this->frequency = freq;
}

void Square::calculate() {
  sample = (phase < 0.5f) ? 1.0f * amplitude : -1.0f * amplitude;}
