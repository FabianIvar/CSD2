#include "filter.hpp"

Filter::Filter(float dryWet, float cutoff, float qFactor, float dBgain,
  float samplerate) : Effect(dryWet), m_samplerate(samplerate), m_cutoff(cutoff), m_qFactor(qFactor), m_dBgain(dBgain) {

  #if DEBUG
    std::cout << "Filter Constructor" << std::endl;
  #endif

  calculateCoefficients();
}

Filter::~Filter() {
  #if DEBUG
    std::cout << "Filter Destroyed" << std::endl;
  #endif
}

void Filter::applyEffect(const float& input, float& output) {
  float x = input;
  float y = (a0/b0)*x + (a1/b0)*xn_1 +
    (a2/b0)*xn_2 - (b1/b0)*yn_1 - (b2/b0)*yn_2;

  xn_2 = xn_1;
  xn_1 = x;
  yn_2 = yn_1;
  yn_1 = y;

  if (y > 1.0f) y = 1.0f;
  else if (y < -1.0f) y = -1.0f;
  else output = y;
}

void Filter::calculateCoefficients() {

// cutoff frequency in Hz
  float w0 = (2.0f*M_PI * m_cutoff) / m_samplerate;
  float cosw0 = cos(w0);
  float sinw0 = sin(w0);
  float alpha = sinw0 / (2.0f * m_qFactor);
  m_amplitude = pow(10.0f, m_dBgain * 0.025f);

// coefficients
  a0 = 1.0f + alpha * m_amplitude;
  a1 = -2.0f * cosw0;
  a2 = 1.0f - alpha * m_amplitude;
  b0 = 1.0f + alpha / m_amplitude;
  b1 = -2.0f * cosw0;
  b2 = 1.0f - alpha / m_amplitude;

  #if DEBUG
    std::cout << a0 <<
      ",\n" << a1 <<
      ",\n" << a2 <<
      ",\n" << b0 <<
      ",\n" << b1 <<
      ",\n" << b2
    << std::endl;
  #endif

}
