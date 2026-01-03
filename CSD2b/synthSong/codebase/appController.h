// appController handles UI and input validation

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

namespace appController {

  std::string color(std::string textInput, std::string color);
  void displayTitlescreen();
  void askSynthType();
  typedef std::vector<std::string> strVec;
  // void askSynthType(std::string synthTypes[]);
  // void askWaveType(std::string waveTypes[]);
  // void askNumOsc(int max);

  // // void confirmSettings
  //
  // // Function overloading
  // std::string getUserInput(
  //   std::string expectedType);
  // std::string getUserInput(
  //   std::string expectedType, float min, float max);
  // std::string getUserInput(
  //   std::string expectedType, float min, float max, bool constrainInput);
}
