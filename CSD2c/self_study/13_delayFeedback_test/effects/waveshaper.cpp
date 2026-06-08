#include "waveshaper.hpp"
#include <iostream>
#include "../utils/bufferTools.hpp"
#include "../utils/interpolation.hpp"

using namespace Interpolation;
using namespace BufferTools;

Waveshaper::Waveshaper(float dryWet, float kFactor,
  int bufferSize) : Effect(dryWet), m_kFactor(kFactor),
    m_bufferSize(bufferSize) {

  #if DEBUG
    std::cout <<
      "Waveshaper Constructor"
    << std::endl;
  #endif

  generateSCurve();
}

Waveshaper::Waveshaper(float dryWet, float kFactor) :
  Waveshaper(dryWet, kFactor, 512) { }

Waveshaper::~Waveshaper() {
  free(m_buffer);
  #if DEBUG
    std::cout <<
      "Waveshaper Destroyed"
    << std::endl;
  #endif
}

void Waveshaper::generateSCurve() {
  m_buffer = allocate<float>(m_bufferSize);
  float normalizeFactor = 1.0f / atan(m_kFactor);

  for(int i = 0; i < m_bufferSize; i++) {
    float x = bilinear<float>(
      static_cast<float>(i), 0.0f,
      static_cast<float>(m_bufferSize), -1.0f, 1.0f);
    m_buffer[i] = normalizeFactor * atan(m_kFactor * x);
  }
  #if DEBUG
    logArray<float>(m_buffer, 512, "S-Curve buffer");
  #endif
}

void Waveshaper::applyEffect(
  const float &input, float &output) {
  float sample = input;
  if(sample > 1.0f) sample = 1.0f;
  if(sample < -1.0f) sample = -1.0f;

/* pseudo code waveshaper interpolatie

1) get floating point "index" in buffer
2) calculate remainder
  factor = remainder
  low = buffer[int(floatingPointIndex)]
  high = buffer[int(floatingPointIndex) + 1]
3) output = linear(factor, low, high)

*/

  float indexFloat = bilinear<float>(
    sample, -1.0f, 1.0f, 0.0f, static_cast<float>(m_bufferSize - 1));

  int index = static_cast<int>(indexFloat);
  float remainder = indexFloat - index;
  float low = static_cast<float>(m_buffer[static_cast<size_t>(index)]);
  float high = static_cast<float>(m_buffer[static_cast<size_t>(index + 1)]);

  output = linear<float>(remainder, low, high);

}

void Waveshaper::setKFactor(float kFactor) {m_kFactor = kFactor; }
