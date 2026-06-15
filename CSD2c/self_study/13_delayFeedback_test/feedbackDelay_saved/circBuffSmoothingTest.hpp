#pragma once
#include "../utils/interpolation.hpp"
#include "../utils/bufferToolkit.hpp"

#define DEBUG 1

using namespace BufferToolkit;
using namespace Interpolation;

struct CircularBuffer {

  CircularBuffer(uint size, float distRW);
  ~CircularBuffer();

  void resetSize(uint size); // do I really need this?
  float getDistRW();
  uint getSize();
  void allocateBuffer();
  void releaseBuffer();

  inline void prepareParam(float parameter) {

    m_currentValue = linear<float>(parameter, msToSamples(150.0f, m_samplerate), msToSamples(1000.0f, m_samplerate));
    float targetValue = 48000.0f * parameter;
    m_difference = targetValue - m_currentValue;
    m_storedValue = m_currentValue;

    m_valueIncrement = 0.00005;
    m_line = 0.0f;

    m_smoothingEnabled = true;
  }

  inline void smootheValue() {
    if (m_smoothingEnabled) {
      m_line += m_valueIncrement;
      m_currentValue = m_storedValue + m_line * m_difference;

      if (m_line >= 1.0f) {
        m_line = 0.0f;
        m_smoothingEnabled = false;
      }
    }
  }

  inline void calculateGrainIncrement() { // calculatePhaseStep
    m_grainIncrement = 1.0f/m_currentValue;
  }

  inline void incrSummandFactor() {
    for (int i = 0; i < 2; i++) {
      m_summandFactor[i] += m_grainIncrement;
      wrap(m_summandFactor[i]);
    }
  }

  inline void calcReadHSummand() {
    for (int i = 0; i < 2; i++) {
      m_summand[i] = m_summandFactor[i] * m_currentValue * 2;
    }
  }

  inline void setCurrentValue(float value) {
    m_currentValue = value;
    calculateGrainIncrement();
  }

  inline void setDistRW(float distance) {
    if (distance < 1.0f) distance = 1.0f;
    else if (distance > m_size) distance = m_size;

    m_distRW = distance;

    for (int i = 0; i < 2; i++) {
      m_readH[i] = m_writeH - m_distRW + m_summand[i];
      wrap(m_readH[i]);
    }
  }

  inline void tick() {
    incrReadH();
    incrWriteH();
    incrSummandFactor();
  }

  inline float read() {
    float output = 0.0f;
    for (int i = 0; i < 2; i++) {
      int low = static_cast<int>(m_readH[i]);
      float high = m_readH[i] + 1.0f;
      wrap(high);
      float remainder = m_readH[i] - low;
      output += linear<float>(
        remainder, readAtIndex(low), readAtIndex(high)) *
        getGrainAmplitude(m_summandFactor[i]);
    }

    std::cout << "output: " << output << std::endl;
    return output;

  }

  inline void write(float value) {
    m_buffer[static_cast<int>(m_writeH)] = value;
  }

  private:

  inline void incrReadH() {
    for (int i = 0; i < 2; i++) {
      m_readH[i]++;
      wrap(m_readH[i]);
    }
  }

  inline void incrWriteH() {
    m_writeH++;
    wrap(m_writeH);
  }

  inline void wrap(float& head) { // can heads reach highest index in buffer?

    if (head >= static_cast<float>(m_size)) head -= static_cast<float>(m_size);
    else if (head < 0.0f) head -= static_cast<float>(m_size);

  }

  float getGrainAmplitude(float factor) {
    if (factor < 0.5f) return linear(factor, 0.0f, 1.0f);
    else if (factor > 0.5f) return linear(factor, 1.0f, 0.0f);
    else return 0.5f;
  }

  inline float readAtIndex(float index) {
    float remainder = index - static_cast<int>(index);
    float high = index + 1.0f;
    wrap(high);
    return linear<float>(remainder, m_buffer[static_cast<int>(index)],
      m_buffer[static_cast<int>(high)]);
  }

