// appController handles UI, input and validation

#pragma once
#include <string>

namespace appController {
  void displayTitlescreen();
  void askSynthType(string synthTypes[]);
  void askWaveType(string waveTypes[]);
  void askNumOsc(int max);

  // void confirmSettings

  // Function overloading
  string getUserInput(
    string expectedType);
  string getUserInput(
    string expectedType, float min, float max);
  string getUserInput(
    string expectedType, float min, float max, bool constrainInput);


}
