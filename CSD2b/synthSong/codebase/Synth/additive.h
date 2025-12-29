#pragma once
#include <vector>
#include <memory>
#include "synth.h"
#include "oscillator.h"
#include "WaveTypes/sine.h"
#include "WaveTypes/square.h"
#include "WaveTypes/saw.h"

struct Additive : public Synth {
  Additive(float frequency, float samplerate);
  void calculate() override;

  ~Additive() override;

private:
  typedef std::vector<shared_ptr<Oscillator*>> oscVector;
  oscVector voices;
  float devisor;



};
