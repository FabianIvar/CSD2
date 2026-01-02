#pragma once
#include "../oscillator.h"
#include <iostream>

struct Square : public Oscillator {
  Square(float _frequency, float _samplerate);
  void setAmplitude(float amp) override;
  void setFrequency(float freq) override;
  void calculate() override;

  ~Square() override {
    #if DEBUG
      std::cout << "Square destroyed" << std::endl;
    #endif
  }
};
