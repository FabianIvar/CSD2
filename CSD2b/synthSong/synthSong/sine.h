#pragma once
#include <iostream>
#include <cmath>
#include "oscillator.h"

class Sine : public Oscillator
{
public:
  //Constructor and destructor
  Sine(float frequency, float samplerate);
  ~Sine();

};
