#include "melody.h"

Melody::Melody(int length, float _samplerate)
  : samplerate(_samplerate), noteIndex(0),
    frameCount(0),
    melodyLength(length) {

  float summand = 0.0f;
  melody.push_back(Note(1.0f, 36.0f, 100.0f));

  for (int i = 0; i <= length; i++) {
    (i == 1 || i == 4) ? summand += 1.0f : summand += 2.0f;
    melody.push_back( Note( 1.0f, 36.0f + summand, 100.0f));
  }
}

bool Melody::tick() {

  frameCount++;

  if (frameCount >= getNoteSampleDur()) {
    noteIndex++;

    if (noteIndex > melodyLength) noteIndex = 0;
    frameCount = 0;
    return true;
  }
  return false;
}

int Melody::lenToSamples(float qNoteValue) {
  double calculation = ((60.0 / 120.0) * qNoteValue) * samplerate;

  return static_cast<int>(calculation);
}

int Melody::getNoteSampleDur() {
  float qNoteLength = melody[size_t(noteIndex)].getQNoteLength();
  return lenToSamples(qNoteLength);
}

float Melody::getNoteFrequency() {
  float midiPitch = melody[size_t(noteIndex)].getMidiPitch();
  mtof m(midiPitch);
  return m.output;
}

float Melody::getNoteAmplitude() {
  float midiVel = melody[size_t(noteIndex)].getMidiVel();
  vtoa v(midiVel);
  return v.output;
}
