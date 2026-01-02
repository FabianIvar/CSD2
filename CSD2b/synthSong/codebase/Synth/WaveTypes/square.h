#pragma once
#include "../oscillator.h"
#include <iostream>

struct Square : public Oscillator {
  Square(float _frequency, float _samplerate);
  void calculate() override;

  ~Square() override {
    #if DEBUG
      std::cout << "Square destroyed" << std::endl;
    #endif
  }
};
