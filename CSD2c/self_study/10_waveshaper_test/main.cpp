#include <iostream>
#include "audiocomponent.h"
#include "oscillators/sine.h"
#include "oscillators/oscillator.h"
#include "effect.hpp"
#include "waveshaper.hpp"
#include "bufferTools.hpp"
#include "interpolation.hpp"

#define DEBUG 1

struct CustomCallback : AudioCallback {
  explicit CustomCallback(double Fs) : AudioCallback(Fs) {
    // stuff.prepare()
    osc->prepare(static_cast<float>(Fs));
    osc->setFrequency(100.0f);
  }

  ~CustomCallback() override {
    delete osc;
    delete waveshaper;
    osc = nullptr;
    waveshaper = nullptr;
  }

  void prepare(int sampleRate, int blockSize) override {
    // stuff to prepare - effects for example


  }

  void process(AudioBuffer buffer) override {
    auto [inputChannels, outputChannels, numInputChannels,
    numOutputChannels, numFrames] = buffer;

    // Main Loop here
    for (auto sample = 0; sample < numFrames; ++sample) {

//========================================================================

      osc->tick();
      float oscSample = osc->getSample();
      float distSample;

      waveshaper->processFrame(oscSample, distSample);

      float processedSample = waveshaper->getSample();
//========================================================================

      for(auto channel = 0; channel < numOutputChannels; ++channel) {
        outputChannels[channel][sample] = processedSample;
/*=============================================================================

      outputChannels[channel][sample] = theSampleProcessed

=============================================================================*/
      }
    }
  }

  Oscillator* osc = new Sine;
  Effect* waveshaper = new Waveshaper(1.0f, 25.0f);

};


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


  std::cout << "\nPress q Enter to quit..." << std::endl;
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
