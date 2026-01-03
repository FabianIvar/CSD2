#pragma once
#define DEBUG 0

#if DEBUG
#include <iostream>
#endif

// #include <vector>

struct Oscillator {

  Oscillator(float _frequency, float _samplerate);
  virtual ~Oscillator();

  void tick();
  float getSample();
  void setAmplitude(float amp);
  void setFrequency(float freq);

protected:
  virtual void calculate() = 0;
  float frequency;
  float amplitude;
  float samplerate;
  float phase;
  float sample;

};
