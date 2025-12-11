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
