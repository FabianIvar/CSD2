#pragma once
#include <cmath>
#include "effect.hpp"
#include "../utils/bufferToolkit.hpp"
#include "../utils/interpolation.hpp"

using namespace Interpolation;
using namespace BufferToolkit;

#define DEBUG 1
#define LOG_SCURVE 0

struct Waveshaper : public Effect {
  Waveshaper(float dryWet, float kFactor, int bufferSize);
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
