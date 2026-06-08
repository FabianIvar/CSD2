#pragma once
#include "effect.hpp"
#include "circularBuffer.hpp"
#include "../utils/bufferToolkit.hpp"

using namespace BufferToolkit;
#define DEBUG 1

struct FeedbackDelay {
  FeedbackDelay(
    float delayTimeMS, float maxDelayTimeMS,
    float feedback, float dryWet, float samplerate);

  ~FeedbackDelay() override;

  void applyEffect(const float &input,
    float &output) override;

  void setDelayTimeMS();
  void setFeedback(float feedback);

private:
/* using Pointer Composition, smart pointers would
 be better, but that's out of scope for now */

  CircularBuffer* m_circularBuffer;
  float m_feedback;
  uint m_numDelaySamples;
  uint m_bufferSize;

};
