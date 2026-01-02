#include "synth.h"

// NOTE: Implement amplitude as argument
Synth::Synth(float _frequency, float _samplerate)
  : frequency(_frequency), amplitude(0.10f),
    samplerate(_samplerate),
    tempOsc(nullptr) {}

Synth::~Synth() {
  #if DEBUG
    std::cout <<
      "Synth Destroyed"
    << std::endl;
  #endif
}

// Calculates sample
void Synth::tick() { calculate(); }

// Returns sample calculated by the synth
float Synth::getSynthSample() { return _sample; }

void Synth::setSynthFrequency(float freq) {
  this->frequency = freq;
}

void Synth::setSynthAmplitude(float amp) {
  this->amplitude = amp;
}

// Initialized with a frequency of 0;
void Synth::setWaveType(int wave) {
  switch (wave) {
    case 0:
      tempOsc = new Sine(220.0f, samplerate);
      break;
    case 1:
      tempOsc = new Square(220.0f, samplerate);
      break;
    case 2:
      tempOsc = new Saw(220.0f, samplerate);
      break;
    case 'd':
      delete tempOsc;
      tempOsc = nullptr;
      break;
  }
}
