#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include <iostream>
#include "effects/waveshaper.hpp"
#include "effects/feedbackDelay.hpp"
#include "effects/filter.hpp"
#include "utils/bufferToolkit.hpp"
#include "utils/interpolation.hpp"

using namespace BufferToolkit;
using namespace Interpolation;

#define DEBUG 1


class EffectsChain {
public:
  EffectsChain() {
    #if DEBUG
      std::cout << "EffectsChain Constructor" << std::endl;
    #endif

    //  (dryWet | kFactor)
    waveshaper = new Waveshaper(1.0f, 25.0f);

    for (uint i = 0; i < 2; i++) {

      //   dryWet | delayTimeMS | maxDelayTimeMS |feedback | samplerate)
      delay[i] = new FeedbackDelay(0.3f, 125.0f, 1000.0f, 0.3f, 48000.0f);

      //  (dryWet | cutoff | qFactor | dBgain | samplerate)
      // filter = new Filter(1.0, );

    }

  }

  ~EffectsChain() {

    delete waveshaper;
    waveshaper = nullptr;

    for (int i = 0; i < 2; i++) {
        delete delay[i];
        delay[i] = nullptr;
      }

    #if DEBUG
      std::cout << "EffectsChain Destroyed" << std::endl;
    #endif
  }

  void prepareToPlay(float sampleRate, int numSamplesPerBlock){
    // Your Prepare Goes Here


  }

  void getNextBlock(juce::AudioBuffer<float>& buffer){
    // performance can be improved with interleaving, out of scope for now
    // also multithreading? where would I use this?

    float sample[2];
    // Your DSP goes here
    for(int channel = 0; channel < buffer.getNumChannels(); ++channel){
      auto* input = buffer.getReadPointer(channel); // was inputChannel
      auto* output = buffer.getWritePointer(channel); // was outputChannel

      for (int frame = 0; frame < buffer.getNumSamples(); ++frame){
        // outputChannel[sample] = inputChannel[sample];
        // waveshaper[channel]->processFrame(input[frame], sample[channel]);
        // // delay[channel]->applyEffect()
        // delay[channel]->setDryWet(m_parameter);
        // delay[channel]->processFrame(waveshaper[channel]->getSample(), sample[channel]);
        //
        // sample[channel] = delay[channel]->getSample();
        //
        // output[frame] = sample[channel];

        waveshaper->processFrame(input[frame], output[frame]);

      }
    }
  }

  void setParameter(float parameter) { m_parameter = parameter; }

    // m_parameter = parameter;
    // for (uint i = 0; i < 2; i++) {
    //   delay[i]->setDelayTimeMs(linear<float>(parameter, 125.0f, 1000.0f));
    // }

    // Your Code goes here
    // std::cout << "\n---->parameter: " << parameter << std::endl;

private:
  Effect* waveshaper;
  Effect* delay[2];
  float m_parameter;
  // Effect* filter;
};
