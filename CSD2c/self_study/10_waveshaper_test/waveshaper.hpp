#pragma once
#include <cmath>
#include "effect.hpp"
#define DEBUG 1

struct Waveshaper : public Effect {
  Waveshaper(float dryWet, float kFactor, int bufSize);
  Waveshaper(float dryWet, float kFactor);
  ~Waveshaper();

  void generateSCurve();

  void applyEffect(const float& input, float& output) override;
  void setKFactor(float kFactor);


private:
  int m_bufferSize;
  float m_kFactor;
  float* m_buffer;
};
