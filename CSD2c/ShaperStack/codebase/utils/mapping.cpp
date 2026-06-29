#include "mapping.hpp"

Mapping::Mapping() {
  #if DEBUG
    std::cout << "Mapping Constructor" << std::endl;
  #endif

  eq1Curve = allocate<float>(512);
  eq2Curve = allocate<float>(512);
  eq3Curve = allocate<float>(512);
  delayCurve = allocate<float>(512);

  genEq1Curve();
  genEq2Curve();
  genEq3Curve();
  genDelayCurve();
}

Mapping::~Mapping() {
  free(eq1Curve);
  free(eq2Curve);
  free(eq3Curve);
  free(delayCurve);

  #if DEBUG
    std::cout << "Mapping Destroyed" << std::endl;
  #endif
}

void Mapping::genEq1Curve() {
  for (int x = 0; x < 512; x++) {
    float value = (pow(4.0f, x/511.0f) - 1.0f) / 3.0f;
    if (value < 0.0f) value = 0.0f;

    eq1Curve[x] = value;
  }
  #if MAPPING_DEBUG
  logArray<float>(eq1Curve, 512, "eq1");
  #endif
}

void Mapping::genEq2Curve() {
  for (int x = 0; x < 512; x++) {
    float value = (pow(16.0f, (x/511.0f)-0.25f) - 1.0f) / 7.0f;
    if (value < 0.0f) value = 0.0f;

    eq2Curve[x] = value;

  }
  #if MAPPING_DEBUG
  logArray<float>(eq2Curve, 512, "eq2");
  #endif
}

void Mapping::genEq3Curve() {
  for (int x = 0; x < 512; x++) {
    float value = (pow(9.0f, (x/511.0f)-0.5f) - 1.0f) / 2.0f;
    if (value < 0.0f) value = 0.0f;

    eq3Curve[x] = value;

  }
  #if MAPPING_DEBUG
  logArray<float>(eq3Curve, 512, "eq3");
  #endif
}

void Mapping::genDelayCurve() {
  for (int x = 0; x < 512; x++) {
    delayCurve[x] = (pow(10.0f, 5.0f * (x/511.0f)) - 1.0f) / 99999.0f;

  }
  #if MAPPING_DEBUG
  logArray<float>(eq3Curve, 512, "delay");
  #endif
}

float Mapping::getValue(int curve, float parameter) {

  float floatIndex = parameter * 511.0f;
  int index = static_cast<int>(floatIndex);
  float remainder = floatIndex-index;
  int high;
  (index == 511) ? high = 511 : high = index+1;

  switch(curve) {
    case 1:
      return linear<float>(remainder, eq1Curve[index], eq1Curve[high]);
      break;
    case 2:
      return linear<float>(remainder, eq2Curve[index], eq2Curve[high]);
      break;
    case 3:
      return linear<float>(remainder, eq3Curve[index], eq3Curve[high]);
      break;
    case 4:
      return linear<float>(remainder, delayCurve[index], delayCurve[high]);
      break;
    default:
      std::cout << "something went wrong" << std::endl;
      return 0.0f;
  }
}
