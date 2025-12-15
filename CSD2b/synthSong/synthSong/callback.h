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
  CustomCallback (double samplerate);
  void prepare (int rate) override;
  void process (AudioBuffer buffer) override;

private:
  Square oscillator;
};

#endif  //CALLBACK_H
