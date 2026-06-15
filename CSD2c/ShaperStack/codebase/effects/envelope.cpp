#include <iostream>
#include "envelope.hpp"
#include "utils/interpolation.hpp"

using namespace Interpolation;

Envelope::Envelope(float samplerate, float attack, float decay, float release) : m_samplerate(samplerate), m_factor(0.0f), m_toggle(true) {

  m_part = 0;
  m_attack = attack;
  m_decay = decay;
  m_release = release;

  calcIncrement(attack);

  #if DEBUG
    std::cout << "Envelope Constructor" << std::endl;
  #endif
}

Envelope::~Envelope() {
  #if DEBUG
    std::cout << "Envelope Destroyed" << std::endl;
  #endif
}

float Envelope::getAmplitude() {
  if (m_amplitude > 1.0f || m_amplitude < 0.0f) {
    return 0.0f;
    std::cout << "something went wrong" << std::endl;
  }
  else return m_amplitude;
}

void Envelope::setAmplitude(float amplitude) {
  m_amplitude = amplitude;
}

void Envelope::tick() {
  float adr[3] = {m_attack, m_decay, m_release};

  if (m_toggle == true) {
    if ((m_factor + m_factorIncrement) <= 1.0f) {
      float amp = linear<float>(m_factor, m_target[m_part], m_target[m_part+1]);
      setAmplitude(amp);
      m_factor += m_factorIncrement;
    }
    else if (m_part < 3) { // 0, 1, 2 = OKAY
      m_factor = 0.0f;
      m_part++;
      std::cout << "\n---> part [" << m_part << "]" << std::endl;
      calcIncrement(adr[m_part]);
    }
    else {
      m_toggle = false;
      std::cout << "\n---> finished!" << std::endl;
    }
  }
}

void Envelope::calcIncrement(float lengthMs) {

/* pseudo code

bijv 15ms voor attack

48000 * 0.001 = 48 samples per ms | want 48000 samples per seconde
48 * 15 = 720 samples.

Dus het moet van 0 naar 1 in 720 stapjes.

*/
  float samplesAmount = (m_samplerate * 0.001f) * lengthMs;
  m_factorIncrement = 1.0f / samplesAmount;

  #if DEBUG
    std::cout <<  "increment: " << m_factorIncrement << std::endl;
  #endif
}

void Envelope::play() { m_toggle = true; }
