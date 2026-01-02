#pragma once
#include "../oscillator.h"

struct Square : public Oscillator {
  Square(float _frequency, float _samplerate);
  void calculate() override;

  /* NOTE:
  A virtual destructor makes it so that when
  delete is called on 'oscillator* square'
  the destructor of the Square object is called
  instead of the destructor of the oscillator */
  ~Square() override {
    #if DEBUG
      std::cout << "Square destroyed" << std::endl;
    #endif
  }
};
