#include "synth.h"

// NOTE: Implement amplitude as argument
Synth::Synth(float freq, float rate)
  : frequency(freq), samplerate(rate) {}

// calculates sample
void Synth::tick() {
  calculate();}

float Synth::getSynthSample() {
  return _sample;
}
