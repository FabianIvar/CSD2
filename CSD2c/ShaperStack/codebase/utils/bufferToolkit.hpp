// By Fabean 8-6-26

#pragma once
#include <cstdlib>
#include <iostream>

namespace BufferToolkit {
  typedef unsigned int uint;

  template<typename A>
  inline A* allocate(uint size) {
    A value = 0;
    A* buffer = (A*)malloc(size * sizeof(A));
    memset(buffer, value, size * sizeof(A));
    return buffer;
  }

  template<typename L> // log buffer from 0 to size
  void logArray(L* buffer, uint size, std::string arrName) {
    std::cout << "\n" + arrName + ":\n";
    for (uint i = 0; i < size; i++) std::cout << buffer[i] << ", ";
  }

  template<typename C>
  bool contains(C* array, uint size, C target) {
    for (uint i = 0; i < size; i++) {
      if (array[i] == target) return true;
    }
    return false;
  }

  static float msToSamples(float millisec, float rate) {
    return (rate*0.001f*millisec);
  }

  static float samplesToMS(float samples, float rate) {
    return samples/rate;
  }
}
