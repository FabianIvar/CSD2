#pragma once
#include "../oscillator.h"

struct Saw : public Oscillator {
  Saw(float frequency, float samplerate);

  void calculate() override;

  ~Saw() override {
    std::cout << "Saw destroyed" << std::endl;
  }
};
