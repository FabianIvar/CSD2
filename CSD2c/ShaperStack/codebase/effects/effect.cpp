#include "effect.hpp"
#include <iostream>

Effect::Effect() : Effect(1.0f, false) { }

Effect::Effect(float dryWet) : Effect(dryWet, false) { }

Effect::Effect(float dryWet, bool bypass) : m_bypass(bypass) {
  setDryWet(dryWet);
  #if DEBUG
    std::cout << "Effect Constructor" << std::endl;
  #endif
}

Effect::~Effect() {
  #if DEBUG
    std::cout << "Effect Destroyed" << std::endl;
  #endif
}

void Effect::processFrame(const float& input, float& output) {
  if (m_bypass == false) {
    float sampl;
    applyEffect(input, sampl);
    m_sample = sampl * m_dryWet + input * (1.0f - m_dryWet);
    output = m_sample; // used to be sampl <-- check if it still works
  }
  else m_sample = input;
}

float Effect::getSample() { return m_sample; }

void Effect::setDryWet(float dryWet) {
  if (dryWet < 0.0f) m_dryWet = 0.0f;
  else if (dryWet > 1.0f) m_dryWet = 1.0f;
  else m_dryWet = dryWet;
}
