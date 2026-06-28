#pragma once
#include "effect.hpp"
#include "circularBuffer.hpp"
#include "../utils/bufferToolkit.hpp"
#include "../utils/interpolation.hpp"

using namespace BufferToolkit;
using namespace Interpolation;

struct FeedbackDelay : public Effect {
  FeedbackDelay(
    float dryWet, float delayTimeMS, float maxDelayTimeMS,
    float feedback, float samplerate);

  ~FeedbackDelay() override;

  void applyEffect(const float &input,
    float &output) override;

  virtual void setParam(float parameter) override;
  void setDelayTimeMS(float delayMillisec);
  void setFeedback(float feedback);

private:
  /* using Pointer Composition rn, smart pointers would
   be better, but that's out of scope for now */

  CircularBuffer* m_buffer;
  float m_samplerate;
  float m_feedback;
  // uint m_numDelaySamples; // misschien niet meer nodig?
  uint m_size;
  float m_distRW;
  float m_factor;
  float m_output;

};
