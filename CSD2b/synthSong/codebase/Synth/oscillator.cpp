#include "oscillator.h"
// using namespace std;

Oscillator::Oscillator(float frequency, float samplerate)
  : phase(0.0f), amplitude(0.10f) {
    phaseStep = frequency / samplerate;
  }

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

float Oscillator::getSample() {return sample;}
