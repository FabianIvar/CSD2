#include "waveshaper.hpp"
#include "math.hpp"
#include <iostream>

Waveshaper::Waveshaper(float dryWet, float kFactor,
  int bufferSize) : Effect(dryWet), m_kFactor(kFactor),
    m_bufferSize(bufferSize) {

  generateSCurve();
  m_normalizeFactor = 1.0f / atan(m_kFactor);
}

Waveshaper::Waveshaper(float dryWet, float kFactor) :
  Waveshaper(dryWet, kFactor, 512) { }

Waveshaper::~Waveshaper() {
  free(m_buffer);
  std::cout <<
    "Waveshaper Destroyed"
  << std::endl;
}

void Waveshaper::generateSCurve() {
  m_buffer = allocate<float>(m_bufferSize);

  for(int i = 0; i < m_bufferSize; i++) {
    float x = bilinear<float>(
      static_cast<float>(i), 0.0f,
      static_cast<float>(m_bufferSize), -1.0f, 1.0f);
    m_buffer[static_cast<size_t>(i)] =
      normalizeFactor * atan(m_kFactor * x);
  }
}

void Waveshaper::applyEffect(
  const float &input, float &output) {
  float sample = input;
  if(sample > 1.0f) sample = 1.0f;
  if(sample < -1.0f) sample = -0.0f;

/* pseudo code waveshaper interpolatie

1) get floating point "index" in buffer
2) calculate remainder
  factor = remainder
  low = buffer[int(floatingPointIndex)]
  high = buffer[int(floatingPointIndex) + 1]
3) output = linear(factor, low, high)

*/

  float indexFloat = bilinear(
    sample, -1.0f, 1.0f, 0.0f, static_cast<float>(m_bufferSize - 1));
  int index = static_cast<int>(indexFloat);
  float remainder = indexFloat - index;

  output =

}
