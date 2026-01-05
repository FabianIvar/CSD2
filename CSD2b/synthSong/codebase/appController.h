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
  void displayStartMessage();
  void displayQuestion(std::string question);

  // Display request for the user to pick synthesizer type
  void questionSynthType(); // Done

  // Display request for the user to pick a wavetype
  void questionWaveType(std::string question);

  // List enumerated options for multiple choice questions
  void displayOptions(
    strVec options, strVec numboxColor, strVec optionColor);

  // Display request for a value within given bounds
  void questionValInBounds(std::string question,
    std::string lowerBound, std::string upperBound);

  /* Display the lower and upper bounds, values set by the user
     that are within these bounds are valid */
  void displayBounds(
    strVec bounds, strVec boxColor, std::string promptColor);

  int getValidIntInput();
  float getValidValInput(std::string expectedType);


}
