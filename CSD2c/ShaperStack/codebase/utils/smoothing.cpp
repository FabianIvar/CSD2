#include "smoothing.hpp"
#include "bufferToolkit.hpp"
#include "interpolation.hpp"
#include <iostream>

Smoothing::Smoothing(uint amount) : m_writeH(0.0f) {
  #if DEBUG
    std::cout << "Smoothing Constructor" << std::endl;
  #endif

  m_buffer = allocate<float>(amount);
  m_size = static_cast<float>(amount);

  calcPhaseStep();
  setDistRW(amount);
  calcReadH();

  m_output = 0.0f;

  m_storedInput = 0.0f;
  m_difference = 0.0f;
  m_line = 0.0f;
  m_move = false;


}

Smoothing::~Smoothing() {
  free(m_buffer);
  #if DEBUG
    std::cout << "Smoothing Destroyed" << std::endl;
  #endif
}

void Smoothing::tick() {
  updateSize();
  calcReadH();
  incrWriteH();
  incrPhase();
}

float Smoothing::getValue() {
  for (int i = 0; i < 2; i++) {
    m_output += readFloat(m_readH[i]) * calculateAmp(m_PhaseH[i]);
  }
  return m_output;
}

void Smoothing::smooth(const float input) { // when param changes
  // lineIncrement = 0.00005; -> how much the line moves each tick
  // difference -> how much the parameter still needs to move storedInput + difference = current parameter value
  m_storedInput = input;
  m_difference = input - m_storedInput;
  m_line = 0.0f;
  m_move = true;
}

void Smoothing::write(float val) { // Writes val in buffer at writeH
  uint index = static_cast<uint>(m_writeH);
  float remainder = m_writeH - static_cast<float>(index);
  float low = static_cast<float>(index) - remainder;
  m_buffer[index] = linear<float>(0.5f, readFloat(low), val);
}

float Smoothing::readFloat(float index) {
  // returns value in buffer using floating point as index,
  // interpolates between two values in buffer using the remainder
  wrap(index);
  uint i = static_cast<uint>(index);
  return linear<float>(index - i), m_buffer[i], readIndex(i+1));
}

float Smoothing::readIndex(uint index) {
  // returns value in buffer using argument as parameter;
  wrap(index);
  return m_buffer[index];
}

void Smoothing::updateSize() { // every tick

  if (m_move) {

    m_line += m_lineStep;
    m_size = m_size + (m_storedInput + m_line * m_difference) * m_size ;
    calcPhaseStep();
    std::cout << "floatSize: " << m_size << std::endl;

    if (m_line >= 1.0f) {
      m_line = 0;
      m_move = false;
    }
  }
}

float Smoothing::calculateAmp(float phase) { // phase = value between 0 and 1
  if (phase < 0.5f) return linear(phase, 0.0f, 1.0f);
  return linear(phase, 1.0f, 0.0f);
}

void Smoothing::setSize(uint size) {
  free(m_buffer)
  m_buffer = allocate<float>(size);
  m_size = static_cast<float>(size);
  calcPhaseStep();
}

void Smoothing::setDistRW(uint distRW) {
  m_distRW = distRW;
}

void Smoothing::calcPhaseStep() {
// used for scrolling through the window -> amplitude of the grains,
// this never changes unless setGrainSize is called
  m_phaseStep = 1.0f/m_size;
}

void Smoothing::incrPhase() {
  m_phaseH[0] += m_phaseStep;
  wrapPhase(m_phaseH[0]);
}

void Smoothing::wrapPhase(float &phaseH) { // wraps value betwee 0 and 1
  if (phaseH > 1.0f) phaseH -= 1.0f;
}

void Smoothing::calcReadH() {
  m_phaseH[1] = m_phaseH[0] + 0.5f;
  wrapPhase(m_phaseH[1]);

  for (int i = 0; i < 2; i++=) {
    m_readH[i] = m_writeH - m_distRW + m_phaseH[i] * m_size;
    wrap(m_readH[i]);
  }

  logArray<float>(readH, 2, "ReadHeads");
}

void Smoothing::incrWriteH() {
  write(m_storedInput);
  m_writeH++;
  wrap(m_writeH);
}

void Smoothing::wrap(float &head) {
  if (head > m_size) head -= m_size;
  if (head < 0.0f) head += m_size;
}

/*

When parameter changes    |    When Tick is called    |    prepare
                          | updateSize                |
smooth                    | calcReadH                 | setSize
                          | getValue                  | setDistRW
                          |                           | calcReadH
                          |                           |
                          |                           |
                          |                           |



*/
