// appController handles UI and input and validation
#include "appController.h"

appCtrl::Compare comparator;

std::string appCtrl::color(std::string textInput,
  std::string color) {

// Asci skips asciCode 38 for some reason?
  std::string ansiColors[] = {
    "black",
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
    "brightCyan",
    "default"
  };

  std::string ansiCode;

  for (int i = 0; i < 16; i++) {
    if (!(color.compare(ansiColors[i]))) {
      if (i <= 7) {
        // ANSI code 30 is black and not visable in the terminal
        ansiCode = std::to_string(30 + i);
      }
      else {
        // Starting from 90 are the bright variants of the colors
        ansiCode = std::to_string(82 + i);
      }
    }
  }

  std::string prefix = "\x1B[" + ansiCode + "m";
  std::string suffix = "\033[0m";
  std::string output = prefix + textInput + suffix;
  return output;
}

void appCtrl::displayTitlescreen() {
  system("clear");
  std::cout <<
    color("\n▄█████ ██  ██ ███  ██ ██████ ██  ██   "
    "▄█████ ▄████▄ ███  ██  ▄████\n", "brightCyan") <<
    color("▀▀▀▄▄▄  ▀██▀  ██ ▀▄██   ██   ██████   "
    "▀▀▀▄▄▄ ██  ██ ██ ▀▄██ ██  ▄▄▄\n","cyan") <<
    color("█████▀   ██   ██   ██   ██   ██  ██   "
    "█████▀ ▀████▀ ██   ██  ▀███▀\n\n","brightBlue") <<
    color("==========================================="
    "========================", "black")
  << std::endl;
}

void appCtrl::questionSynthType() {
  std::cout<<
    color("\n-=<(", "brightBlack") <<
    color("Pick Synth Type", "brightCyan") <<
    color(")>=-\n\n", "brightBlack");
  strVec options = {"Additive Synth", "FM Synth"};
  strVec enumColor = {"brightBlack", "brightCyan", "brightBlack"};
  strVec optionColor = {"default","default"};
  displayOptions(options, enumColor, optionColor);
}

/* displayOptions displays an enumerated
   list of options the user can pick from */
void appCtrl::displayOptions(
  strVec options, strVec enumColor, strVec optionColor) {

  int optionIndex = 0;
  std::string optionIndexString;
  int enumIndex;

  strVec box = {"[", "x", "]"};
  for (auto i : optionColor) {
    box[1] = std::to_string(optionIndex);

    enumIndex = 0;
    for (auto j : enumColor) {
      std::cout << appCtrl::color(box[size_t(enumIndex)], j);
      enumIndex++;
    }

    std::cout << " " <<
      appCtrl::color(options[size_t(optionIndex)], i)
      << "\n";
    optionIndex++;
  }

  std::cout << std::endl;


  intVec validInput;
  for (int i = 0; i < int(options.size()); i++) validInput.push_back(i);
  comparator.setValidIntegers(validInput);
}

/* takes a vector<int> as input, casts the values inside
   the vector to type string, stores the strings inside a
   new vector and assignes this vector to the
   member-variable 'validIntInput' inside the 'Compare'
   class */
void appCtrl::Compare::setValidIntegers(
  std::vector<int> values) {
  strVec valuesAsString;
  for (auto i : values) valuesAsString.push_back(std::to_string(i));
  this->validIntegers = valuesAsString;
}

/* returns the vector<string> which is a vector that
   contains every valid integer as a string */
appCtrl::strVec appCtrl::Compare::getValidIntegers() {
  return validIntegers;
}

int appCtrl::getValidIntInput() {
  strVec validInts = comparator.getValidIntegers();
  bool notValid = true;
  std::string input;

  while(notValid) {
    std::cout << color(">> ", "brightCyan");
    std::cin >> input;
    if (std::find(validInts.begin(), validInts.end(), input)
      != validInts.end()) {
      notValid = false;
    }
    else
      std::cout <<
        appCtrl::color("\nInput not valid","red") <<
        appCtrl::color(" (expected ","red") <<
        appCtrl::color("int","brightRed") <<
        appCtrl::color("), try again\n", "red")
      << std::endl;
  }
  return std::stoi(input);
}
