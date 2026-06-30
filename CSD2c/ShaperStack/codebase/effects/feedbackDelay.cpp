#include "feedbackDelay.hpp"
#include <iostream>

FeedbackDelay::FeedbackDelay(
  float dryWet, float delayTimeMS, float maxDelayTimeMS,
  float feedback, float samplerate) :
  Effect(dryWet), m_samplerate(samplerate), m_factor(0.0f),
  m_output(0.0f) {

  #if DEBUG
    std::cout << "FeedbackDelay Constructor" << std::endl;
  #endif

  if (feedback < 0.0f) m_feedback = 0.0f;
  else if (feedback > 0.99f) m_feedback = 0.99f;
  else m_feedback = feedback;

  m_size = static_cast<int>(msToSamples(maxDelayTimeMS, m_samplerate));
  m_distRW = msToSamples(delayTimeMS, m_samplerate);

  //  (size | distRW)
  m_buffer = new CircularBuffer(m_size, m_distRW);

}

FeedbackDelay::~FeedbackDelay() {
  delete m_buffer;
  m_buffer = nullptr;

  #if DEBUG
    std::cout << "FeedbackDelay Destroyed" << std::endl;
  #endif

}

void FeedbackDelay::setParam(float parameter) {
  m_buffer->setDistRW(linear<float>(
    parameter, m_distRW, static_cast<float>(m_size)));
}

void FeedbackDelay::applyEffect(const float &input, float &output) {

  float sampl = m_buffer->read();
  if (sampl < -1.0f) sampl = -1.0f;
  else if (sampl > 1.0f) sampl = 1.0f;

  output = sampl;
  m_buffer->write(output * m_feedback + input);
  m_buffer->tick();
}
