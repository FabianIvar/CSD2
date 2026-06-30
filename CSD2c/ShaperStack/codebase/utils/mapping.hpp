/* by Fabean 29/06/26

generate exponential curve

             |
            *|
          _^ |
       _*^   |
----*^ˆ------|

fill a buffer and interpolate */

#pragma once
#include <cmath>
#include <iostream>
#include "interpolation.hpp"
#include "bufferToolkit.hpp"

using namespace Interpolation;
using namespace BufferToolkit;

#define MAPPING_DEBUG 0
#define DEBUG 0

struct Mapping {

  Mapping();
  ~Mapping();

  float getValue(int curve, float parameter);

private:

  void genEq1Curve();
  void genEq2Curve();
  void genEq3Curve();
  void genDelayCurve();

  float* eq1Curve;
  float* eq2Curve;
  float* eq3Curve;
  float* delayCurve;
};
