// appController handles UI and input validation

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

// using namespace std;

namespace appCtrl {
  typedef std::vector<std::string> strVec;
  typedef std::vector<int> intVec;
  typedef std::vector<float> floatVec;

/* This class stores values of various types
   to compare user input to. */
  class Compare {
    appCtrl::strVec validIntegers;
    std::vector<float> validFloats;
  public:
    void setValidIntegers(std::vector<int> values);
    void setValidFloats(floatVec);
    appCtrl::strVec getValidIntegers();
    std::vector<float> getValidFloats();
  };

  std::string color(std::string textInput, std::string color);
  void displayTitlescreen();

  void questionSynthType(); // Done
  void questionCarWaveType(); // Done
  void questionModWaveType(); // Done

  void displayOptions(
    strVec options, strVec numboxColor, strVec optionColor);

  // void questionModIndex();
  void questionRatio(); // Done

  void displayBounds(
    strVec bounds, strVec boxColor, std::string promptColor);

  int getValidIntInput();
  float getValidFloatInput();









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
