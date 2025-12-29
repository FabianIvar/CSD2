#pragma once
#include "oscillator.h"

class Sine : public Oscillator {
  // void calculate() override;
  void calculate() override;

public:
  Sine (float frequency, float samplerate);
  virtual ~Sine() override {}

};
