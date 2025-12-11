//
// Created by Dean on 02/12/2023.
// Messed around with by Fabean on 11/12/2025.
//

#include <juce_audio_basics/juce_audio_basics.h>
#include <juce_audio_devices/juce_audio_devices.h>
#include <iostream>
// using namespace std;


struct AudioBuffer {
    const float** inputChannels;
    float** outputChannels;
    int numInputChannels, numOutputChannels, numFrames;

private:

};

// audiocallback inherits from juce audiosource
// maybe audiocallback sets the main settings for audio playback which is
  // coded in Juce?
class AudioCallback : public juce::AudioSource {
public:
    // Fs stands for frame size?
    AudioCallback(double sampleRate) : Fs (sampleRate) {
      double printer = sampleRate;
      std::cout << "SampleRate in Audiocallback constructor = " << printer << std::endl;
    }

// Samplerate is arbitrary because juce sets the samplerate to 41khz??
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override {

        juce::ignoreUnused(samplesPerBlockExpected);
        Fs = sampleRate;
        prepare(static_cast<int>(Fs));
    }
    void releaseResources() override {}
    void getNextAudioBlock(
      const juce::AudioSourceChannelInfo& bufferToFill) override {
      processBlock(bufferToFill);
    }

    virtual void process(AudioBuffer buffer) = 0;
    virtual void prepare(int sampleRate) = 0;

private:
    double Fs;

    void processBlock(const juce::AudioSourceChannelInfo& bufferToFill) {
        const auto buffer = AudioBuffer {
            .inputChannels = const_cast<const float**> (
              bufferToFill.buffer->getArrayOfReadPointers()),
            .outputChannels = const_cast<float **> (
              bufferToFill.buffer->getArrayOfWritePointers()),
            .numInputChannels = bufferToFill.buffer->getNumChannels(),
            .numOutputChannels = bufferToFill.buffer->getNumChannels(),
            .numFrames = bufferToFill.buffer->getNumSamples() };
        process(buffer);
    }

};

// regelt berichten die worden gestuurd door juce
struct ScopedMessageThreadEnabler {
    ScopedMessageThreadEnabler() { juce::initialiseJuce_GUI(); }
    ~ScopedMessageThreadEnabler() { juce::shutdownJuce_GUI(); }
};


class JUCEModule {
public:
    explicit JUCEModule(AudioCallback& callback) : _callback(callback){
        audioSourcePlayer.setSource (&_callback);
        audioDeviceManager.addAudioCallback (&audioSourcePlayer);
    }

    ~JUCEModule() {
        audioDeviceManager.removeAudioCallback (&audioSourcePlayer);
    }

    void init(int numInputChannels, int numOutputChannels){
        // deze functie 'initializeWithDefaultDevices' zorgt er voor dat 'default device' wordt geselecteerd als output device
        // hoe laat ik de user kiezen?
        // iets met juce::AudioDeviceSelectorComponent
        audioDeviceManager.initialiseWithDefaultDevices(
          numInputChannels, numOutputChannels);
    }

private:
    AudioCallback& _callback;
    juce::AudioDeviceManager audioDeviceManager;
    juce::AudioSourcePlayer audioSourcePlayer;
};
