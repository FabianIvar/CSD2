// By Fabean 8-6-26

#pragma once

namespace BufferToolkit {
  typedef unsigned int uint;

  template<typename A>
  inline A* allocate(uint size) {
    A value = 0;
    A* buffer = (A*)malloc(size * sizeof(A));
    memset(buffer, value, size * sizeof(A));
    return buffer;
  }

  template<typename L>
  void logArray(L* buffer, uint size, std::string arrName) { // Printing buffer from 0 to size
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

  int msToSamples(float millisec, float rate) {
    return static_cast<int>(rate*0.001f*millisec);
  }
}
