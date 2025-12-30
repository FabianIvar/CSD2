#pragma once
#include <iostream>
#define DEBUG 0

struct Oscillator {

  Oscillator(float frequency, float samplerate);

/* NOTE:
A virtual destructor makes it so that when
delete is called on 'oscillator* square'
the destructor of the WaveType object is called
instead of the destructor of the oscillator */
  virtual ~Oscillator() {}

  float getSample();
  void tick();

protected:
  virtual void calculate() = 0;
  float phase;
  float amplitude;
  float phaseStep;
  float sample;

};
