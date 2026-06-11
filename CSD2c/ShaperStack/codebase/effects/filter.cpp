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

  output = y;
}
