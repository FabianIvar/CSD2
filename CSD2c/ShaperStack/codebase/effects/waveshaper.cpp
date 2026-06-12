#include "waveshaper.hpp"
#include <iostream>

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
  #if LOG_SCURVE
    logArray<float>(m_buffer, 512, "S-Curve buffer");
  #endif
}

void Waveshaper::applyEffect(
  const float &input, float &output) {
  float sample = input;
  if(input > 1.0f) output = 1.0f;
  else if(input < -1.0f) output = -1.0f;
  else {
    float indexFloat = bilinear<float>(
      sample, -1.0f, 1.0f, 0.0f, static_cast<float>(m_bufferSize));

    int index = static_cast<int>(indexFloat);
    float remainder = indexFloat - index;
    float low = static_cast<float>(m_buffer[index]);
    float high;
    if (index < 512) {
      high = static_cast<float>(m_buffer[index + 1]);
    }
    else high = low;

    output = linear<float>(remainder, low, high);
  }
}

void Waveshaper::setKFactor(float kFactor) {m_kFactor = kFactor; }

/* pseudo code waveshaper interpolatie

1) get floating point "index" in buffer
2) calculate remainder
  factor = remainder
  low = buffer[int(floatingPointIndex)]
  high = buffer[int(floatingPointIndex) + 1]
3) output = linear(factor, low, high)

*/
