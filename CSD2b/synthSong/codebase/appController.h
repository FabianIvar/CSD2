// appController handles UI and input validation

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

namespace appCtrl {
  typedef std::vector<std::string> strVec;
  typedef std::vector<int> intVec;
  typedef std::vector<float> floatVec;

// This class stores values to compare user input to.
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

  // Displays Ascii art title screen
  void displayTitlescreen();
  // Displays "-=<(question)>=-"
  void displayQuestion(std::string question);
  // Displays start message and waits for input
  void displayStartMessage();
  // Displays quit message and waits for input
  void displayQuitMessage();

  // Display request for the user to pick synthesizer type
  void questionSynthType();
  // Display request for the user to pick a wavetype
  void questionWaveType(std::string question);
  // List enumerated options for multiple choice questions
  void displayOptions(
    strVec options, strVec numboxColor, strVec optionColor);
  // Display request for a value within given bounds
  void questionValInBounds(std::string question,
    std::string lowerBound, std::string upperBound);
  /* Display the lower and upper bounds, values
     that are within these bounds are valid */
  void displayBounds(
    strVec bounds, strVec boxColor, std::string promptColor);

  // returns validated user input as integer
  int getValidIntInput();
  /* returns validated user input as float, (can be used for
     ints, floats and doubles when return value is casted) */
  float getValidValInput(std::string expectedType);
}
