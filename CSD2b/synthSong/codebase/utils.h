#pragma once
#include <iostream>

namespace utils {
  std::string color(
    std::string text, std::string color);
  float arrSum(
    float inputArray[], int start = 0, int stop = 16);
  float constrain(
    float inputValue, float minimum, float maximum);

  float noteSampleDur(
    float lenQNotes, int sampleRate);
  float mtof(
    int midiPitch);
  float velToAmp(
    int midiVel);
}
