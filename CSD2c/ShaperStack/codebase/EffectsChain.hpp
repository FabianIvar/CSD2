#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include <iostream>
#include "effects/waveshaper.hpp"
#include "effects/feedbackDelay.hpp"
#include "effects/filter.hpp"
#include "utils/smoothing.hpp"
#include "utils/bufferToolkit.hpp"
#include "utils/interpolation.hpp"

using namespace BufferToolkit;
using namespace Interpolation;

#define DEBUG 1


//===============================================


class EffectsChain {
public:
  EffectsChain() {
    #if DEBUG
      std::cout << "EffectsChain Constructor" << std::endl;
    #endif
  }

  ~EffectsChain() {

    delete waveshaper;
    waveshaper = nullptr;

    for (int i = 0; i < 2; i++) {
      delete smooth[i];
      smooth[i] = nullptr;
      delete delay[i];
      delay[i] = nullptr;
    }

    #if DEBUG
      std::cout << "EffectsChain Destroyed" << std::endl;
    #endif
  }

  void prepareToPlay(float samplerate, int numSamplesPerBlock){

    //  (dryWet | kFactor)
    waveshaper = new Waveshaper(1.0f, 25.0f);


    for (uint i = 0; i < 2; i++) {
      //  (samplerate | ms)
      smooth[i] = new Smoothing(samplerate, 500.0f);

      //  (dryWet | delayTimeMS | maxDelayTimeMS |feedback | samplerate)
      delay[i] = new FeedbackDelay(0.3f, 150.0f, 4000.0f, 0.0f, samplerate);

      //  (dryWet | cutoff | qFactor | dBgain | samplerate)
      // filter[i] = new Filter(1.0, );
    }
    m_prepared = true;
  }

  void getNextBlock(juce::AudioBuffer<float>& buffer){
    // performance can be improved with interleaving, out of scope for now
    // also multithreading could improve performance
    // also also, plugin won't work if more then two channels are used

    float sample[2];

    for(int channel = 0; channel < buffer.getNumChannels(); ++channel){
      auto* input = buffer.getReadPointer(channel); // was inputChannel
      auto* output = buffer.getWritePointer(channel); // was outputChannel
      // delay[channel]->setParam(m_parameter);

      for (int frame = 0; frame < buffer.getNumSamples(); ++frame) {
        m_parameter = smooth[channel]->getNextValue();

        delay[channel]->setParam(m_parameter);
        waveshaper->processFrame(input[frame], output[frame]);
        delay[channel]->processFrame(waveshaper->getSample(), output[frame]);
        output[frame] = delay[channel]->getSample();
        if (output[frame] > 1.0f) output[frame] = 1.0f;
        else if (output[frame] < -1.0f) output[frame] = -1.;
      }

    }
  }

  void setParameter(float parameter) {
    if (m_storedParameter != parameter && m_prepared) {
      for (int i = 0; i < 2; i++) smooth[i]->setTargetValue(parameter);
      #if DEBUG
        std::cout << "-----[ parameter ]-----> " << parameter << std::endl;
      #endif
    }
  }

private:
  Effect* waveshaper;
  Effect* delay[2];
  Smoothing* smooth[2];
  float m_parameter;
  float m_storedParameter;
  bool m_prepared;
  // Effect* filter;
};
