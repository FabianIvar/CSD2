#pragma once
// #include <iostream>
// #include <string>
using namespace std;
#include <sstream>

namespace utils {
  std::string color(
    std::string text, std::string color);
  // auto arrSlice(
  //   auto inputArray[], int startPos, int stopPos);

  float arrSum(
    float inputArray[], int start, int stop);
  float constrain(
    float inputValue, float minimum, float maximum);

  double noteSampleDur(
    int bpm, float LenQNotes, double sampleRate);
  double mtof(
    int midiPitch);
  double velToAmp(
    int midiVel);

  /* TODO if I feel like it,
    this is kinda duplicate code, but it is also
    what happens with a template. compiler just makes
    more versions of the same function. I can't figure
    out how to use templates in a namespace, so a class
    with dynamic polymorphism remains as an option.
    Also maybe make an arrSlice function*/

  template <typename T>
  std::string pToString(const T& pointer);
  // std::string pToString(float* inputPointer);
  // std::string pToString(double* inputPointer);
}
