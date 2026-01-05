#pragma once

struct Note {
  Note(float QNoteLength,
       float midiPitch,
       float midiVel);
  float getQNoteLength();
  float getMidiPitch();
  float getMidiVel();
private:
  float qNoteLength;
  float midiPitch;
  float midiVel;
};
