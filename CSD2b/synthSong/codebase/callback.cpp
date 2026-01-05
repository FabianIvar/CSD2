#include "callback.h"

CustomCallback::CustomCallback(float samplerate)
  : AudioCallback(samplerate), melody(24, samplerate)  {}

CustomCallback::~CustomCallback() {

  for (int i = 0; i < 2; i++) {
    delete synth[i];
    synth[i] = nullptr;
  }
  std::cout << std::endl;
}

void CustomCallback::prepare (int samplerate) {

  appCtrl::displayTitlescreen();

  appCtrl::questionSynthType();

//===========================================================//

// 0 for additive, 1 for fm
  int synthType = appCtrl::getValidIntInput();

  if (!synthType) { // Additive Synth


    appCtrl::questionWaveType("Pick Wavetype");
    int addWaveType = appCtrl::getValidIntInput();

    appCtrl::questionValInBounds("Set Amount of Partials", "1", "50");
    int voicesAmt = static_cast<int>(appCtrl::getValidValInput("int"));

    std::vector<float> partialAmps;
    for (int i = 0; i < voicesAmt; i++) {
      appCtrl::questionValInBounds(
        "Set Amplitude of Voice "+ std::to_string(i), "0.0", "1.0");
        partialAmps.push_back(appCtrl::getValidValInput("float"));
    }

    for (int i = 0; i < 2; i++) {

/* args: [1]frequency, [2]samplerate, [3]waveType, [4]voicesAmt */
      synth[i] = new Additive(
        melody.getNoteFrequency(), samplerate, addWaveType, voicesAmt);

      int partialNum = 0;
      for (auto j : partialAmps) { // Sets amplitude of partials
        synth[i]->setOscAmplitude(partialNum, j);
        partialNum++;
      }

      synth[i]->setSynthAmplitude(melody.getNoteAmplitude());
    }
  }
  else if (synthType) { // FM Synth
    appCtrl::questionWaveType("Pick Carrier Wavetype");
    int carWaveType = appCtrl::getValidIntInput();

    appCtrl::questionWaveType("Pick Modulator Wavetype");
    int modWaveType = appCtrl::getValidIntInput();

    appCtrl::questionValInBounds("Set Ratio", "0.5", "25.0");
    float ratio = appCtrl::getValidValInput("float");

    appCtrl::questionValInBounds("Set Modulation Index", "0.0", "100.0");
    float modIndex = appCtrl::getValidValInput("float");

    for (int i = 0; i < 2; i++) {

/* args: [1]carrierFrequency, [2]samplerate, [3]carrierWaveType,
        [4]modulatorWaveType, [5]ratio, [6]modulationIndex */
      synth[i] = new Fm(melody.getNoteFrequency(), samplerate,
        carWaveType, modWaveType, ratio, modIndex);
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
    }
  }
}
