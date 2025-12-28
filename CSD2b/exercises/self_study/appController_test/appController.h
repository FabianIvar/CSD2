// appController handles UI and input validation

#pragma once

namespace appController {
  void displayTitlescreen();
  void askSynthType(std::string synthTypes[]);
  void askWaveType(std::string waveTypes[]);
  void askNumOsc(int max);

  // void confirmSettings

  // Function overloading
  std::string getUserInput(
    std::string expectedType);
  std::string getUserInput(
    std::string expectedType, float min, float max);
  std::string getUserInput(
    std::string expectedType, float min, float max, bool constrainInput);
}
