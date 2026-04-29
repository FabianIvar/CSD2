#include <math.h>
#include <iostream>

#pragma once

class Filter {
public:
    virtual float process(float input) = 0;
};


//                   IIRFilter
//   X[n] ---->(+)--->[ 1 sample ] ---> Y[n]
//              |                   |
//             (a)<-----------------
//
class IIRFilter : public Filter {
    public:
    float process(float input) override {
        // Y[n] = X[n] + aY[n-1]
        feedback = input + (a * feedback);
        return feedback;
    }

    void setCoefficient(float coefficient) {
        // Do not exceed 1, for the safety of all our ears
        a = coefficient;
    }

private:
    float feedback { 0.0 };
    float a { 0.0 }; // Coefficient "a" is mostly used for feedback lines

};


//                    OneZero
//   X[n] ---->-------------------(+)---> Y[n]
//              |                  |
//             (b)-->[ 1 sample ]-->
//
class FIRFilter : public Filter {
    public:
    float process(float input) override {
        // Y[n] = X[n] - bX[n-1]
        auto output = input - (b * x1);

        x1 = input; // Recaching Delay
        return output;
    }

    void setCoefficient(float coefficient) {
        b = coefficient;
    }

private:
    float x1 {0.0 }; // x1 for a single sample delay
    float b { 0.0 };  // Coefficient "b" is usually used for feed forward lines

};

class Biquad :  public Filter { // peakingEQ
  // float coefficients[5] = {
  //   0.1358015398471006,
  //   0.2716030796942012,
  //   0.1358015398471006,
  //   -0.7166657917686204,
  //   0.2598719511570229};

//   float coefficients[5] = {
// 0.6551237193210465,
// -1.310247438642093,
// 0.6551237193210465,
// -0.931995440378234,
// 0.6884994369059523
// };


//========================================================


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

public:
  float prepare(float cutoff, float qFactor, float dBgain, float samplerate) {
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

//                   OnePole
//   X[n] --(b)->(+)--->[ 1 sample ] ---> Y[n]
//              |                   |
//             (a)<-----------------
//
class OnePole : public Filter {
    public:
    float process(float input) override {
        // Y[n] = bX[n] + aY[n-1]
        // You make this one:

        std::cout << "input" << std::endl;

    }

    void setCoefficient(float coefficient) {
        a = coefficient;
        b = 1.0f - a;
    }

private:
    float feedback { 0.0 };
    float a { 0.0 };
    float b { 0.0 };
};


//                   4_Pole / Simple Cascade
//   X[n]--->[OnePole][OnePole][OnePole][OnePole]--->Y[n]
//
class SimpleLadder :  public Filter {
    public:
    float process(float input) override {

    }

    void setCoefficient(float coefficient) {
        a = coefficient;
        b = 1.0f - a;
    }

private:
    float A { 0.0 };
    float B { 0.0 };
    float C { 0.0 };
    float D { 0.0 };


    float b { 0.0 };
    float a { 0.0 };
};


//                   4 Sample
//   X[n] --(b)->(+)--->[ 4 sample ] ---> Y[n]
//              |                   |
//             (a)<-----------------
//
class FourSample :  public Filter {
    public:
    float process(float input) override {
        // Y[n] = X[n] + aY[n-4]

    }

    void setCoefficient(float coefficient) {
        a = coefficient;
        b = 1.0f - a;
    }


private:
    float feedback { 0.0 };
    float b { 0.0 };
    float a { 0.0 };
};


//                   Halve Biquad
//   X[n] --(b)->(+)--------------------> Y[n]
//                |                  |
//               (a1)<----------[ 1 sample ]
//                |                  |
//               (a2)<----------[ 1 sample ]
//
//
class HalfBiquad :  public Filter {
    public:
    float process(float input) override {
      // y[n] = bX[n] - a1Y[n-1] - a2Y[n-2]

    }

    void setBCoefficient(float coefficient){
        b = coefficient;
    }

    void setA1Coefficient(float coefficient) {
        a1 = coefficient;
    }

    void setA2Coefficient(float coefficient) {
        a2 = coefficient;
    }


private:
    float b;
    float a1;
    float a2;
};


// class Biquad :  public Filter {
// public:
//     // Zoek een Biquad, en maak  'm :- )
//     // Probeer het internet, of Will Pirkle, zijn verschillende benaderingen
//     // Succes.
//
//
//
// };
