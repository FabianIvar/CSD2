#pragma once

#include "audiocomponent.h"
// TODO: include all this stuff
// #include "synth"
// #include "additive.h"
// #include "fm.h"
#include "oscillator.h"
// #include "saw.h"
// #include "sine.h"
// #include "square.h"

class CustomCallback : public AudioCallback {
public:

  explicit CustomCallback (double sampleRate) : AudioCallback(Fs);

  ~CustomCallback() override;

  void prepare(int sampleRate) override;

  void process(AudioBuffer buffer) override;

  double getSampleRate();

  // updatePitch();
  // updateAmplitude();

private:
  // int frameCount = 0;
  double _sampleRate;
  Oscillator* myOsc = nullptr;

  // Melody melody;
  // double noteDelayFactor = 0.1;



};
