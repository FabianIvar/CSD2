#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Utils {
private:
  T inputValue;
  T minimum;
  T maximum;
  T arr[];
public:
  Utils(T val1, T val2, T val3, T val4[])
  : inputValue(val1), minimum(val2), maximum(val3), arr(val4){
  }

  static string color(string text, string color);
  static auto constrain(auto inputvalue, auto minimum, auto maximum);
  static auto arrSum(auto arr[], int start, int stop);


  static float noteSampleDur(
    float lenQNotes, int sampleRate);
  static float mtof(
    int midiPitch);
  static float velToAmp(
    int midiVel);
};
