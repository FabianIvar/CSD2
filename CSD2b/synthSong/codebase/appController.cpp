// appController handles UI and input and validation

#include <iostream>
#include "appController.h"
#include "utils.h"


void appController::displayTitlescreen() {
  std::cout <<
    Utils::color("▄█████ ██  ██ ███  ██ ██████ ██  ██   "
    "▄█████ ▄████▄ ███  ██  ▄████\n", "brightCyan") <<
    Utils::color("▀▀▀▄▄▄  ▀██▀  ██ ▀▄██   ██   ██████   "
    "▀▀▀▄▄▄ ██  ██ ██ ▀▄██ ██  ▄▄▄\n","cyan") <<
    Utils::color("█████▀   ██   ██   ██   ██   ██  ██   "
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
