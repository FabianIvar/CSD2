#pragma once

/* NOTE:
Duplicate code can probably be
prevented by overloading constructors
and putting everything inside the same class.
But that's out of scope for now. */

namespace Utils {

  // MIDI Pitch to Frequency
  template<typename M> struct mtof {

    M output;
    mtof(M midiPitch) {
      this->output = 440.0 * pow(
        2.0, (midiPitch - 69.0) / 12.0);;
    }
  };

  // MIDI Velocity to Amplitude
  template<typename V> struct vtoa {

    V output;
    vtoa(V midiVelocity) {
      this->output = midiVelocity / 127.0;
    }
  };

  // Constrain 'value' between 'min' and 'max'
  template<typename C> struct constrain {

    C output;
    constrain(C value, C min, C max) {
      this->output = std::min(
        max, std::max(min, value));
    }
  };

  // Sums values in a vector between 'start' and 'stop'
  template<typename S> struct vectorSum {

    S output;
    vectorSum(std::vector<S> vector, int start, int stop) {
      S summed = 0.0;

      for (int i = start; i < stop; i++) {
        summed += vector[i];
      }

      this->output = summed;
    }
  };

  // outputs string in selected color when printed by cout
  std::string color(
    std::string textInput,
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

  // Note length to amount of samples
  int lenToSamples(
    double qNotes,
    double sampleRate) {
    double calculation = ((60.0 / 120.0) * qNotes) * sampleRate;

    return static_cast<int>(calculation);
  }
}
