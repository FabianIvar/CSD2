#pragma once
#include <iostream>
#include <string>

namespace utils {
  string color(
    string text, string color);
  auto arrSlice(
    auto inputArray[], int startPos, int stopPos);
  float arrSum(
    float inputArray[]);
  auto constrain(
    auto inputValue, auto minimum, auto maximum);

  double noteSampleDur(
    int bpm, float LenQNotes, double sampleRate);
  double mtof(
    int midiPitch);
  double velToAmp(
    int midiVel);
}
