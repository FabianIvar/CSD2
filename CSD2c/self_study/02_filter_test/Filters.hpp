//
// Created by Dean on 27/02/2024.
//
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

class Biquad :  public Filter {
  // float coefficients[5] = {
  //   0.1358015398471006,
  //   0.2716030796942012,
  //   0.1358015398471006,
  //   -0.7166657917686204,
  //   0.2598719511570229};

  float coefficients[5] = {
0.6551237193210465,
-1.310247438642093,
0.6551237193210465,
-0.931995440378234,
0.6884994369059523
};

// Coefficients
  float a0 = coefficients[0];
  float a1 = coefficients[1];
  float a2 = coefficients[2];
  float b1 = coefficients[3];
  float b2 = coefficients[4];
// Stored samples
  float xn_1 = 0.0f;
  float xn_2 = 0.0f;
  float yn_1 = 0.0f;
  float yn_2 = 0.0f;
  float gain;

public:
  float process(float x) override {
    float y = gain*(a0*x + a1*xn_1 + a2*xn_2 - b1*yn_1 - b2*yn_2);

    xn_2 = xn_1;
    xn_1 = x;
    yn_2 = yn_1;
    yn_1 = y;

    return y;

  }

  void setCoefficient(float gain) {
    this->gain = gain;
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
