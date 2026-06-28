// Smoothing by Fabean 18/06/26

#include "smoothing.hpp"
#include <iostream>

/* Volgorde:

---------------------------------------------------------------------------

1) Smoothing* smooth object wordt aangemaakt in prepare.
   Hier wordt de grootte van de buffer bepaald en de 'hoeveelheid smoothing'
   (amount), amount wordt gebruikt om de stapgrootte van de windows te bepalen.
   dat werkt als volgt:
    stepsize = 1/amount
    'windowPhase' += stepsize     (dit is een beetje verwarrende naam)
    output = buffer[readH1] * calcAmplitude(windowPhase) +
             buffer[readH2] * calcAmplitude(windowPhase2)
        windowPhase2 is gewoon windowPhase maar dan 0.5 hoger

---------------------------------------------------------------------------

2) Wanneer de parameter wordt veranderd krijgt void Smoothing::smooth de
   parameter binnen als argument -> (value tussen 0.0f, en 1.0f).

3) Vervolgens wordt in de code smooth->getValue() gecalled
   In Smoothing->getValue() gebeuren meerdere dingen:
   > tick() wordt gecalled
     - updateSize(); -> scaled amount (aka grainsize) naar een nieuwe waarde
                        en berekent opnieuw de stepsize van de 'windowPhase'
     - calcReadH(); -> berekent de locaties van de twee readheads,
                       buffer[readH[0]] en buffer[readH[1]] zijn de twee
                       waardes waar een fade tussen is.
     - incrWrieH(); -> spreekt voor zich
     - incrPhase(); -> dit zorgt er voor dat de phase een stapje hoger wordt
                       (windowPhase += step)
   > write(storedInput); -> Schrijft op de locatie van de writeH storedInput in
                            een buffer. (waarde tussen 0.0f en 1.0f)
   > en de output berekenen en returnen =
                            buffer[readH1] *calcAmplitude(windowPhase) +
                            buffer[readH2] * calcAmplitude(windowPhase2)

Dat was m! ik heb in deze uitleg niet letterlijk de namen van de variables
gebruikt om het even wat duidelijker te maken. Ik heb soms ook dingen in een
array gedaan ipv bijvoorbeeld readH1 en readH2, maar ik denk dat het verder wel
logisch is.

*/


Smoothing::Smoothing(uint bufferSize, float amount) : m_size(bufferSize), m_writeH(0.0f) {
  #if DEBUG
    std::cout << "Smoothing Constructor" << std::endl;
  #endif

  m_buffer = allocate<float>(bufferSize);
  m_grainSize = amount;

  calcPhaseStep();
  setDistRW(amount);
  calcReadH();

  m_storedInput = 0.0f;
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
  tick();
  write(m_storedInput);
  float output = 0.0f;
  for (int i = 0; i < 2; i++) {
    output += readFloat(m_readH[i]) * calculateAmp(m_phaseH[i])*2;
  }
  return output;
}

void Smoothing::smooth(const float &input) { // when param changes
  // lineIncrement = 0.00005; -> how much the line moves each tick
  // difference -> how much the parameter still needs to move storedInput + difference = current parameter value

  m_storedInput = input;
  float inputDifference = input - m_storedInput;
  m_line = 0.0f;
  m_move = true;

  m_storedSize = m_grainSize;
  m_targetSize = m_storedSize + m_storedSize * inputDifference;
  m_difference = m_targetSize - m_storedSize;
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
  return linear<float>(index - i, m_buffer[i], readIndex(i+1));
}

float Smoothing::readIndex(uint index) {
  // returns value in buffer using argument as parameter;
  wrap(index);
  return m_buffer[index];
}

void Smoothing::updateSize() { // every tick

  if (m_move) {

    m_line += m_lineStep;
    m_grainSize = m_storedSize + m_line * m_difference;
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
  free(m_buffer);
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
  m_phaseStep = 1.0f/m_grainSize;
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

  for (int i = 0; i < 2; i++) {
    m_readH[i] = m_writeH - m_distRW + m_phaseH[i] * m_grainSize;
    wrap(m_readH[i]);
  }

  // logArray<float>(m_readH, 2, "ReadHeads");
}

void Smoothing::incrWriteH() {
  // write(m_storedInput);
  m_writeH++;
  wrap(m_writeH);
}

void Smoothing::wrap(float &head) {
  if (head > m_size) head -= m_size;
  if (head < 0.0f) head += m_size;
}

// might cause problems? -> casting m_size to uint
void Smoothing::wrap(uint &head) {
  if (head > static_cast<uint>(m_size)) head -= static_cast<uint>(m_size);
  if (head < 0) head += static_cast<uint>(m_size);
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
