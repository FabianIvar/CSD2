#pragma once
#include "oscillator.h"

class Sine : public Oscillator {
public:
  Sine (float frequency = 0, float samplerate = 44100.0f);

protected:
  void calculate() overrides;
};
