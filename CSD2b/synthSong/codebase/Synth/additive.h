#pragma once
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

#include "../utils.h"
#include "synth.h"
// #include "oscillator.h"
// #include "WaveTypes/sine.h"
// #include "WaveTypes/square.h"
// #include "WaveTypes/saw.h"

struct Additive : public Synth {
  Additive(float _frequency, float _samplerate,
    int _waveType, int _voicesAmt);

  ~Additive() override;
  void calculate() override;

private:
  std::vector<Oscillator*> voices;

  int voicesAmt;
  int waveType;

};
