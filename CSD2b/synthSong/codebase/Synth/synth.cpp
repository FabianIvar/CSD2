#include "synth.h"

// NOTE: Implement amplitude as argument
Synth::Synth(float freq, float rate)
  : frequency(freq), samplerate(rate) {}

Synth::~Synth() {
  #if DEBUG
    std::cout <<
      "Synth Destroyed"
    << std::endl;
  #endif
}

Oscillator* setWaveType(float freq, int wave) {
  Oscillator* tempOsc;
  switch (waveType) {
    case 0:
      tempOsc = new Sine(0.0f, samplerate);
      return tempOsc;
      break;
    case 1:
      tempOsc = new Square(0.0f, samplerate);
      return tempOsc;
      break;
    case 2:
      tempOsc = new Saw(0.0f, samplerate);
      return tempOsc;
      break;
  }
}

// Calculates sample
void Synth::tick() {calculate();}

// Returns sample calculated by the synth
float Synth::getSynthSample() {return _sample;}
