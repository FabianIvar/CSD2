#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include <iostream>
#include "effects/waveshaper.hpp"
#include "effects/feedbackDelay.hpp"
#include "effects/filter.hpp"
#include "utils/mapping.hpp"
#include "utils/smoothing.hpp"
#include "utils/bufferToolkit.hpp"
#include "utils/interpolation.hpp"

using namespace BufferToolkit;
using namespace Interpolation;

#define DEBUG 1


//===============================================


class EffectsChain {
public:
  EffectsChain() : m_prepared(false) {
    #if DEBUG
      std::cout << "EffectsChain Constructor" << std::endl;
    #endif
  }

  ~EffectsChain() {

    delete waveshaper;
    waveshaper = nullptr;
    delete mapping;
    mapping = nullptr;

    for (int i = 0; i < 2; i++) {
      delete smooth[i];
      smooth[i] = nullptr;
      delete delay[i];
      delay[i] = nullptr;
      delete filter[i];
    }

    #if DEBUG
      std::cout << "EffectsChain Destroyed" << std::endl;
    #endif
  }

  void prepareToPlay(float samplerate, int numSamplesPerBlock){

    //  generates buffers with the mapping for the different effects.
    //  1 = eq1 mapping | 2 = eq2 mapping | 3 = eq3 mapping | 4 = delay mapping
    mapping = new Mapping();

    //  (dryWet | kFactor)
    waveshaper = new Waveshaper(1.0f, 25.0f);


    for (uint i = 0; i < 2; i++) {
      //  (samplerate | ms)
      smooth[i] = new Smoothing(samplerate, 300.0f);

      //  (dryWet | delayTimeMS | maxDelayTimeMS |feedback | samplerate)
      delay[i] = new FeedbackDelay(0.9f, 150.0f, 1000.0f, 0.4f, samplerate);

      //  (dryWet | cutoff | qFactor | dBgain | samplerate)
      filter[i] = new Filter(1.0, 500.0f, 4.0f, 20.0f, samplerate);
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
      delay[channel]->setParam(m_parameter);

      for (int frame = 0; frame < buffer.getNumSamples(); ++frame) {
        m_parameter = smooth[channel]->getNextValue();

        // delay[channel]->setParam(m_parameter);
        filter[channel]->setDryWet(m_parameter);
        filter[channel]->processFrame(input[frame], output[frame]);

        // waveshaper->processFrame(filter[channel]->getSample(), output[frame]);
        // delay[channel]->processFrame(waveshaper->getSample(), output[frame]);
        // output[frame] = delay[channel]->getSample();
        output[frame] = filter[channel]->getSample();

        // clip if output exceeds bounds
        if (output[frame] > 1.0f) output[frame] = 1.0f;
        else if (output[frame] < -1.0f) output[frame] = -1.0f;
      }
    }
  }

  void setParameter(float parameter) {
    if (m_storedParameter != parameter && m_prepared) {
      for (int i = 0; i < 2; i++) smooth[i]->setTargetValue(parameter);
    }
  }

private:

  enum class map {
    EQ1 = 1,
    EQ2,
    EQ3,
    DELAY
  };

  Effect* waveshaper;
  Effect* delay[2];
  Effect* filter[2];
  Smoothing* smooth[2];
  Mapping* mapping;
  float m_parameter;
  float m_storedParameter;
  bool m_prepared;
};
