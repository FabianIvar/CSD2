/* by Fabean 29/06/26

generate exponential curve

             |
            *|
          _^ |
       _*^   |
----*^ˆ------|

fill a buffer and interpolate */

#include <cmath>
#include <iostream>
#define MAPPING_DEBUG 1

struct Mapping {

  Mapping();
  ~Mapping();

  void genDelayCurve() {
    for (int x = 0; x < 512; x++) {
      delayCurve[x] = (pow(10.0f, 5.0f * x) - 1.0f) / 99999.0f;
    }
  }

  void genEq1Curve() {
    for (int x = 0.0f; x < 512.0f; x++) {
      float value = (pow(4.0f, x) - 1.0f) / 3.0f;
      if (value < 0.0f) value = 0.0f;

      eq1Curve[x] = value;
    }
    #if MAPPING_DEBUG
      logArray<float>(eq1Curve, 512, "eq1");
    #endif
  }

  void genEq2Curve() {
    for (int x = 0.0f; x < 512.0f; x++) {
      float value = (pow(16.0f, x-0.25f) - 1.0f) / 7.0f;
      if (value < 0.0f) value = 0.0f;

      eq2Curve[x] = value;

      #if MAPPING_DEBUG
        logArray<float>(eq1Curve, 512, "eq1");
      #endif
    }
  }

  void genEq3Curve() {
    for (int x = 0.0f; x < 512.0f; x++) {
      float value = (pow(9.0f, x-0.5f) - 1.0f) / 2.0f;
      if (value < 0.0f) value = 0.0f;

      eq3Curve[x] = value;

      #if MAPPING_DEBUG
        logArray<float>(eq1Curve, 512, "eq1");
      #endif
    }
  }

  float getValue(int curve, float parameter) {

    float floatIndex = parameter * 512.0f;
    int index = static_cast<int>(floatIndex);
    float remainder = floatIndex-index;
    int high;
    (index == 512) ? high = 512 : high = index+1;

    switch(curve) {
      case 1:
        return linear<float>(remainder, delayCurve[index], delayCurve[high]);
        break;
      case 2:
        return linear<float>(remainder, eq1Curve[index], eq1Curve[high]);
        break;
      case 3:
        return linear<float>(remainder, eq2Curve[index], eq2Curve[high]);
        break;
      case 4:
        return linear<float>(remainder, eq3Curve[index], eq3Curve[high]);
        break;
      default:
        std::cout << "something went wrong" << std::endl;
    }
  }

private:


  float* eq1Curve;
  float* eq2Curve;
  float* eq3Curve;
  float* delayCurve;
}
