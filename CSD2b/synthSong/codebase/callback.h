#pragma once

#include "audiocomponent.h"
#include "Synth/synth.h"
// #include "Synth/WaveTypes/sine.h"
// #include "Synth/WaveTypes/square.h"
// #include "Synth/WaveTypes/saw.h"
// #include "Synth/oscillator.h"

struct CustomCallback : public AudioCallback {
  CustomCallback (float samplerate);
  ~CustomCallback() override;
  void prepare (int sampleRate) override;
  void process (AudioBuffer buffer) override;
private:
  // Oscillator* waveType;
  Synth* synthType[2];
};
