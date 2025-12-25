#include <iostream>
#include <cmath>
using namespace std;

#define DEBUG 1

// explicit
template<typename V> struct mtof {

  V* midiPitch;
  mtof(V& midiPitch);

  template <typename T>
  operator T();
};

// out of class definition of mtof constructor with initializer list
template<typename V>
mtof<V>::mtof(V &midiPitch) {
  this->midiPitch = &midiPitch;
  cout <<
    "mtof constructor\n" <<
    "midiValue: " << midiPitch << "\nOf type: " <<
    typeid(midiPitch).name() << endl;
}

// out of class definition
template <typename V>
template <typename T>
mtof<V>::operator T() {
  T output = 440.0 * pow(2.0, (midiPitch - 69) / 12);
  cout << "Output frequency: " << output << endl;
  return output;
}

// template<typename T>
// midiPitch::operator T*(T* inputValue) {
//   return 440 * pow(2.0, (midiPitch - 69));}



//============================================================================//


int main() {
  cout << endl;
  #if DEBUG
  cout << "Starting program...\n" << endl;
  #endif

  //==========================================================================//
  cout << "test1" << endl;

  float calculateFreq = 36.0;
  mtof midiPitch1(calculateFreq);

  decltype(calculateFreq) frequency = static_cast<decltype(frequency)>(midiPitch1);

  // double frequency2 = midiPitch1.operator double*();
  // mtof

  string example_string = "abc";
  const char* test = example_string.c_str();

  cout <<
    "\nTest2\nValue in test: " << test << "\nOf type: " <<
    typeid(test).name() << endl;


  //==========================================================================//
  #if DEBUG
  cout << "\nProgram finished... shutting down" << endl;
  #endif

  cout << endl;
  return 0;
}
