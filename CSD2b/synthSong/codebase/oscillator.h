#pragma once
#include <iostream>
#include "synth.h"

class Oscillator : public Synth {
public:
  Oscillator(float frequency, float sampleRate);
  ~Oscillator();

  void setFrequency(float frequency);
  float getFrequency();
  void setPhase(float phase);
  float getPhase();
  void setSampleRate(float sampleRate);
  void tick();

protected:

  // pure virtual function, making the Oscillator class abstract.
  virtual void calculate() = 0;
  float frequency;
  float amplitude;
  float phase;
  // float phaseStep;
  float sample;
  float sampleRate;




}
