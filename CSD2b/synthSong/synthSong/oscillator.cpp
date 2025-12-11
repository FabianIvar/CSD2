#include <iostream>
#include "oscillator.h"

void Sine::setSamplerate(float samplerate) {
  this->samplerate = samplerate;
  cout << "samplerate = " << samplerate << endl;
}

float Sine::getSample() {
  return sample;
}

void Sine::tick() {
  // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += frequency / samplerate;
  if(phase > 1.0f) {
    phase -= 1.0f;
  }
  sample = sin(M_PI * 2 * phase) * amplitude;
}

//getters and setters
void Sine::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

float Sine::getFrequency()
{
  return frequency;
}
