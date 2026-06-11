#pragma once

struct Effect {
  Effect();
  Effect(float dryWet);
  Effect(float dryWet, bool bypass);
  virtual ~Effect();

  virtual void prepare(float samplerate) { }
  void processFrame(const float& input, float& output);
  float getSample();
  void setDryWet(float dryWet);
  void setParam(float parameter);

protected:
  virtual void applyEffect(const float& input, float& output) = 0;

private:
  float m_dryWet;
  float m_sample;
  bool m_bypass = false;
};
