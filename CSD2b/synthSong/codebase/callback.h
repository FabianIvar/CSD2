#pragma once

#include "audiocomponent.h"
#include "sine.h"
#include "oscillator.h"
// #include "square.h"

class CustomCallback : public AudioCallback {
public:
  CustomCallback (float samplerate);
  ~CustomCallback() override;
  void prepare (int sampleRate) override;
  void process (AudioBuffer buffer) override;

private:
  Oscillator* sine[2];
  // Square oscillatorFifth;
  // Square oscillatorFifthDetuned;
};
