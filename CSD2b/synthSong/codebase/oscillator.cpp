// Credits for code to Ciska Vriezenga

#include <iostream>
#include "oscillator.h"
#include "appController.h"
using namespace std;
using namespace appController;

Oscillator::Oscillator(float frequency, float samplerate) : phase(0.0f), amplitude(0.25f), frequency(frequency), samplerate(samplerate) {

  this->phaseStep = frequency / samplerate;
}

Oscillator::~Oscillator() {

}

void Oscillator::tick() {
  phase += phaseStep;
  // wrap the phase to interval [0, 1]
  if (phase > 1) {
    phase -= 1.0;
  }
  else if (phase < 0)
  {
    phase += 1.0;
  }
  calculate();
}

float Oscillator::getSample() {return sample; }

void Oscillator::setFrequency (float frequency) {
  // TODO
  // add check to see if parameter is valid
  this->frequency = frequency;
}

float Oscillator::getFrequency() {return frequency; }
