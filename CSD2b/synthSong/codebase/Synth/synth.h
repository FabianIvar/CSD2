#pragma once

#include "oscillator.h"
#include "WaveTypes/sine.h"
#include "WaveTypes/square.h"
#include "WaveTypes/saw.h"

struct Synth {
  Synth(float _frequency, float _samplerate);

  /* A virtual destructor makes it so that when
  delete is called on (e.g.) 'oscillator* square'
  the destructor of the WaveType object is called */
  virtual ~Synth();

  // Used in additive synth to set amp of partials
  virtual void setOscAmplitude(
    int oscNum, float amp) {oscNum = 0; amp = 0;}
  void synthTick();
  float getSynthSample();
  void setSynthFrequency(float freq);
  void setSynthAmplitude(float amp);
  Oscillator** setWaveType(int wave);

protected:
  virtual void calculate() = 0;
  float frequency;
  float amplitude;
  float samplerate;
  float _sample;
  Oscillator* tempOsc;
};
