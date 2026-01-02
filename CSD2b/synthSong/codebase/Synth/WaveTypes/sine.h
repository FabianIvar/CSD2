#pragma once
#include "../oscillator.h"

#if DEBUG
  #include <iostream>
#endif

struct Sine : public Oscillator {
  Sine(float frequency, float samplerate);
  void calculate() override;

  ~Sine() override {
    #if DEBUG
      std::cout << "Sine destroyed" << std::endl;
    #endif
  }
};
