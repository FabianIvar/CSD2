#pragma once
#define DEBUG 1

struct Envelope {
  Envelope(float samplerate, float attack, float decay, float release);
  ~Envelope();

  void calcIncrement(float lengthMs);
  float getAmplitude();
  void setAmplitude(float amplitude);
  void tick();
  void play();

private:
  int m_part;
  float m_attack;
  float m_decay;
  float m_release;

  float m_target[4] = {0.0f, 1.0f, 0.6f, 0.0f};
  float m_samplerate;
  float m_factor;
  float m_amplitude;
  float m_factorIncrement;
  bool m_toggle;

};
