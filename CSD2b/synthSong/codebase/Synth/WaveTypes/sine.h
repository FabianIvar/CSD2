#pragma once
#include "../oscillator.h"

struct Sine : public Oscillator {
  Sine(float frequency, float samplerate);
  void calculate() override;

  ~Sine() override {
    std::cout << "Sine destroyed" << std::endl;
  }
};
