#pragma once
#include "synth.h"

struct Fm : public Synth {

  Fm(float _frequency, float _samplerate,
    int carrierWaveType, int modulatorWaveType,
    float ratio, float modulationIndex);

  ~Fm() override;
  void calculate() override;

protected:
  Oscillator* carrier;
  Oscillator* modulator;
  int carWaveType;
  int modWaveType;
  float inverseRatio;
  float modIndex;
};
