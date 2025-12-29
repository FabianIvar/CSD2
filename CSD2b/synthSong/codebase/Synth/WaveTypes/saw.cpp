#include "saw.h"

Saw::Saw (float frequency, float samplerate)
  : Oscillator(frequency, samplerate) {}

void Saw::calculate() {
  sample = (phase * 2.0f - 1.0f) * amplitude;
}
