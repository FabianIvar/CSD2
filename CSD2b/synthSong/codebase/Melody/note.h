#pragma once

#define DEBUG 0

#if DEBUG
#include <iostream>
#endif

struct Note {
  Note(float QNoteLength,
    float midiPitch, float midiVel);

  // getters
  float getQNoteLength();
  float getMidiPitch();
  float getMidiVel();
private:
  float qNoteLength;
  float midiPitch;
  float midiVel;
};
