// This is an updated version of interpolation in 03_interpolation_test
#pragma once
#include <cmath>
#include <iostream>
#define DEBUG 1

#define EXCLUDE_OLD_NN 1
#define EXCLUDE_NN 0
#define EXCLUDE_LIN 0
#define EXCLUDE_BLIN 0

namespace Interpolation {
  typedef unsigned int uint;
  /* When used in interpolation context low can be seen as
     the previous value and high can be seen as the
     next value. */

// ==[Nearest Neighbour]========

  #if !EXCLUDE_OLD_NN
    inline float old_nearest_neighbour(
      float value, float low, float high) {

      float bounds[] = {low, high};
      float distance[2];

      for (uint i : bounds) {
        uint index = &bounds[i] - &bounds[0];

        std::cout << "index: " + std::to_string(index) + "\n";

        distance[index] = sqrt(pow(value, 2) + pow(i, 2));

        #if DEBUG
          std::cout << "value: " + std::to_string(index) << std::endl;

        #endif
      }
      return (distance[0] < distance[1]) ? bounds[1] : bounds[0];
    }
  #endif

  #if !EXCLUDE_NN
    template<typename T>
      inline T nearestNeighbour(T val, T low, T high) {
        T half = (high - low) * 0.5;
        return (val < half) ? low : high;
      }
  #endif

// ==[Linear]========

  #if !EXCLUDE_LIN
    template<typename LN>
    inline LN linear(LN factor, LN low, LN high) {
      if(factor < 0) return low; //        |- constrain between (0,1)
      else if(factor > 1) return high; //  |
      return (1.0 - factor) * low + factor * high;
    }
  #endif

// ==[Bilinear]======

  #if !EXCLUDE_BLIN
    template<typename BL> // 'mapInRange'
    inline BL bilinear(BL input, BL inLow, BL inHigh,
      BL outLow, BL outHigh)
    {
      BL factor = (input - inLow) / (inHigh - inLow);
      BL outDelta = outHigh - outLow;
      return outLow + outDelta * factor;
    }
  #endif

// ==[utility]==============================================================

  template<typename E>
  bool isEven(E val) {
    E half = val * 0.5;
    return (int(half) == half) ? true : false;
  }

  template<typename C>
  inline bool contains(C* array, uint size, C target) {
    for (uint i = 0; i < size; i++) {
      if (array[i] == target) return true;
    }
    return false;
  }

} // Interpolation
