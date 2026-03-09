#pragma once
#include <cmath>
#include <iostream>
#define DEBUG 1

#define EXCLUDE_OLD_NN 1
#define EXCLUDE_NN 0

namespace Interpolation {
  typedef unsigned int uint;
  /* When used in interpolation context low can be seen as
     the previous value and high can be seen as the
     next value. */

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

  inline float* newBuffer(uint size) {
    float* buffer = (float*)malloc(size * sizeof(float));
    memset(buffer, 0.0f, size * sizeof(float));
    return buffer;
  }

  bool isEven(float val) {
    float half = val * 0.5;
    // std::cout << "\nHalf: " << half << std::endl;
    // std::cout << "output: " << (int(half) == half) ? true : false;
    return (int(half) == half) ? true : false;
  }

  void logBuffer(float* buffer, uint size) {
    // Printing buffer from 0 to size
    std::cout << "\nBuffer: ";
    for (uint i = 0; i < size; i++) std::cout << buffer[i] << ", ";
  }

}
