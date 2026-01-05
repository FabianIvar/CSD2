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

    M output;
    mtof(M midiPitch) {
      M referencePitch = 440.0;
      M exponent = 2.0;
      M subtrahend = 69.0;
      M devisor = 12.0;
      this->output = referencePitch * pow(
        exponent, (midiPitch - subtrahend) / devisor);
    }
  };

  // MIDI Velocity to Amplitude
  template<typename V> struct vtoa {

    V output;
    vtoa(V midiVelocity) {
      V devisor = 127.0;
      this->output = midiVelocity / devisor;
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

  // Unused functions
  #if !EXCLUDE

  // Constrain 'value' between 'min' and 'max'
  template<typename C> struct constrain {

    C output;
    constrain(C value, C min, C max) {
      this->output = std::min(
        max, std::max(min, value));
    }
  };

  #endif
}
