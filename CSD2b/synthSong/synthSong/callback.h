#pragma once

#include "audiocomponent.h"
// TODO: include all this stuff
// #include "synth"
// #include "additive.h"
// #include "fm.h"
// #include "oscillator.h"
// #include "saw.h"
// #include "sine.h"
// #include "square.h"

class CustomCallback : public AudioCallback {
public:

  explicit CustomCallback (double samplerate);
  void prepare (int rate) override;
  void process (AudioBuffer buffer) override;

  // updatePitch();
  // updateAmplitude();

private:
  // int frameCount = 0;
  // double sampleRate;
  // double noteDelayFactor = 0.1;
  Sine sine;

  // Oscillator* oscillator = nullptr;

};
