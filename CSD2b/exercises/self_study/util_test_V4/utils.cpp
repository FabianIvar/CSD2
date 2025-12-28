// #include <iostream>
// #include <sstream>
#include "utils.h"
using namespace std;

std::string utils::color(std::string textInput, std::string color) {
  #if DEBUG
  std::cout << "utils::color" << std::endl;;
  #endif

  std::string ansiColors[14] = {
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
        ansiCode = to_string(31 + i);
      }
      else {
        // Starting from 90 are the bright variants of the colors
        ansiCode = to_string(90 + i);
      }
    }
  }

  std::string prefix = "\x1B[" + ansiCode + "m";
  std::string suffix = "\033[0m";
  std::string output = prefix + textInput + suffix;

  #if DEBUG
  std::cout << "outut: " << output << std::endl;
  #endif

  return output;
}

// NOTE: Should be vector
float utils::arrSum(float inputArray[], int start, int stop) {

    float output = 0;
    for (int i = start; i <= stop; i++) {
      output += inputArray[i];}

    return output;
}

// NOTE: Should be generic
template <typename C>
utils::constrain<C>::constrain(
  C &inputValue, C &minimum, C &maximum) {

  C output = std::min(*maximum, std::max(*minimum, *inputValue));
  this->output = &output;

  #if DEBUG
  std::cout <<
    "constrain constructor\n" <<
    "output: " << output <<
    "\nOf type: " << std::typeid(output).name()
  << std::endl;
  #endif
}

template <typename C>
Utils::constrain<C>::operator C() {

  #if DEBUG
  std::cout <<
    "Constrained value: " << frequency <<
    "\nOf type: " << std::typeid(*output).name();
  << std::endl;
  #endif

  return output;
}


// DONE
//============================================================================//

// mtof constructor definition
template<typename M>
Utils::mtof<M>::mtof(M& midiPitch) {
  this->midiPitch = &midiPitch;

  #if DEBUG
  std::cout <<
    "mtof constructor\n" <<
    "midiValue: " << midiPitch <<
    "\nOf type: " << std::typeid(midiPitch).name()
  << std::endl;
  #endif
}

// mtof conversion operator definition
template <typename M>
Utils::mtof<M>::operator M() {

  M frequency = 440.0 * std::pow(2.0, (*midiPitch - 69.0) / 12.0);

  #if DEBUG
  std::cout <<
    "Output frequency: " <<
    440.0 * std::pow(2.0, (*midiPitch - 69.0) / 12.0)
  << std::endl;;
  #endif

  return frequency;
}


// vtoa constructor definition
template<typename V>
Utils::vtoa<V>::vtoa(V midiVelocity) {
  this->midiVelocity = &midiVelocity;

  #if DEBUG
  std::cout <<
    "vtoa constructor\n" <<
    "midiVelocity: " << midiVelocity <<
    "\nOf type: " <<
    std::typeid(midiVelocity).name()
  << std::endl;
  #endif

}

// vtoa conversion operator definition
template <typename V>
Utils::vtoa<V>::operator V() {

  V amplitude = *midiVelocity / 127.0;

  #if DEBUG
    std::cout <<
      "Output amplitude: " << amplitude
    << std::endl;;
  #endif

  return amplitude;
}

int utils::noteSampleDur(
  double bpm, double qNotes, double sampleRate) {

  /* qNotes means the note length expressed as amount of quarter notes.
  lenQNotes = 2.0 means 2 quarter notes, so a half note.
  With a bpm of 120, a quarter note is: 60/ 120 = 0,5
  With a sampleRate of 44100 samples per second,
  The amount of samples in 0,5 seconds is 44100 * 0,5 = 22050 samples
  Calculation is done with doubles. Output = int */

  double calculation = ((60 / bpm) * qNotes) * sampleRate;

  #if DEBUG
  std::cout <<
    "Amount of samples: " << calculation <<
    "\nInformation loss after type_cast: " <<
    calculation - static_cast<int>(calculation) <<
  std::endl;
  #endif

  return static_cast<int>(calculation);
}



//============================================================================//



// functions that are no longer used
#if !EXCLUDE
double utils::velToAmp(int midiVel) {
  double amplitude = midiVel / 127;
  return amplitude;
}

template<typename T>
std::string utils::pToString(const T& pointer) {
  std::stringstream ss;
  ss << static_cast<void*>(pointer);
  return ss.str();
}
#endif
