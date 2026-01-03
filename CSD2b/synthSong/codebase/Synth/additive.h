#pragma once
#include <vector>
#include <algorithm>
#include <functional>

#include "../utils.h"
#include "synth.h"

struct Additive : public Synth {
  Additive(float _frequency, float _samplerate,
    int _waveType, int _voicesAmt);

  ~Additive() override;
  void setOscAmplitude(int oscNum,
    float amp) override;
  void calculate() override;

  std::vector<float> partialAmp;
private:
  std::vector<Oscillator*> voices;
  int voicesAmt;
  int waveType;
};
