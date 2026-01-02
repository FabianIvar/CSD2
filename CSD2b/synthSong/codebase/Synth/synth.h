#pragma once

#include "oscillator.h"
#include "WaveTypes/sine.h"
#include "WaveTypes/square.h"
#include "WaveTypes/saw.h"

// #if DEBUG
  #include <iostream>
// #endif

/* TODO:

- Maybe remove duplicate code between additive
  and fm -> wavetype picker function in synth.
  ^^ Requires a lot of changes. might be
  out of scope

*/

struct Synth {
  Synth(
    float _frequency, float _samplerate);
  virtual ~Synth();
  void tick();
  float getSynthSample();
  void setSynthFrequency(float freq);
  void setSynthAmplitude(float amp);
  void setWaveType(int wave);

protected:
  virtual void calculate() = 0;
  float frequency;
  float amplitude;
  float samplerate;
  float _sample;
  Oscillator* tempOsc;
};
