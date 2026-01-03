#pragma once
#include <vector>
#include <algorithm>
#include <functional>

// #if DEBUG
// #include <iostream>
// #endif

#include "../utils.h"
#include "synth.h"

struct Additive : public Synth {
  Additive(float _frequency, float _samplerate,
    int _waveType, int _voicesAmt);

  ~Additive() override;
  void calculate() override;

private:
  std::vector<Oscillator*> voices;

  int voicesAmt;
  int waveType;

  std::vector<float> partialAmp;

};
