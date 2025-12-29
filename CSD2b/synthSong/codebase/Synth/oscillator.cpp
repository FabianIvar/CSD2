// Credits for code to Ciska Vriezenga

#include <iostream>
#include "oscillator.h"
using namespace std;

Oscillator::Oscillator(float frequency, float samplerate) :
  phase(0.0f),
  amplitude(0.10f) {
    phaseStep = frequency / samplerate;
  }

// void calcPhaseStep(float frequency) {
//   this->_frequency = frequency;
//   this->phaseStep = _frequency / _samplerate;
// }

void Oscillator::tick() {
  phase += phaseStep;

  if (phase > 1.0f) {
    phase -= 1.0f;
  }
  else if (phase < 0.0f)
  {
    phase += 1.0f;
  }
  calculate();
}

float Oscillator::getSample() {return sample; }

// void Oscillator::setFrequency (float frequency) {
//   // TODO
//   // add check to see if parameter is valid
//   this->_frequency = frequency;
// }

// float Oscillator::getFrequency() {return _frequency;}
// float Oscillator::setSamplerate(float samplerate) {
//   this->samplerate = samplerate;
// }
