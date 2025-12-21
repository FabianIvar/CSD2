#include "FabiansFirstSynth.h"

struct CustomCallback : AudioCallback {
    explicit CustomCallback (double Fs) : AudioCallback(Fs) {

    }

    ~CustomCallback() override {

    }

    void prepare (int sampleRate) override {
        _sampleRate = sampleRate;

        fabiansFirstSynth = new Synth (sampleRate);
    }

    void process (AudioBuffer buffer) override {
        auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;


        // rekent opnieuw uit voor zowel channel 1 als 2

/*

auto output = [fabiansFirstSynth.calculate(), fabiansFirstSynth.getSample()]

*/


        // for (int channel = 0u; channel < numOutputChannels; ++channel) {
        // voor elk kanaal
            for (int sample = 0u; sample < numFrames; ++sample) {
            // voor elke sample
                fabiansFirstSynth.calculate();
                outputChannels[channel][sample] = fabiansFirstSynth.getSample();

                outputChannels[0][sample] = fabiansFirstSynth.getSample();
                // outputChannels[1][sample] = fabiansFirstSynth.getSample();
        }
    }

  float getSampleRate(){
      return _sampelRate;
  }

private:
    Synth* fabiansFirstSynth;
    float _sampleRate
};
