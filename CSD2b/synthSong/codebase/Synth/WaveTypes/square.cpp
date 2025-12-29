#include "square.h"

Square::Square (float frequency, float samplerate)
  : Oscillator (frequency, samplerate) {}

void Square::calculate() {
  sample = (phase < 0.5f) ? 1.0f * amplitude : -1.0f * amplitude;}
