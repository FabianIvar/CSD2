#pragma once
#include <cmath>
#include "effect.hpp"
#include "../utils/bufferToolkit.hpp"
#include "../utils/interpolation.hpp"

using namespace Interpolation;
using namespace BufferToolkit;

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
