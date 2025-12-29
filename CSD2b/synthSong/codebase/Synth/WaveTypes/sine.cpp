#include "sine.h"
#include "math.h"

Sine::Sine (float frequency, float samplerate)
  : Oscillator(frequency, samplerate) {}

void Sine::calculate() {
  sample = sin(static_cast<float>(M_PI) * 2.0f * phase) * amplitude;
}
