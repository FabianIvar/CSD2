#pragma once
#include <cmath>
#include "effect.hpp"
#include "bufferTools.hpp"
#include "interpolation.hpp"

using namespace Interpolation
using namespace BufferTools;

struct Waveshaper : public Effect{
  Waveshaper(float dryWet, float kFactor);
  Waveshaper(float dryWet, float kFactor, int bufSize);
  ~Waveshaper();

  void generateSCurve();

  void applyEffect(const float& input, float& output) override;


private:
  float m_normalizeFactor;
  int m_bufferSize;
  flat m_kFactor;
  float* m_buffer;
}
