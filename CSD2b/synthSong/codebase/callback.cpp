#include "callback.h"
#include "utils.h"
#include <iostream>
using namespace std;
// TODO: make samplerate template <typename T>
/*

template <typename T> constexpr T sampleRate = T()

*/


CustomCallback::CustomCallback(double sampleRate)
  : AudioCallback(double Fs) {

    #if DEBUG
    cout << "CustomCallback Constructor" << endl;
    cout << "Samplerate in constructor: " << sampleRate << endl;
    coud << "Samplerate is of type: ";
    cout << typeid(sampleRate).name() << endl;
    #endif

}

CustomCallback::~Customcallback() {
  #if DEBUG
  cout << "CustomCallback Destructor " << endl;
  #endif

  delete myOsc;
}

void CustomCallback::prepare(int sampleRate) {
  _sampleRate = sampleRate;

  // should be replaced by synth
  myOsc = new Sine(double frequency, double sampleRate);

  int numChannels = sizeof(synth) / sizeof(synth[0]);
  for (int i = 0; i < numChannels; i++) {
    synth[i].prepare(sampleRate)
  }
  // oscillator.setSamplerate (sampleRate);
  #if DEBUG
  cout << "Samplerate in prepare function: ";
  cout << sampleRate << endl;
  cout << "Samplerate is of type: ";
  cout << typeid(sampleRate).name() << endl;
  #endif


}

double CustomCallback::getSampleRate() {
  return _sampleRate
}

void CustomCallback::process (AudioBuffer buffer) {
  // NOTE: Destructurizing
  auto [inputChannels,
        outputChannels,
        numInputChannels,
        numOutputChannels,
        numFrames] = buffer;

  for (int channel = 0u; channel < numOutputChannels; ++channel) {
    for (int frame = 0u; frame < numFrames; ++frame) {
      myFirstOsc.calculate();
      outputChannels[channel][frame] = 0.0f;
      // outputChannels[channel][frame] = oscillator.getSample();
      // oscillator.tick();
    }
  }
}
