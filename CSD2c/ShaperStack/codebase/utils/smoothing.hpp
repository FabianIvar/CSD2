#include <iostream>
#define DEBUG 1

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
    m_distance = m_targetValue - m_currentValue;
    m_delta = m_distance / m_time;
    m_smoothing = true;
  }

  float getNextValue() {
    if (m_smoothing) {
      m_currentValue += m_delta;
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


/*


setTargetValue();
getNextValue();
reset(samplerate, ms)


currentValue
targetValue
distance
delta = distance / [ time ]-->( in samples )
currentValue += delta
bool isSmoothing = false

*/
