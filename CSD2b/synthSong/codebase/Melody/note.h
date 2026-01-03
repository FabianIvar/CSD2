#pragma once

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
