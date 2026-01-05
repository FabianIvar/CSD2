// appController handles UI and input and validation
// For documentation, see "appController.h"

#include "appController.h"

appCtrl::Compare comparator;

// Applies color to string printed by cout
std::string appCtrl::color(std::string textInput,
  std::string color) {

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
        // ANSI codes 1 to 7 are the non-bright variants of the colors.
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
  /*
  Font Author: Loic Cressot
  This font is free to use and distribute / MIT License
  FIGFont created with: http://patorjk.com/figfont-editor
  */

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

void appCtrl::displayStartMessage() {
  std::cout << "\nPress " <<
    color("s + Enter ", "brightCyan") + "to start\n"
  << std::endl;

  bool hasStarted = false;
  while(!hasStarted) {
    if (std::cin.get() == 's') hasStarted = true;
    else std::cout << color(">> ", "brightCyan");
  }
  std::cout << std::endl;
}

void appCtrl::displayQuitMessage() {
  std::cout << "Press " <<
    appCtrl::color("q + Enter","red") + " to quit\n"
  << std::endl;

  bool running = true;
  while (running) {
    if (std::cin.get() == 'q') running = false;
    else std::cout << color(">> ", "brightCyan");
  }
}

void appCtrl::displayQuestion(std::string question) {
  std::cout<<
    color("\n-=<(", "brightBlack") <<
    color(question, "brightCyan") <<
    color(")>=-\n\n", "brightBlack");
}

void appCtrl::questionSynthType() {
  appCtrl::displayQuestion("Pick Synth Type");
  strVec options = {"Additive Synth", "FM Synth"};
  strVec numboxColor = {"brightBlack", "brightCyan", "brightBlack"};
  strVec optionColor = {"default", "default"};
  displayOptions(options, numboxColor, optionColor);
}

void appCtrl::questionWaveType(std::string question) {
  appCtrl::displayQuestion(question);
  strVec options = {"Sine", "Square", "Saw"};
  strVec numboxColor = {"brightBlack", "brightCyan", "brightBlack"};
  strVec optionColor = {"default", "default", "default"};
  displayOptions(options, numboxColor, optionColor);
}

void appCtrl::displayOptions(
  strVec options, strVec numboxColor, strVec optionColor) {

  int optionIndex = 0;
  int numboxIndex;

  strVec numbox = {"[", "x", "]"};
  for (auto i : optionColor) {
    numbox[1] = std::to_string(optionIndex);

    numboxIndex = 0;
    for (auto j : numboxColor) {
      std::cout << appCtrl::color(numbox[size_t(numboxIndex)], j);
      numboxIndex++;
    }

    std::cout << " " <<
      appCtrl::color(options[size_t(optionIndex)], i)
      << "\n";
    optionIndex++;
  }

  std::cout << "\n";

  intVec validInput;
  for (int i = 0; i < int(options.size()); i++) validInput.push_back(i);
  comparator.setValidIntegers(validInput);
}

void appCtrl::questionValInBounds(std::string question,
  std::string lowerBound, std::string upperBound) {

  displayQuestion(question);
  strVec boundsAsString = {lowerBound, upperBound};
  strVec boxColor = {"brightBlack","brightCyan","brightBlack",
    "brightCyan","brightBlack"};
  std::string promptColor = "default";
  displayBounds(boundsAsString, boxColor, promptColor);
}

void appCtrl::displayBounds(
  strVec boundsAsString, strVec boxColor, std::string promptColor) {

  strVec box = {"[","x","-","x","]"};

  box[1] = boundsAsString[0];
  box[3] = boundsAsString[1];

  int boxIndex = 0;
  for (auto i : boxColor) {
    std::cout << appCtrl::color(box[size_t(boxIndex)], i);
    boxIndex++;
  }
  std::cout <<
    appCtrl::color(" Enter Value within bounds\n", promptColor)
  << std::endl;
  floatVec bounds = {std::stof(boundsAsString[0]),
     std::stof(boundsAsString[1])};
  comparator.setValidFloats(bounds);
}

void appCtrl::Compare::setValidIntegers(std::vector<int> values) {
/* takes a vector<int> as input, casts the values inside
   the vector to type string, stores the strings inside a
   new vector and assignes this vector to the
   member-variable 'validIntInput' inside the 'Compare'
   class. */
  strVec valuesAsString;
  for (auto i : values) valuesAsString.push_back(std::to_string(i));
  this->validIntegers = valuesAsString;
}

void appCtrl::Compare::setValidFloats(std::vector<float> values) {
  this->validFloats = values;
}

appCtrl::strVec appCtrl::Compare::getValidIntegers() {
/* returns the vector<string> which is a vector that
   contains every valid integer as a string */
  return validIntegers;
}

std::vector<float> appCtrl::Compare::getValidFloats() {
/* returns the vector<float> which contains two float values
   representing the lowerbound and the upperbound. All float
   values between these bounds are valid. */
  return validFloats;
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
        appCtrl::color("\nInput not valid (expected ","red") <<
        appCtrl::color("int","brightRed") <<
        appCtrl::color("), try again\n", "red")
      << std::endl;
  }
  return std::stoi(input);
}

float appCtrl::getValidValInput(std::string expectedType) {
  floatVec validFloat = comparator.getValidFloats();
  bool notValid = true;
  std::string input;

  while(notValid) {
    std::cout << color(">> ", "brightCyan");
    std::cin >> input;

    try {
      std::stof(input);
    }
    catch (std::invalid_argument) {
      std::cout <<
        appCtrl::color("\n'" + input + "' "
          "not valid (expected ", "red") <<
        appCtrl::color(expectedType,"brightRed") <<
        appCtrl::color("), try again\n", "red")
      << std::endl;
      continue;
    }

    float floatInput = std::stof(input);

    if (floatInput >= validFloat[0] &&
      floatInput <= validFloat[1]) {
      notValid = false;
    }
    else {
      std::cout <<
        appCtrl::color("\nInput out of bounds"
        " try again\n", "red")
      << std::endl;
    }
  }
  return std::stof(input);
}
