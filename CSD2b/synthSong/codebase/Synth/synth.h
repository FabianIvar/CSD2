#pragma once

struct Synth {
  Synth(float frequency, float samplerate);
  virtual ~Synth() {}
  void tick();
  float getSynthSample();

protected:
  virtual void calculate() = 0;
  float frequency;
  // float amplitude;
  float samplerate;
  float _sample;
};
