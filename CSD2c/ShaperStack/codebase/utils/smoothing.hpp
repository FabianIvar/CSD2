#pragma once
#include "bufferToolkit.hpp"
#include "interpolation.hpp"
#include <iostream>

#define DEBUG 1

struct Smoothing {
// amount is how many samples are in the 'grains' aka windows
  Smoothing(uint amount);
  ~Smoothing();
  void tick();
  void smooth(float &input);
  void getValue();

private:

  void write(float val);
  float readFloat(float index);
  float readIndex(uint index);
  void updateSize();
  float calculateAmp();
  void setSize(uint size); // resize
  void setDistRW(uint distRW);
  void calcPhaseStep();
  void incrPhase();
  void wrapPhase(float &phaseH);
  void calcReadH();
  void incrWriteH();
  void wrap(float &head);

  float* m_buffer;
  float m_size;
  uint m_distRW;
  float m_phaseStep;
// smooth
  float m_storedInput;
  float m_difference;
  //m_phase = 0
  bool m_move = true;
  float m_lineStep = 0.00005f;
  // heads
  float m_line;
  float m_phaseH[2] = {0.0f, 0.0f};
  float m_readH[2] = {0.0f, 0.0f};
  float m_writeH;
  float m_output;


}
