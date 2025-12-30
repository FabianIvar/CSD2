#pragma once
#define EXCLUDE 1

/* NOTE:
Duplicate code can probably be
prevented by overloading constructors
and putting everything inside the same class.
But that's out of scope for now. */

namespace Utils {

  // MIDI Pitch to Frequency
  template<typename M> struct mtof {

    static M output;
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

  // Deletes objects stored in a vector and assigns nullptr
  template <typename E> struct entity_deleter {

    /* Source - https://stackoverflow.com/a
    Posted by rlbond, modified by community.
    Retrieved 2025-12-29, License - CC BY-SA 2.5 */

    void operator()(E*& entity) {
      delete entity;
      entity = nullptr;
    }
  };

  #if !EXCLUDE
  // Note length to amount of samples
  static int lenToSamples(
    double qNotes,
    double sampleRate) {
    double calculation = ((60.0 / 120.0) * qNotes) * sampleRate;

    return static_cast<int>(calculation);
  }
  #endif
}
