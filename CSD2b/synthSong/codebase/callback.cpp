#include "callback.h"
#include "appController.h"
#include "utils.h"

CustomCallback::CustomCallback (float samplerate)
  : AudioCallback (samplerate) {}

CustomCallback::~CustomCallback(){

  delete waveType;
  waveType = nullptr;

  for (int i = 0; i < 2; i++) {
    delete synthType[i];
    synthType[i] = nullptr;
  }
  // delete wave[1];
  // wave[1] = nullptr;
}

void CustomCallback::prepare (int samplerate) {

  std::cout << "\n\nsamplerate: " << samplerate << std::endl;
  appController::displayTitlescreen();
  std::cout << Utils::color("\nPress Enter to start","brightCyan") << std::endl;

// Press enter to start TODO: move this to appController
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
    synthType[i] = new Additive(220.0f, samplerate);
  }

}

//============================================================================//

void CustomCallback::process (AudioBuffer buffer) {
  auto [inputChannels,
        outputChannels,
        numInputChannels,
        numOutputChannels,
        numFrames] = buffer;

  for (int channel = 0u; channel < numOutputChannels; ++channel) {
    for (int frame = 0u; frame < numFrames; ++frame) {
      outputChannels[channel][frame] = 0.0;
      float sample = wave[channel]->getSample();

      // amplitude limited to 0.3
      outputChannels[channel][frame] = sample;
      wave[channel]->tick();


      // oscillatorFifth.tick();
      // oscillatorFifthDetuned.tick();
    }
  }
}
