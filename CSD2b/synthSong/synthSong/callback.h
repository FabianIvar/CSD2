#pragma once
#include "audiocomponent.h"
#include "oscillator.h"
#include "sine.h"
// #include "square.h"
// #include "saw.h"

class CustomCallback : public AudioCallback {
public:
  CustomCallback (float samplerate);
  void prepare (int rate) override;
  void process (AudioBuffer buffer) override;

private:
  // TODO: polymorphism -> let user pick oscillator type
  Sine oscillator;
};
