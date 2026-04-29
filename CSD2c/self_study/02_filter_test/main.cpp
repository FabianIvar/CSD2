//
// Created by Dean on 02/12/2023.
//

#include "audiocomponent.h"
#include <iostream>
#include <oscillator.h>
#include <saw.h>
#include "Filters.hpp"
#include "deltasequence.h"

struct CustomCallback : AudioCallback {
    explicit CustomCallback(double Fs) : AudioCallback(Fs) {
// arguments: ( frequency in Hz | q-factor | dbGain | samplerate )
    filter.prepare(5000.0f, 0.5f, 10.0f, static_cast<float>(Fs));
    // filter.setCoefficient(0.9f);
    }

    ~CustomCallback() override {
    }

    void prepare(int sampleRate, int blockSize) override {
      saw.prepare(sampleRate);
      saw.setFrequency(200.5f);
    }

    void process(AudioBuffer buffer) override {
        auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;


        for (auto sample = 0u; sample < numFrames; ++sample) {
            saw.tick();
            float oscSample = saw.getSample() * 0.2f;
            float filteredOutput = filter.process(oscSample);
            for(auto channel = 0u; channel < numOutputChannels; ++channel) {
                outputChannels[channel][sample] = filteredOutput;
            }
        }
    }


    Saw saw {200};
    Biquad filter; // set Filter!
};

#define Delta_Sequence 0

int main() {


#if Delta_Sequence
    ScopedMessageThreadEnabler scopedMessageThreadEnabler;
    CustomCallback audioSource(48000);
    DeltaSequence::run(audioSource.filter);
#else
    ScopedMessageThreadEnabler scopedMessageThreadEnabler;
    CustomCallback audioSource(48000);
    JUCEModule juceModule(audioSource);
    juceModule.init(2, 2);


    std::cout << "Press q Enter to quit..." << std::endl;
    bool running = true;
    while (running) {
        switch (std::cin.get()) {
            case 'q':
                running = false;
                break;
        }
    }
#endif
    return 0;
}
