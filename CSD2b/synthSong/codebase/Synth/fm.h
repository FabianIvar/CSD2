#pragma once
#include <memory>

// #if DEBUG
  #include <iostream>
// #endif

#include "synth.h"
// #include "oscillator.h"
// #include "WaveTypes/sine.h"
// #include "WaveTypes/square.h"
// #include "WaveTypes/saw.h"

/* TODO:

- add fm to CMakeLists.txt
- enum for waveType
-

*/
struct Fm : public Synth {
// NOTE: Add amplitude
  Fm(float _carrierFrequency, float _samplerate,
    int _carrierWaveType, int _modulatorWaveType,
    float _ratio, float _modulationIndex);

  ~Fm() override;
  void calculate() override;
  // void setWaveType(int waveType);

private:
  Oscillator* carrier;
  Oscillator* modulator;
  int carrierWaveType;
  int modulatorWaveType;
  float ratio;
  float modulationIndex;

  // typedef vector<tuple<Oscillator*, int>> osc;
  // vector<tuple<Oscillator*, int>> oscillators;

};
