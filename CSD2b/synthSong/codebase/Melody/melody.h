#pragma once
#include <vector>
#include "note.h"
#include <cmath>
#include "../utils.h"

// using namespace std;
using namespace Utils;

class Melody {
  std::vector<Note> melody;
  // std::vector<int> timestamp;
  float samplerate;
  int noteIndex;
  int frameCount;
  int melodyLength;


public:
  Melody(int length, float _samplerate);
  bool tick();
  int lenToSamples(float QnoteValue);
  int getNoteSampleDur();
  float getNoteFrequency();
  float getNoteAmplitude();
};
