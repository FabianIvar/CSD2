#pragma once
#include "synth.h"

// : public Synth

struct Oscillator {

  Oscillator(float frequency, float samplerate);

/* NOTE:
A virtual destructor makes it so that when
delete is called on 'oscillator* square'
the destructor of the WaveType object is called
instead of the destructor of the oscillator */
  virtual ~Oscillator() {}

  // void setFrequency(float frequency);
  // float getFrequency();
  // void setSamplerate();
  float getSample();
  void tick();
  // void calcPhaseStep(float frequency);
  // float getPhase();

protected:
  virtual void calculate() = 0;
  float phase;
  float amplitude;
  float phaseStep;
  float sample;
// private:
  // float frequency;
  // float samplerate;

};
