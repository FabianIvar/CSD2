#include "synth.h"

// NOTE: Implement amplitude as argument
Synth::Synth(float freq, float rate)
  : frequency(freq), samplerate(rate),
    tempOsc(nullptr) {}

Synth::~Synth() {
  #if DEBUG
    std::cout <<
      "Synth Destroyed"
    << std::endl;
  #endif
}

// Initialized with a frequency of 0;
static void setWaveType(int wave) {
  switch (wave) {
    case 0:
      tempOsc = new Sine(0.0f, samplerate));
      break;
    case 1:
      tempOsc = new Square(0.0f, samplerate));
      break;
    case 2:
      tempOsc = new Saw(0.0f, samplerate));
      break;
    case 'd':
      delete tempOsc;
      tempOsc = nullptr;
      break;
  }
}

// Calculates sample
void Synth::tick() {calculate();}

// Returns sample calculated by the synth
float Synth::getSynthSample() { return _sample; }
