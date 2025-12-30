#pragma once
#include "../oscillator.h"
#include <iostream>

struct Sine : public Oscillator {
  Sine(float frequency, float samplerate);
  void calculate() override;

  ~Sine() override {
    #if DEBUG
      std::cout << "Sine destroyed" << std::endl;
    #endif
  }
};
