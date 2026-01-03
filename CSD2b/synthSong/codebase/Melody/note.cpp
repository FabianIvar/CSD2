#include "note.h"

Note::Note(float _qNoteLength, float _midiPitch, float _midiVel)
 : qNoteLength(_qNoteLength), midiPitch(_midiPitch), midiVel(_midiVel) {
  #if DEBUG
    std::cout <<
      "Note Constructor"
    << std::endl;
  #endif
}

float Note::getQNoteLength() { return qNoteLength; }

float Note::getMidiPitch() { return midiPitch; }

float Note::getMidiVel() { return midiVel; }
