#pragma once
#include <cmath>

#define EXCLUDE_NN 0
#define EXCLUDE_LIN 0
#define EXCLUDE_BLIN 0

namespace Interpolation {
  typedef unsigned int uint;
  /* When used in interpolation context low can be seen as
     the previous value and high can be seen as the
     next value. */

// ==[Nearest Neighbour]========

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

}
