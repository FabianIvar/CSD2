#include <iostream>
#include "oscillator.h"
using namespace std;

Oscillator::Oscillator(float frequency, float samplerate) {
  cout << "Oscillator Constructor\n" << "frequency: ";
  cout << frequency << "\nsamplerate: " << samplerate << endl;
}

void Oscillator::setSamplerate(float samplerate) {
  this->samplerate = samplerate;
  cout << "samplerate = " << samplerate << endl;
}

float Oscillator::getSample() {
  return sample;
}

//getters and setters
void Oscillator::setFrequency(float frequency)
{
  // TODO input validation
  this->frequency = frequency;
}

float Oscillator::getFrequency()
{
  return frequency;
}
