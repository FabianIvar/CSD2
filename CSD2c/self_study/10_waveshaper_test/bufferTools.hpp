#pragma once

namespace BufferTools {
  typedef unsigned int uint;

  template<typename A>
  inline A* allocate(uint size) {
    A* buffer = (A*)malloc(size * sizeof(A));
    memset(buffer, 0.0f, size * sizeof(A));
    return buffer;
  }

  bool isEven(float val) {
    float half = val * 0.5;
    return (static_cast<int>(half) == half) ? true : false;
  }

  template<typename L>
  void logArray(L* buffer, uint size, std::string arrName) {
    // Printing buffer from 0 to size
    std::cout << "\n" + arrName + ": ";
    for (uint i = 0; i < size; i++) std::cout << buffer[i] << ", ";
  }

  template<typename C>
  bool contains(C* array, uint size, C target) {
    for (uint i = 0; i < size; i++) {
      if (array[i] == target) return true;
    }
    return false;
  }
}
