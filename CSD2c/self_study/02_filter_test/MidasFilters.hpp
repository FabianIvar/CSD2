#include <iostream>
#include "math.h"
#pragma once

class Filter {
public:
  virtual float process(float input) = 0;
};


class Biquad :  public Filter {
public:
  float process(float input) override {
    // y[n] = b0X[n] + b1X[n-1] + b2X[n-2] - a1Y[n-1] - a2Y[n-2]
    float output = input * b0 + sample1;
    sample1 = sample2 + input * b1 - output * a1;
    sample2 = input * b2 - output * a2;
    // std::cout << input << " , " << output << std::endl;
    return output;
  }

  void calculateCoefficients(float f0, float q) {
    float w0 = 2.0f*M_PI*f0/static_cast<float>(48000);
    float cosW0 = cos(w0);
    float sinW0 = sin(w0);
    float alfa = sinW0/(2.0f*q);
    b1 = 1.0f-cosW0;
    b0 = b1*0.5f;
    b2 = b0;
    a0 = 1.0f+alfa;
    a1 = -2.0f*cosW0;
    a2 = 1.0f-alfa;
    // std::cout << "check deze: " << a1 << ", " << a2 << ", " << b0 << ", " << b1 << ", " << b2 << std::endl;
  }

private:
  float a0 = { 0.0f };
  float a1 = { 0.0f };
  float a2 = { 0.0f };
  float b0 = { 0.0f };
  float b1 = { 0.0f };
  float b2 = { 0.0f };
  float sample1 = { 0.0f };
  float sample2 = { 0.0f };
};


class PirkleBiquad :  public Filter {
public:
  float process(float input) override {
    // y[n] = b0X[n] + b1X[n-1] + b2X[n-2] - a1Y[n-1] - a2Y[n-2]
    float output = input * b0 + sample1;
    sample1 = sample2 + input * b1 - output * a1;
    sample2 = input * b2 - output * a2;
    return output;
  }

  void calculateCoefficients(float f0, float q) {
    std::cout << f0 << ", " << q << std::endl;
    float w0 = 2.0f*M_PI*f0/static_cast<float>(48000);
    float d = 1/q;
    float sinW0 = sin(w0);
    float b = 0.5*(1-(d/2)*sinW0)/(1+(d/2)*sinW0);
    float y = (0.5+b)*cos(w0);
    b1 = 0.5+b-y;
    b0 = 0.5*b1;
    b2 = b0;
    // a0 = 1.0f+alfa;
    a1 = -2.0f*y;
    a2 = 2*b;
    std::cout << "check deze: " << a1 << ", " << a2 << ", " << b0 << ", " << b1 << ", " << b2 << std::endl;
  }

private:
  float a0 = { 0.0f };
  float a1 = { 0.0f };
  float a2 = { 0.0f };
  float b0 = { 0.0f };
  float b1 = { 0.0f };
  float b2 = { 0.0f };
  float sample1 = { 0.0f };
  float sample2 = { 0.0f };
};
