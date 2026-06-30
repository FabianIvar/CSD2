// by Fabean 29/06/26

#include <iostream>
#define DEBUG 0

struct Smoothing {
  Smoothing(float samplerate, float ms) :
    m_samplerate(samplerate), m_smoothing(false) {
    #if DEBUG
      std::cout << "Smoothing Constructor" << std::endl;
    #endif

    msToSamples(ms);
  }

  ~Smoothing() {
    #if DEBUG
      std::cout << "Smoothing Destroyed" << std::endl;
    #endif
  }

  void setTargetValue(float parameter) {
    m_targetValue = parameter;
    if (m_targetValue < 0.0f) m_targetValue = 0.0f;
    m_distance = m_targetValue - m_currentValue;
    m_delta = m_distance / m_time;
    if (m_delta < 0.0f) m_delta *= -1.0f;
    m_smoothing = true;
  }

  float getNextValue() {
    if (m_smoothing) {
      if (m_currentValue < m_targetValue) {
        m_currentValue += m_delta;
      }
      else if (m_currentValue > m_targetValue) {
        m_currentValue -= m_delta;
      }
      else m_smoothing = false;
    }
    return m_currentValue;
  }

  void reset(float ms) {
    msToSamples(ms);
  }

private:
  void msToSamples(float ms) {m_time = m_samplerate * 0.001f * ms;}

  float m_samplerate;
  float m_currentValue;
  float m_targetValue;
  float m_distance;
  float m_delta;
  float m_time; // time in samples
  bool m_smoothing;
};
