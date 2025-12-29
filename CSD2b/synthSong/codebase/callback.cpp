#include "callback.h"
#include "appController.h"
#include "utils.h"
using namespace appController;

CustomCallback::CustomCallback (float samplerate)
  : AudioCallback (samplerate) {}

CustomCallback::~CustomCallback(){
  delete sine[0];
  delete sine[1];
}

void CustomCallback::prepare (int samplerate) {
  std::cout << "samplerate: " << samplerate << std::endl;
  displayTitlescreen();
  std::cout << Utils::color("\nPress Enter to start","brightCyan") << std::endl;

  std::string input;
  bool hasStarted = false;

  while(!hasStarted) {
    switch (std::cin.get()) {
      default:
        hasStarted = true;
    }
  }

  for (int i = 0; i < 2; i++) {
    sine[i] = new Sine(220, samplerate);
  }
  // oscillator.setSamplerate (samplerate);
}

void CustomCallback::process (AudioBuffer buffer) {
  auto [inputChannels,
        outputChannels,
        numInputChannels,
        numOutputChannels,
        numFrames] = buffer;

  for (int channel = 0u; channel < numOutputChannels; ++channel) {
    for (int frame = 0u; frame < numFrames; ++frame) {
      outputChannels[channel][frame] = 0.0;
      float sample = sine[channel]->getSample();

      // amplitude limited to 0.3
      outputChannels[channel][frame] = sample;
      sine[channel]->tick();


      // oscillatorFifth.tick();
      // oscillatorFifthDetuned.tick();
    }
  }
}
