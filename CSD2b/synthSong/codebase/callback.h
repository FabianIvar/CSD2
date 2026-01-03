#pragma once

#include "audiocomponent.h"
#include "Synth/synth.h"
#include "Synth/additive.h"
#include "Synth/fm.h"
#include "melody/melody.h"

struct CustomCallback : public AudioCallback {
  CustomCallback (float samplerate);
  ~CustomCallback() override;
  void prepare (int samplerate) override;
  void process (AudioBuffer buffer) override;
private:
  // Oscillator* waveType;
  Synth* synth[2];
  Melody melody;
};
