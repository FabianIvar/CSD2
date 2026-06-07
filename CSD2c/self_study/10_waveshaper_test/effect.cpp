#include "effect.hpp"
#include <iostream>

Effect::Effect() : m_dryWet(1.0f), m_bypass(false) { }

Effect::Effect(float dryWet) :
  m_dryWet(dryWet), m_bypass(false) { }

Effect::Effect(float dryWet, bool bypass) :
  m_dryWet(dryWet), m_bypass(bypass) { }

Effect::~Effect() {
  #if DEBUG
    std::cout << "Effect Destroyed" << std::endl;
  #endif
}

void Effect::prepare(float samplerate) :
  m_samplerate(samplerate) { }

void Effect::processFrame(const float& input, float& output) {
  if (m_bypass != true) {
    applyEffect(input, output);
    output = input * (1.0f - m_dryWet) + output * m_dryWet;
    m_sample = output;
  }

float Effect::getSample() { return m_sample; }

void Effect::setDryWet(float dryWet) { m_dryWet = dryWet; }

// applyEffect is a pure virtual function
}
