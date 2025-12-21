#include <iostream>
#include "oscillator.h"
#include "appController.h"
using namespace std;
using namespace appController;

Oscillator::Oscillator(float frequency, float sampleRate) : frequency(frequency), sampleRate(sampleRate), amplitude(0.25f), phase(0) {

  #if DEBUG
  cout << "Oscillator Constructor" << endl;
  #endif

  phaseStep = frequency / sampleRate;
}

Oscillator::~Oscillator() {
  #if DEBUG
  cout << "Oscillator Destructor" << endl;
  #endif
}


Oscillator::getSampleRate(float sampleRate) {
  this->sampleRate = sampleRate;
}
