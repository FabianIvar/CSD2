#include "callback.h"
#include "appController.h"
#include "utils.h"

CustomCallback::CustomCallback (float samplerate)
  : AudioCallback (samplerate) {}

CustomCallback::~CustomCallback() {

  // delete waveType;
  // waveType = nullptr;

  for (int i = 0; i < 2; i++) {
    delete synth[i];
    synth[i] = nullptr;
  }
  std::cout << std::endl;
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

// TEMP: 0 for additive, 1 for fm, and temporary if statement
  int synthType = 1;

  if (!synthType) {
    for (int i = 0; i < 2; i++) {
    /* TODO: Add amplitude parameter,
      or implement a 'setAmplitude' function

args: [1]frequency, [2]samplerate, [3]waveType, [4]voicesAmt */
      synth[i] = new Additive(220.0f, samplerate, 0, 4);
    }
  }
  else if (synthType) {
    for (int i = 0; i < 2; i++) {
      /* TODO: add amplitude parameter,

args: [1]carrierFrequency, [2]samplerate, [3]carrierWaveType,
      [4]modulatorWaveType, [5]ratio, [6]modulationIndex */
      synth[i] = new Fm(220.0f, samplerate, 0, 0, 2.0f, 1.0f);
    }
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