    float m_summandFactor[2] = {0.0f, 0.5f};
    float m_summand[2] = {0.0f, 0.0f};
    float m_currentValue;
    float m_line;

    bool m_smoothingEnabled;
    float m_valueIncrement;
    float m_grainIncrement;
    float m_difference;

    float* m_buffer;
    uint m_size;
    float m_readH[2] = {0.0f, 0.0f};
    float m_writeH;
    float m_distRW;
    float m_storedValue;
    float m_samplerate;

};


/*

void prepareParam(float parameter) { // calculateGrainStep

  m_currentValue = value * "multiplier --> replace this";
  targetValue = value * parameter;
  m_storedValue = m_currentValue;

  m_difference = targetValue - m_currentValue;
  m_valueIncrement = 0.00005;
  m_line = 0.0f;

  m_smoothingEnabled = true;
}

void smootheValue() {
  if (smoothingEnabled) {
    m_line += m_valueIncrement;
    m_currentValue = m_storedValue + m_line * m_difference;

    if (m_line >= 1.0f) {
      m_line = 0.0f;
      m_smoothingEnabled = false;
    }
  }
}

void calculateGrainIncrement() { // calculatePhaseStep
  m_grainIncrement = 1.0f/m_currentValue;
}

void incrSummandFactor() {
  for (int i = 0; i < 2; i++) {
    summandFactor[i] += m_grainIncrement;
    wrap(summandFactor[i]);
  }
}

void calcReadHSummand() {
  for (int i = 0; i < 2; i++) {
    summand[i] = summandFactor[i] * m_currentValue * 2;
  }
}

void setCurrentValue(float value) {
  m_currentValue = value;
  calculateGrainIncrement();
}

void setDistRW(float distance) {
  if (distance < 1.0f) distance = 1.0f;
  else if (distance > m_size) distance = m_size;

  m_distRW = distance;

  for (int i = 0; i < 2; i++) {
  m_readH[i] = m_writeH - m_distRW + m_summand[i]
  wrap(m_readH[i]);
  }
}

void tick() {
incrReadH();
incrWriteH();
incrSummandFactor();
}

private:

void incrReadH() {
  for (int i = 0; i < 2; i++) {
    m_readH[i]++;
    wrap(m_readH);
  }
}

void incrWriteH() {
  m_writeH++;
  wrap(m_writeH);
}

inline void wrap(float& head) { // can heads reach highest index in buffer?

  if (head >= static_cast<float>(m_size)) head -= static_cast<float>(m_size);
  else if (head < 0.0f) head -= static_cast<float>(m_size);

}

float getGrainAmplitude(float grain) {
  if (grain < 0.5f) return linear(grain, 0.0f, 1.0f);
  else if (grain > 0.5f) return linear(grain, 1.0f, 0.0f);
  else return 0.5f;
}

inline float read() {
  float output = 0.0f;
  for (int i = 0; i < 2; i++) {
    int low = static_cast<int>(m_readH[i]);
    float high = m_readH[i] + 1.0f;
    wrap(high);
    float remainder = m_readH[i] - low;
    output += linear<float>(
      remainder, readAtIndex(low), readAtIndex(high)]) *
      getGrainAmplitude(summandFactor[i]);
  }

  return output

}

  float m_summandFactor[2] = {0.0f, 0.5f};
  float m_summand[2] = {0.0f, 0.0f};
  float m_currentValue;
  float m_line;

  bool m_smoothingEnabled;
  float m_valueIncrement;
  float m_difference;

  float* m_buffer;
  uint m_size;
  float m_readH[2] = {0.0f, 0.0f};
  float m_writeH;
  float m_distRW;
  float m_storedValue;

*/






// die envelope is een array van 1024 waarden die van 0 naar 1 naar 0 gaan
