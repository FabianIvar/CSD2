/*
Biquad filter based on direct form
y[n] = a0*x[n] + a1*x[n-1] - b1*y[n-1] - b2*y[n-2]
*/

#include <math.h>
#include <iostream>
#include "effect.hpp"

#pragma once

struct Filter : public Effect { // peakingEQ

  Filter(float dryWet, float cutoff, float qFactor,
    float dBgain, float samplerate);

  ~Filter() override;

  void applyEffect(const float& input, float& output) override;

  void calculateCoefficients();

private:

// Coefficients
  float a0; // |-- Zeros
  float a1; // |
  float a2; // |

  float b0; // |-- Poles
  float b1; // |
  float b2; // |

// Stored samples
  float xn_1 = 0.0f;
  float xn_2 = 0.0f;
  float yn_1 = 0.0f;
  float yn_2 = 0.0f;

// Member variables
  float m_samplerate;
  float m_cutoff;
  float m_qFactor;
  float m_dBgain;
  float m_amplitude;





};
