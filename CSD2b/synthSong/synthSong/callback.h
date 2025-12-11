#include <iostream>
#include "audiocomponent.h"
// oscillator.h should eventually be Synth.h
#include "oscillator.h"
//  Daan Schrier


// the class customcallback inherits code from audiocallback

// CustomCallback overrides values from Juce::AudioCallback
struct CustomCallback : AudioCallback {
  // a double is a float at 64bit so with twice as many numbers

  // initializer list?
  // explicit has something to do with typeCasting
  // parameterized explicit constructor with initilization list
    explicit CustomCallback (double Fs) : AudioCallback(Fs) {

    }

    ~CustomCallback() override {

    }

    void prepare (int sampleRate) override {
      oscillator.setSamplerate (samplerate);
      cout << "\nsamplerate: " << samplerate << "\n";
    }

/*
    void process (AudioBuffer buffer) override {
        auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;


        for (int channel = 0u; channel < numOutputChannels; ++channel) {
            for (int sample = 0u; frame < numFrames; ++frame) {
                // write frame to buffer at channel 0, amp = 0.25
                outputChannels[channel][frame] = oscillator.getSample();
                oscillator.tick();
            }
        }
    }

};
