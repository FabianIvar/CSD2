// appController handles UI, input and validation

#include <iostream>
#include "appController.h"
using namespace std;
using namespace utils;


void appController::displayTitlescreen() {

}
void askSynthType();
void askWaveType(string available);
void askNumOsc();
// void confirmSettings

// Function overloading
string getUserInput(
  string expectedType);
string getUserInput(
  string expectedType, float min, float max);
string getUserInput(
  string expectedType, float min, float max, bool constrainInput);
