#pragma once
#include "synth.h"
#include "oscillator.h"
#include "WaveTypes/sine.h"
#include "WaveTypes/square.h"
#include "WaveTypes/saw.h"

struct Additive : public Synth {
  Additive(float frequency, float samplerate);
  void calculate() override;

  ~Additive() override {
    std::cout << "Additive Type Destroyed" << std::endl;
  }

private:
  Oscillator* wave[2];

  
};
