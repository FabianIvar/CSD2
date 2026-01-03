#pragma once
#include "../oscillator.h"

struct Saw : public Oscillator {
  Saw(float _frequency, float _samplerate);
  void calculate() override;

  ~Saw() override {
    #if DEBUG
      std::cout << "Saw destroyed" << std::endl;
    #endif
  }
};
