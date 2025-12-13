#include "sine.h"
#include "math.h"
using namespace std;

Sine::Sine(float frequency, float samplerate)
  : Oscillator(frequency, samplerate) {
  cout << "Sine - constructor\n"
}

Sine::~Sine() {
  cout << "Sine - destructor\n";
}

void Sine::calculate() {
  phase += frequency / samplerate;
  if(phase > 1.0f) {
    phase -= 1.0f;
  }
  sample = sin(M_PI * 2 * phase) * amplitude;
}
