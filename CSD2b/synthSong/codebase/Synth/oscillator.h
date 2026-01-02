#pragma once
#define DEBUG 1

// #if DEBUG
  #include <iostream>
// #endif

// TODO: add setFrequency function

struct Oscillator {

  Oscillator(float _frequency, float _samplerate);

/* NOTE:
A virtual destructor makes it so that when
delete is called on (e.g.) 'oscillator* square'
the destructor of the WaveType object is called
instead of the destructor of the oscillator */
  virtual ~Oscillator();

  void tick();
  void setAmplitude(float amp);
  void setFrequency(float freq);
  float getSample();

protected:
  virtual void calculate() = 0;
  float frequency;
  float amplitude;
  float samplerate;
  float phase;
  float sample;

};
