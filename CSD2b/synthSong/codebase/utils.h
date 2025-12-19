#pragma once
#include <iostream>
#include <string>

namespace utils {
  string color(
    string text, string color);
  auto arrSlice(
    auto inputArray[], int startPos, int stopPos);
  float arrSum(float inputArray[]);


  double mtof(int midiPitch);
  double velToAmp(int velocity);
  double noteTimeDur(float noteLength);


}
