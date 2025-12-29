#pragma once
#include <iostream>
#include "synth.h"

// : public Synth

class Oscillator {
public:
  Oscillator(float frequency, float samplerate);
  virtual ~Oscillator();

  void setFrequency(float frequency);
  float getFrequency();
  float getSample();
  void tick();
  // void setPhase(float phase);
  // float getPhase();
  // void setSampleRate(float sampleRate);

protected:
  virtual void calculate() = 0;
  float phase;
  float amplitude;
  float phaseStep;
  float sample;
private:
  float frequency;
  float samplerate;




};
