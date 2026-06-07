#include "effect.hpp"
#include <iostream>

Effect::Effect() : Effect(1.0f, false) { }

Effect::Effect(float dryWet) : Effect(dryWet, 1.0f) { }

Effect::Effect(float dryWet, bool bypass) : m_bypass(bypass) {
  setDryWet(dryWet);
}

Effect::~Effect() {
  #if DEBUG
    std::cout << "Effect Destroyed" << std::endl;
  #endif
}

void Effect::processFrame(const float& input, float& output) {
  if (m_bypass != true) {
    applyEffect(input, output);
    output = input * (1.0f - m_dryWet) + output * m_dryWet;
    m_sample = output;
  }
  else m_sample = input;
}

float Effect::getSample() { return m_sample; }

void Effect::setDryWet(float dryWet) {
  if (dryWet < 0.0f) m_dryWet = 0.0f;
  else if (dryWet > 1.0f) m_drywet = 1.0f;
  else m_dryWet = dryWet;
}

// applyEffect is a pure virtual function
}
