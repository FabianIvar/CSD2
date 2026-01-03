#include "callback.h"
#include "appController.h"
#include "utils.h"

CustomCallback::CustomCallback(float samplerate)
  : AudioCallback(samplerate), melody(12, samplerate)  {}

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

// TODO: move this to appController color brightCyan
  std::cout << "\nPress Enter to start" << std::endl;

  std::string input;
  bool hasStarted = false;
  while(!hasStarted) {
    switch (std::cin.get()) {
      default:
        hasStarted = true;
    }
  }

//===========================================================//

// TEMP: 0 for additive, 1 for fm, (temporary if statement)
  int synthType = 0;

  if (!synthType) {
    for (int i = 0; i < 2; i++) {

/* args: [1]frequency, [2]samplerate, [3]waveType, [4]voicesAmt */
      synth[i] = new Additive(melody.getNoteFrequency(), samplerate, 0, 10);
      synth[i]->setOscAmplitude(1, 0.0f);
      synth[i]->setOscAmplitude(3, 0.0f);
      synth[i]->setOscAmplitude(5, 0.0f);
      synth[i]->setOscAmplitude(7, 0.0f);
      synth[i]->setOscAmplitude(9, 0.0f);
      synth[i]->setSynthAmplitude(melody.getNoteAmplitude());
    }
  }
  else if (synthType) {
    for (int i = 0; i < 2; i++) {

/* args: [1]carrierFrequency, [2]samplerate, [3]carrierWaveType,
        [4]modulatorWaveType, [5]ratio, [6]modulationIndex */
      synth[i] = new Fm(melody.getNoteFrequency(), samplerate, 0, 0, 1.0f, 5.0f);
      synth[i]->setSynthAmplitude(melody.getNoteAmplitude());
    }
  }
}

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
      synth[channel]->synthTick();
      melody.tick();
      if (melody.tick()) {
        for (int i = 0; i < 2; i++) {
          synth[i]->setSynthFrequency(melody.getNoteFrequency());
          synth[i]->setSynthAmplitude(melody.getNoteAmplitude());
        }
      }




      // oscillatorFifth.tick();
      // oscillatorFifthDetuned.tick();
    }
  }
}
