#pragma once
#include <iostream>

class Oscillator {
public:
  Oscillator (float frequency = 0, float samplerate = 48000);
  ~Oscillator();

  // allow to set samplerate after initialization
  void setSamplerate (float samplerate);
  //return the current sample
  float getSample();
  // go to next sample
  virtual void calculate() = 0;

  //getters and setters
  void setFrequency (float frequency);
  float getFrequency();

private:
  float frequency;
  float amplitude;
  float phase;
  // sample contains the current sample
  float sample;
  float samplerate;
};

#endif
