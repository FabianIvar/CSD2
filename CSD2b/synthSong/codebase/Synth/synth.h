#pragma once
// #include "subtractive.h"

struct Synth {
  Synth(float frequency, float samplerate);
  virtual ~Synth() {}
  float getSample();
  void tick();

protected:
  virtual void calculate() = 0;

}
