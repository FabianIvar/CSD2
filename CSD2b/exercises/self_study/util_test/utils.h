#pragma once
#include <iostream>

namespace utils {
  std::string color(
    std::string text, std::string color);
  float arrSum(
    float inputArray[]);
  float constrain(
    float inputValue, float minimum, float maximum);

  double noteSampleDur(
    int bpm, float lenQNotes, double sampleRate);
  double mtof(
    int midiPitch);
  double velToAmp(
    int midiVel);
}
