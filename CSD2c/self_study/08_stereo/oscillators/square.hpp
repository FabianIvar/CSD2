#pragma once

#include <iostream>
#include "oscillator.hpp"

class Square : public Oscillator {
public:
  //Constructor and destructor
  Square();
  Square(float frequency, float samplerate = 48000);
  ~Square() override;

private:
  // calculate the next sample according to square calculation
  void calcNextSample() override;
};
