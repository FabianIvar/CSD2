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

  m_size = static_cast<uint>(msToSamples(maxDelayTimeMS, m_samplerate));
  m_distRW = msToSamples(delayTimeMS, m_samplerate);

  // (size | distRW)
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

  // std::cout << "-----[ m_size ]-----> " << m_size << std::endl;
}

void FeedbackDelay::applyEffect(const float &input, float &output) {

  output = m_buffer->read();

  m_output *= m_feedback;
  m_output += input;

  // std::cout << "-----[ feedback ]-----> " << m_feedback << std::endl;
  // std::cout << "-----[ m_output ]-----> " << m_output << std::endl;
  m_buffer->write(m_output);
  m_buffer->tick();


}

// this function might be redundant
void FeedbackDelay::setDelayTimeMS(float delayMS) {

  m_distRW = msToSamples(delayMS, m_samplerate);

  if (m_distRW > m_size) m_distRW = static_cast<float>(m_size);

  m_buffer->setDistRW(m_distRW);
}



















/* pseudo code for smoothing parameter input

calculate distance between parameter and stored parameter value

distance = parameter - storedParam;
  (e.g.) --> parameter = 0.7 and storedParam = 0.8
  distance = 0.7 - 0.8 --> -0.1

[idea 1]
I want the parameter to travel to the target value (the parameter value)
at a constant speed that doesn't generate clicks

[idea 2]
Credits to Midas for this one,
I could also work with grains, maybe with a class? It would take the start value, the target value, and the amount of time the grain will exist. maybe an ignore input boolean?

class Grain {
  Grain(float start, float target, float time) blabla initializer list {
    m_ignoreInput = false;
  }

  void start() {
    ignoreInput = true;
    float grainSize = 2 * msToSamples(time)

  }

  calcIncrement(float lengthMs) {

    float samplesAmount = (m_samplerate * 0.001f) * lengthMs;
    m_factorIncrement = 1.0f / samplesAmount;

    #if DEBUG
      std::cout <<  "increment: " << m_factorIncrement << std::endl;
    #endif
  }



private:
  float m_start;
  float m_target;
  float m_time;
  bool m_ignoreInput
}


*/
