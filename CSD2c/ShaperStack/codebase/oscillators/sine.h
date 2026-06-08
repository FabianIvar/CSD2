#pragma once
#include <iostream>
#include "oscillator.h"

class Sine : public Oscillator
{
public:
  //Constructor and destructor
  Sine();
  Sine(float frequency, float samplerate = 48000);
  ~Sine();

private:
  // calculate the next sample according to sine calculation
  void calcNextSample() override;
};
