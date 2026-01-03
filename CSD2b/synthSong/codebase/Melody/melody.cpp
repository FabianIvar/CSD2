#include "melody.h"

Melody::Melody(int length, float _samplerate)
  : noteIndex(0), frameCount(0), samplerate(_samplerate),
    melodyLength(length) {

  float summand = 0.0f;
  melody.push_back(Note(1.0f, 36.0f, 100.0f));

  for (int i = 0; i <= length; i++) {
    (i == 1 || i == 4) ? summand += 1.0f : summand += 2.0f;
    melody.push_back( Note( 1.0f, 36.0f + summand, 100.0f));
  }

  // std::vector<float> qNoteLengths;
  //
  // for (auto i : melody) {
  //   qNoteLengths.push_back(i.getQNoteLength());
  //   vectorSum sum(qNoteLengths, 0, qNoteLengths.size());
  //   timestamp.push_back( lenToSamples( sum.output));
  // }
}

bool Melody::tick() {
  frameCount++;

  if (frameCount >= getNoteSampleDur()) {
    noteIndex++;

    if (noteIndex >= melodyLength) {
      noteIndex = 0;
    }

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
  float qNoteLength = melody[noteIndex].getQNoteLength();
  return lenToSamples(qNoteLength);
}

float Melody::getNoteFrequency() {
  float midiPitch = melody[noteIndex].getMidiPitch();
  mtof m(midiPitch);
  return m.output;
}

float Melody::getNoteAmplitude() {
  double midiVel = melody[noteIndex].getMidiVel();
  vtoa v(midiVel);
  return v.output;
}

// 2, 1, 2, 2, 1, 2, 2
// Note(36.0f, 100.0f, 2.0f)
