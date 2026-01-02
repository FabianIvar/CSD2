#pragma once
#include "../oscillator.h"
#include <iostream>

struct Saw : public Oscillator {
  Saw(float _frequency, float _samplerate);
  void setAmplitude(float amp) override;
  void setFrequency(float freq) override;
  void calculate() override;

  ~Saw() override {
    #if DEBUG
      std::cout << "Saw destroyed" << std::endl;
    #endif
  }
};
