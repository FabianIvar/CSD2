#pragma once

namespace Utils {

  template<typename V> struct Mtof {
    const V* midiPitch;

    Mtof(V &midiPitch){
      this->midiPitch = &midiPitch;
    }
    operator V() {
      V frequency = 440.0 * pow(
        2.0, (*midiPitch - 69.0) / 12.0);

      return frequency;
    }

  };
}
