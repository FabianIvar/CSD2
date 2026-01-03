#include "synth.h"

// NOTE: Implement amplitude as argument
Synth::Synth(float _frequency, float _samplerate)
  : frequency(_frequency), amplitude(0.10f),
    samplerate(_samplerate),
    tempOsc(nullptr) {}

Synth::~Synth() {
  if (tempOsc != nullptr) tempOsc = nullptr;

  #if DEBUG
    std::cout <<
      "Synth Destroyed"
      "\ntempOsc: " << tempOsc
    << std::endl;
  #endif
}

// Calculates sample
void Synth::synthTick() { calculate(); }

// Returns sample calculated by the synth
float Synth::getSynthSample() { return _sample; }

void Synth::setSynthFrequency(float freq) {
  this->frequency = freq;
}

void Synth::setSynthAmplitude(float amp) {
  this->amplitude = amp;
}

// Initialized with a frequency of 0;
Oscillator** Synth::setWaveType(int wave) {
  std::cout <<
    ">>>tempOsc: " << tempOsc
  << std::endl;

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
    default:
      #if DEBUG
        std::cout <<
          "error!"
        << std::endl;
      #endif
      break;
  }

  #if DEBUG
    std::cout <<
      "Address: " << tempOsc << "\n"
    << std::endl;
  #endif

  return &tempOsc;
}
