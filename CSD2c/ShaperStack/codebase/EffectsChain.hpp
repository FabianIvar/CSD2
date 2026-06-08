#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include <iostream>
#include "effects/waveshaper.hpp"
#include "effects/feedbackDelay.hpp"
#include "effects/filter.hpp"

#define DEBUG 1


class EffectsChain {
public:
  EffectsChain() {}
  void prepareToPlay(float sampleRate, int numSamplesPerBlock){
    // Your Prepare Goes Here

    //  (dryWet | kFactor)
    waveshaper = new Waveshaper(1.0f, 25.0f);

    //  (delayTime | maxDelayTime | feedback | dryWet | samplerate)
    delay = new FeedbackDelay(500.0f, 1000.0f, 0.8f, 1.0f, 48000.0f);

    //  (dryWet | cutoff | qFactor | dBgain | samplerate)
    // filter = new Filter(1.0, );

  }

    void getNextBlock(juce::AudioBuffer<float>& buffer){
        // Your DSP goes here

        for(int channel = 0; channel < buffer.getNumChannels(); ++channel){
            auto* inputChannel = buffer.getReadPointer(channel);
            auto* outputChannel = buffer.getWritePointer(channel);
            for (int sample = 0; sample < buffer.getNumSamples(); ++sample){
                outputChannel[sample] = inputChannel[sample];
            }
        }


    }

    void setParameter(float parameter){
        // Your Code goes here
    }

private:
  Effect* waveshaper;
  Effect* delay;
  // Effect* filter;
};
