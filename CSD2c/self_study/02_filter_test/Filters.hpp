// Biquad filter, not very optimized.

#include <math.h>
#include <iostream>

#pragma once

class Filter {
public:
    virtual float process(float input) = 0;
    ~Filter() {
      std::cout << "Filter destroyed" << std::endl;
    }
};

class Biquad : public Filter { // peakingEQ

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

  ~Biquad() {
    std::cout << "biquad destroyed" << std::endl;
  }

public:
  void prepare(float cutoff, float qFactor, float dBgain, float samplerate) {
    m_samplerate = samplerate;
    m_cutoff = cutoff;
    m_qFactor = qFactor;
    m_dBgain = dBgain;
    calculateCoefficients();
  }

// system: y[n] = a0*x[n] + a1*x[n-1] - b1*y[n-1] - b2*y[n-2]
  float process(float x) override { // Biquad based on direct form
    float y = (
      a0/b0)*x + (a1/b0)*xn_1 + (a2/b0)*xn_2 - (b1/b0)*yn_1 - (b2/b0)*yn_2;

    xn_2 = xn_1;
    xn_1 = x;
    yn_2 = yn_1;
    yn_1 = y;

    return y;

  }

  void calculateCoefficients() {
// cutoff frequency in Hz, qFactor as a value between 0 and 1

    float w0 = (2.0f*M_PI * m_cutoff) / m_samplerate;
    float cosw0 = cos(w0);
    float sinw0 = sin(w0);
    float alpha = sinw0 / (2.0f * m_qFactor);
    float amplitude = pow(10.0f, m_dBgain * 0.025f);

// coefficients
    a0 = 1.0f + alpha * amplitude;
    a1 = -2.0f * cosw0;
    a2 = 1.0f - alpha * amplitude;
    b0 = 1.0f + alpha / amplitude;
    b1 = -2.0f * cosw0;
    b2 = 1.0f - alpha / amplitude;

    std::cout << a0 <<
      ",\n" << a1 <<
      ",\n" << a2 <<
      ",\n" << b0 <<
      ",\n" << b1 <<
      ",\n" << b2
    << std::endl;

  }

};
