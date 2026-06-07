#include <iostream>
#include "audiocomponent.h"

#define DEBUG 1

struct CustomCallback : AudioCallback {
  explicit CustomCallback(double Fs) : AudioCallback(Fs) {
    // stuff.prepare()
  }

  ~CustomCallback() override { }

  void prepare(int sampleRate, int blockSize) override {
    // stuff to prepare
  }

  void process(AudioBuffer buffer) override {
    auto [inputChannels, outputChannels, numInputChannels,
    numOutputChannels, numFrames] = buffer;

    // Main Loop here
    for (auto sample = 0; sample < numFrames; ++sample) {

/*=============================================================================
(example)
      something.tick();
      float someSample = something.getSample();
      float processedSomething = someEffect.process(someSample)

      everything that is the same for both channels should be here

=============================================================================*/

      for(auto channel = 0; channel < numOutputChannels; ++channel) {

/*=============================================================================

      outputChannels[channel][sample] = theSampleProcessed

=============================================================================*/
      }
    }
  }
}


int main() {
  std::cout << std::endl;
  #if DEBUG
  std::cout <<
    "Starting program...\n"
  << std::endl;
  #endif


  ScopedMessageThreadEnabler scopedMessageThreadEnabler;
  CustomCallback audioSource(48000);
  JUCEModule juceModule(audioSource);
  juceModule.init(2, 2); // Channels ( Input | Output )


  std::cout << "Press q Enter to quit..." << std::endl;
  bool running = true;
  while (running) {
    switch (std::cin.get()) {
      case 'q':
        running = false;
        break;
    }
  }


  #if DEBUG
  std::cout <<
    "\nProgram finished... shutting down"
  << std::endl;
  #endif

  std::cout << std::endl;
  return 0;
}
