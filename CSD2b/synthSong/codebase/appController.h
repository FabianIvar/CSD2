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

  class Compare {
    appCtrl::strVec validIntegers;
  public:
    void setValidIntegers(intVec validInput);
    appCtrl::strVec getValidIntegers();
  };

  std::string color(std::string textInput, std::string color);
  void displayTitlescreen();
  void displayOptions(
    strVec options, strVec enumColor, strVec optionColor);

  void questionSynthType();
  void questionCarWavType();
  void questionModWavType();
  void questionRatio();
  void questionModIndex();
  int getValidIntInput();


/* This class stores values of various types
   to compare user input to. */







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
