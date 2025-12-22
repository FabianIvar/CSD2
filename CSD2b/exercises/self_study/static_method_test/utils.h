#pragma once
#include <sstream>
#include <vector>

  namespace utils {
    std::string color(
      std::string text, std::string color);


    void* arrSum(
       inputArray[], int start = 0, int stop = 16);

    template <typename T>
    T constrain(
      T inputValue, T minimum, T maximum);

    float noteSampleDur(
      float lenQNotes, int sampleRate);
    float mtof(
      int midiPitch);
    float velToAmp(
      int midiVel);
  }
};
