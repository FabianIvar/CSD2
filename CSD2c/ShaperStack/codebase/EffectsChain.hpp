/* performance can be improved with interleaving,
also multithreading could improve performance
the filters are in the direct form and could be more efficient
also, plugin won't work if more then two channels are being used.
improving performance is out of scope for now */

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
      delete filter1[i];
      filter1[i] = nullptr;
      delete filter2[i];
      filter2[i] = nullptr;
      delete filter3[i];
      filter3[i] = nullptr;
    }

    #if DEBUG
      std::cout << "EffectsChain Destroyed" << std::endl;
    #endif
  }

  void prepareToPlay(float samplerate, int numSamplesPerBlock){

    //  generates the mapping for the different effects.
    //  1 = eq1 mapping | 2 = eq2 mapping | 3 = eq3 mapping | 4 = delay mapping
    mapping = new Mapping();

    //  (dryWet | kFactor)
    waveshaper = new Waveshaper(1.0f, 7.5f);


    for (uint i = 0; i < 2; i++) {
      //  (samplerate | ms)
      smooth[i] = new Smoothing(samplerate, 300.0f);

      //  (dryWet | delayTimeMS | maxDelayTimeMS |feedback | samplerate)
      delay[i] = new FeedbackDelay(0.9f, 75.0f, 850.0f, 0.8f, samplerate);

      //  (dryWet | cutoff | qFactor | dBgain | samplerate)
      filter1[i] = new Filter(1.0, 500.0f, 4.0f, 15.0f, samplerate);
      filter2[i] = new Filter(1.0, 1500.0f, 8.0f, 16.0f, samplerate);
      filter3[i] = new Filter(1.0, 1900.0f, 4.0f, 15.5f, samplerate);
    }
    m_prepared = true;
  }

  void getNextBlock(juce::AudioBuffer<float>& buffer){

    float sample[2];

    for(int channel = 0; channel < buffer.getNumChannels(); ++channel){
      auto* input = buffer.getReadPointer(channel); // was inputChannel
      auto* output = buffer.getWritePointer(channel); // was outputChannel
      delay[channel]->setParam(m_parameter);

      for (int frame = 0; frame < buffer.getNumSamples(); ++frame) {
        m_parameter = smooth[channel]->getNextValue();
        #if DEBUG
          std::cout << "m_parameter: " << m_parameter << std::endl;
        #endif

        delay[channel]->setParam(1.0f - m_parameter);

        filter1[channel]->setDryWet(
          mapping->getValue(static_cast<int>(map::EQ1), m_parameter));
        filter2[channel]->setDryWet(
          mapping->getValue(static_cast<int>(map::EQ2), m_parameter));
        filter3[channel]->setDryWet(
          mapping->getValue(static_cast<int>(map::EQ3), m_parameter));
        delay[channel]->setDryWet(
          mapping->getValue(static_cast<int>(map::DELAY), m_parameter));


        delay[channel]->processFrame(input[frame], output[frame]);
        filter1[channel]->processFrame(
          delay[channel]->getSample(), output[frame]);
        waveshaper->processFrame(filter1[channel]->getSample(), output[frame]);
        filter2[channel]->processFrame(waveshaper->getSample(), output[frame]);
        waveshaper->processFrame(filter2[channel]->getSample(), output[frame]);
        filter3[channel]->processFrame(waveshaper->getSample(), output[frame]);
        waveshaper->processFrame(filter3[channel]->getSample(), output[frame]);

        output[frame] = waveshaper->getSample();

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

  enum class map { EQ1 = 1, EQ2, EQ3, DELAY };

  Effect* waveshaper;
  Effect* delay[2];
  Effect* filter1[2];
  Effect* filter2[2];
  Effect* filter3[2];
  Smoothing* smooth[2];
  Mapping* mapping;
  float m_parameter;
  float m_storedParameter;
  bool m_prepared;
};
