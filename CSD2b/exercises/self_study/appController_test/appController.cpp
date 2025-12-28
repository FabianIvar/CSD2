// appController handles UI and input and validation

#include <iostream>
#include "appController.h"
#include "utils.h"
using namespace Utils;


void appController::displayTitlescreen() {

/* Font Author: Loic Cressot
This font is free to use and distribute / MIT License
FIGFont created with: http://patorjk.com/figfont-editor */

  std::cout <<
    color("▄█████ ██  ██ ███  ██ ██████ ██  ██   "
    "▄█████ ▄████▄ ███  ██  ▄████\n", "brightCyan") <<
    color("▀▀▀▄▄▄  ▀██▀  ██ ▀▄██   ██   ██████   "
    "▀▀▀▄▄▄ ██  ██ ██ ▀▄██ ██  ▄▄▄\n","cyan") <<
    color("█████▀   ██   ██   ██   ██   ██  ██   "
    "█████▀ ▀████▀ ██   ██  ▀███▀\n\n","brightBlue") <<
    "=================================================="
    "================="
  << std::endl;

}

void askSynthType();
void askWaveType(std::string available);
void askNumOsc();
// void confirmSettings

// Function overloading
std::string getUserInput(
  std::string expectedType);
std::string getUserInput(
  std::string expectedType, float min, float max);
std::string getUserInput(
  std::string expectedType, float min, float max, bool constrainInput);
