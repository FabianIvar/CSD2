#include "callback.h"
#include "appController.h"
#include "utils.h"

CustomCallback::CustomCallback (float samplerate)
  : AudioCallback (samplerate) {}

CustomCallback::~CustomCallback(){

  // delete waveType;
  // waveType = nullptr;

  for (int i = 0; i < 2; i++) {
    delete synth[i];
    synth[i] = nullptr;
  }
  // delete wave[1];
  // wave[1] = nullptr;
}

void CustomCallback::prepare (int samplerate) {

  appController::displayTitlescreen();

  // Press enter to start TODO: move this to appController color brightCyan
  std::cout << "\nPress Enter to start" << std::endl;

  std::string input;
  bool hasStarted = false;
  while(!hasStarted) {
    switch (std::cin.get()) {
      default:
        hasStarted = true;
    }
  }

//============================================================================//

// implicit conversion: int samplerate to float samplerate
  for (int i = 0; i < 2; i++) {
    // TODO: add amplitude, or a 'setAmplitude'
    // function that can set the amplitude of a specific partial
    // args: frequency, samplerate, waveType, voicesAmt
    synth[i] = new Additive(220.0f, samplerate, 0, 4);
  }

}

//============================================================================//

void CustomCallback::process (AudioBuffer buffer) {
  // destructurization
  auto [inputChannels,
        outputChannels,
        numInputChannels,
        numOutputChannels,
        numFrames] = buffer;

  for (int channel = 0u; channel < numOutputChannels; ++channel) {
    for (int frame = 0u; frame < numFrames; ++frame) {
      outputChannels[channel][frame] = 0.0;
      float sample = synth[channel]->getSynthSample();

      outputChannels[channel][frame] = sample;
      synth[channel]->tick();


      // oscillatorFifth.tick();
      // oscillatorFifthDetuned.tick();
    }
  }
}
