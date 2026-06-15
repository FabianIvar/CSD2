#include "midasCircBuffer.hpp"
#include <iostream>
#include <cstring>
#include <cmath>


CircularBuffer::CircularBuffer()
{
  std::cout << "Buffer constructor" << std::endl;
  allocateBuffer();
}

CircularBuffer::~CircularBuffer()
{
  std::cout << "buffer destructor" << std::endl;
  releaseBuffer();
}

void CircularBuffer::allocateBuffer()
{
  m_buffer = (float*)malloc(m_size * sizeof(float));
  memset(m_buffer, 0, m_size * sizeof(float));
  std::cout << " allocate buffer \n";
}

void CircularBuffer::releaseBuffer()
{
  std::cout << " release buffer \n";
  free(m_buffer);
}

//==============================================================================

void CircularBuffer::tick()
{
  calculateReadH();
  incrWriteH();
  incrPhase();
}




float CircularBuffer::read()
{
  return m_buffer[m_readH] * calculateAmp(m_headPhase) + m_buffer[m_readH2] * calculateAmp(m_headPhase2);

}

void CircularBuffer::write(float input)
{
  m_buffer[m_writeH] = input;
}

void CircularBuffer::resetSize(int size)
{
  m_size = size - sizeof(float);
  releaseBuffer();
  allocateBuffer();
}

void CircularBuffer::setDistanceRW(int distanceRW)
{
  m_distanceRW = distanceRW;
  std::cout << "setDistanceRW\n";
}

float CircularBuffer::getDistanceRW()
{
  return m_distanceRW;
}

void CircularBuffer::m_calculatePhaseStep() // aka grainIncrement
{
  m_phaseStep = 1.0/static_cast<float>(m_grainSize);
  // std::cout << "goyly shit we got phaseStep:  " << m_phaseStep << std::endl;
}

void CircularBuffer::setGrainSize(int grainSize)
{
  m_grainSize = grainSize; // aka factor scaled to a value
  m_calculatePhaseStep();
}

void CircularBuffer::generateEnvelope()
{
  std::cout << "making envelope..." << std::endl;
  m_envelope = (float*)malloc(1024 * sizeof(float));
  int rampTime = 512;
  float rc = 1.0/rampTime;
  for (int i = 0; i < 1025; i++) {
    // std::cout << "envelp " << i << ": " << m_envelope[i] << std::endl;
  }

  for (int i = 0; i < 512; i++) {
    int j = i + 512;
    float attack  = i * rc;
    float release = i * -rc + 1.0;
    m_envelope[i] = attack;
    m_envelope[j] = release;
  }
  for (int i = 0; i < 1025; i++) {
    // std::cout << "envelp " << i << ": " << m_envelope[i] << std::endl;
  }
}

float CircularBuffer::calculateAmp(float phase) // aka getGrainAmp
{
  int index = phase * 1024;
  return m_envelope[index];
}

void CircularBuffer::prepare(int parameter) // aka prepareParam
{ // this was calculateGrainStep
  difference = parameter - m_grainSize;


  stepValue = 0.00005;
  m_tempGrainSize = m_grainSize;
  m_grainPhase = 0;

  move = true;

}

void CircularBuffer::smoothGrain() // aka smootheValue
{
  if (move) {
    m_grainPhase += stepValue; // value between 0 and 1

    m_grainSize = m_tempGrainSize + m_grainPhase * difference;

    // m_calculatePhaseStep();

    if (m_grainPhase >= 1.0) {
      m_grainPhase = 0;
      move = false;

    }
  }
  // setGrainSize(parameterGrainSize);
}




void CircularBuffer::calculateReadH() // inside read() function
{
    //    (0 * currentValue * 2 = 0)
    //    (0.5 * currentValue * 2 = currentValue)
  float backward  = m_headPhase * static_cast<float>(m_grainSize)*2;
  float backward2 = m_headPhase2 * static_cast<float>(m_grainSize)*2;
  m_readH  = m_writeH - m_distanceRW - backward;
  m_readH2 = m_writeH - m_distanceRW - backward2;

  /*
  readh = writeh - distRW
  readh2 = wrieh - distRW - currentValue


  */

  wrapH(m_readH);
  wrapH(m_readH2);
  // std::cout << "readheads: " <<  m_writeH << ", " << m_readH << ", " << m_readH2 << std::endl;
}

void CircularBuffer::incrWriteH()
{
  m_writeH++;
  wrapH(m_writeH);
}

void CircularBuffer::incrPhase()
{
  m_headPhase  += m_phaseStep;
  m_headPhase2 += m_phaseStep;
  if (m_headPhase  > 1.0) { m_headPhase  -= 1.0; }
  if (m_headPhase2 > 1.0) { m_headPhase2 -= 1.0; }
}

void CircularBuffer::wrapH(int& head)
{
  if (head > m_size) { head -= m_size; // std::cout << "plusplu:  " << head;
  }
  else if (head < 0) { head += m_size; // std::cout << "minuminus:  " << head;
  }
}
