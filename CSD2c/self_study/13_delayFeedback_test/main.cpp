#include <iostream>
#include "audiocomponent.h"
#include "oscillators/sine.h"
#include "effects/waveshaper.hpp"
#include "envelope.hpp"
#include "effects/feedbackDelay.hpp"

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

//========[Main Loop]========

    for (auto sample = 0; sample < numFrames; ++sample) {
    // for every frame, so both channels get the same sample as input

      osc->tick();
      env.tick();
      float out;

      // float amp = env.getAmplitude();

      // dat gedoe met &output in processFrame is raar man
      // TODO verander dat misschien

      waveshaper->processFrame(osc->getSample(), out);
      delay->processFrame(waveshaper->getSample() * env.getAmplitude(), out);

      float processedSample = delay->getSample();

      for(auto channel = 0; channel < numOutputChannels; ++channel) {
      // for every channel, so channels get a different sample as input
        outputChannels[channel][sample] = processedSample;

      }
    }
  }

  Oscillator* osc = new Sine;
  Effect* waveshaper = new Waveshaper(1.0f, 25.0f);
  Envelope env = Envelope(48000.0f, 15.0f, 100.0f, 250.0f);
  Effect* delay = new FeedbackDelay(500.0f, 1000.0f, 0.8f, 1.0f, 48000.0f);

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
