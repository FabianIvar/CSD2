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

  output = y; // normalize

  // std::cout << "----[ y * 1/amp ]-----> " << y*1.0f/m_amplitude << std::endl;
  // std::cout << "----[ output - input ]-----> " << output - input << std::endl;
  // std::cout <<
  //   " a0: " << a0 << " a1: " << a1 << " a2: " << a2 <<
  //   "\n b0: " << b0 << " b1: " << b1 << " b2: " << b2 <<
  //   "\n xn_1: " << xn_1 << " xn_2: " << xn_2 <<
  //   "\n yn_1: " << yn_1 << " yn_2: " << yn_2 <<
  //   "\n\n output - input = " << y - input
  // << std::endl;
}

void Filter::calculateCoefficients() {
// cutoff frequency in Hz, qFactor as a value between 0 and 1

  float w0 = (2.0f*M_PI * m_cutoff) / m_samplerate;
  float cosw0 = cos(w0);
  float sinw0 = sin(w0);
  float alpha = sinw0 / (2.0f * m_qFactor);
  m_amplitude = pow(10.0f, m_dBgain * 0.025f);
  // std::cout << "amplitude1: " << pow(10.0f, 1.0f * 0.025f) << "\n" << std::endl;
  // std::cout << "amplitude2: " << pow(10.0f, 2.0f * 0.025f) << "\n" << std::endl;
  // std::cout << "amplitude3: " << pow(10.0f, 3.0f * 0.025f) << "\n" << std::endl;
  // std::cout << "amplitude4: " << pow(10.0f, 4.0f * 0.025f) << "\n" << std::endl;
  // std::cout << "actual amplitude: " << m_amplitude << "\n" << std::endl;

// coefficients
  a0 = 1.0f + alpha * m_amplitude;
  a1 = -2.0f * cosw0;
  a2 = 1.0f - alpha * m_amplitude;
  b0 = 1.0f + alpha / m_amplitude;
  b1 = -2.0f * cosw0;
  b2 = 1.0f - alpha / m_amplitude;

  std::cout << a0 <<
    ",\n" << a1 <<
    ",\n" << a2 <<
    ",\n" << b0 <<
    ",\n" << b1 <<
    ",\n" << b2
  << std::endl;

}
