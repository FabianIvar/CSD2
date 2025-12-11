#include <iostream>
#include "audiocomponent.h"
#include "sine.h"
//  Daan Schrier

// struct is just a class without public and private
// the class customcallback inherits code from audiocallback

// CustomCallback is een class die waardes in callback (van de juce library?) override vgm
struct CustomCallback : AudioCallback {
  // a double is a float at 64bit so with twice as many numbers

  // initializer list?
  // explicit has something to do with typeCasting
    explicit CustomCallback (double Fs) : AudioCallback(Fs) {

    }

    ~CustomCallback() override {

    }

    void prepare (int sampleRate) override {

    }

/* auto is a non-specific type, if it is a float array, auto will turn into a float, if it's an int auto will turn into an int etc. */
    void process (AudioBuffer buffer) override {
        auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

    // u staat voor unsigned, 0u is een unsigned int, en kan niet een negatief
    // getal worden. https://www.geeksforgeeks.org/c/difference-between-unsigned-int-and-signed-int-in-c/

        for (int channel = 0u; channel < numOutputChannels; ++channel) {
            for (int sample = 0u; sample < numFrames; ++sample) {
                // write sample to buffer at channel 0, amp = 0.25
                outputChannels[channel][sample] = sine.getSample();
                sine.tick();
            }
        }
    }

};
