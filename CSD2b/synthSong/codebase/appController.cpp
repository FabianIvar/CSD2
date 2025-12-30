// appController handles UI and input and validation

#include <iostream>
#include "appController.h"

std::string appController::color(std::string textInput,
  std::string color) {

  std::string ansiColors[] = {
    "red",
    "green",
    "yellow",
    "blue",
    "magenta",
    "cyan",
    "white",
    "brightBlack",
    "brightRed",
    "brightGreen",
    "brightYellow",
    "brightBlue",
    "brightMagenta",
    "brightCyan"
  };

  std::string ansiCode;

  for (int i = 0; i < 14; i++) {
    if (!(color.compare(ansiColors[i]))) {
      if (i <= 6) {
        // ANSI code 30 is black and not visable in the terminal
        ansiCode = std::to_string(31 + i);
      }
      else {
        // Starting from 90 are the bright variants of the colors
        ansiCode = std::to_string(83 + i);
      }
    }
  }

  std::string prefix = "\x1B[" + ansiCode + "m";
  std::string suffix = "\033[0m";
  std::string output = prefix + textInput + suffix;
  return output;
}

void appController::displayTitlescreen() {
  std::cout <<
    color("\n▄█████ ██  ██ ███  ██ ██████ ██  ██   "
    "▄█████ ▄████▄ ███  ██  ▄████\n", "brightCyan") <<
    color("▀▀▀▄▄▄  ▀██▀  ██ ▀▄██   ██   ██████   "
    "▀▀▀▄▄▄ ██  ██ ██ ▀▄██ ██  ▄▄▄\n","cyan") <<
    color("█████▀   ██   ██   ██   ██   ██  ██   "
    "█████▀ ▀████▀ ██   ██  ▀███▀\n\n","brightBlue") <<
    "=================================================="
    "================="
  << std::endl;

}

// void askSynthType();
// void askWaveType(std::string available);
// void askNumOsc();
// // void confirmSettings
//
// // Function overloading
// std::string getUserInput(
//   std::string expectedType);
// std::string getUserInput(
//   std::string expectedType, float min, float max);
// std::string getUserInput(
//   std::string expectedType, float min, float max, bool constrainInput);
