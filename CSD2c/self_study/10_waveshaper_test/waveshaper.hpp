#pragma once
#include "effect.hpp"
#include "bufferTools.hpp"
#include "interpolation.hpp"

using namespace Interpolation, BufferTools;

struct Waveshaper : public Effect{
  Waveshaper(float dryWet, float kFactor);
  Waveshaper(float dryWet, float kFactor, int bufSize);

  void applyEffect(const float& input, float& output) override;

  ~Waveshaper();

private:
  int m_bufferSize;
  flat m_kFactor;
  float* m_buffer;
}
