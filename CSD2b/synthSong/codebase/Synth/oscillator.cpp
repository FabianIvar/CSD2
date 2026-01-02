#include "oscillator.h"
// using namespace std;

Oscillator::Oscillator(float _frequency, float _samplerate)
  : frequency(_frequency), amplitude(0.10f),
    samplerate(_samplerate), phase(0.0f),
    sample(0.0f) {
  }

Oscillator::~Oscillator() {
  #if DEBUG
    std::cout <<
      "Oscillator Destroyed"
    << std::endl;
  #endif
}

void Oscillator::tick() {
  phase += frequency * (1 / samplerate);

  if (phase > 1.0f) {
    phase -= 1.0f;
  }
  else if (phase < 0.0f) {
    phase += 1.0f;
  }
  calculate();
}

float Oscillator::getSample() { return sample; }
