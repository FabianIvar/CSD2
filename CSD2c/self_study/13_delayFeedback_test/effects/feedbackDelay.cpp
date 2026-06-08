#include "feedbackDelay.hpp"

FeedbackDelay::FeedbackDelay(
  float delayTimeMS, float maxDelayTimeMS, float feedback,
  float dryWet, float samplerate) : Effect(dryWet),
  m_feedback(feedback), m_samplerate(samplerate) {

  #if DEBUG
    std::cout << "FeedbackDelay Constructor" << std::endl;
  #endif

  uint distRW = static_cast<uint>(
    msToSamples(delayTimeMS, m_samplerate));

  m_bufferSize = static_cast<uint>(
    msToSamples(maxDelayTimeMS, m_samplerate));

  m_circularBuffer = new CircularBuffer(m_bufferSize, distRW);
}

FeedbackDelay::~FeedbackDelay() {
  delete m_circularBuffer;
  m_circularBuffer = nullptr;

  #if DEBUG
    std::cout << "FeedbackDelay Destroyed" << std::endl;
  #endif

}

void FeedbackDelay::applyEffect(const float &input,
  float &output) {

  output = m_circularBuffer->readH();
  m_circularBuffer->writeH(output * m_feedback + input);
  m_circularBuffer->tick();
}

void FeedbackDelay::setDelayTimeMS(float delayMillisec) {
  m_numDelaySamples = static_cast<uint>(
    msToSamples(delayMillisec, m_samplerate));
  if (m_numDelaySamples < m_bufferSize) {
    m_numDelaySamples = m_bufferSize;
  }

  m_circularBuffer->setDistRW(m_numDelaySamples);
}
