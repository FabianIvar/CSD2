#include <iostream>
using namespace std;

#define DEBUG 1

//=============================================================================//


namespace Utils {
  template<typename V> struct mtof {

    V* midiPitch;
    mtof(V& midiPitch);

    // template <typename T>
    operator V(); // was operator T();
  };
}


/* out-of-class definition of mtof
   constructor with initializer list */
template<typename V>
Utils::mtof<V>::mtof(V &midiPitch) {
  this->midiPitch = &midiPitch;
  cout <<
    "mtof constructor\n" <<
    "midiValue: " << midiPitch <<
    "\nOf type: " << typeid(midiPitch).name()
  << endl;
}

// out-of-class definition of operator
template <typename V>
Utils::mtof<V>::operator V() {

  V output = 440.0 * pow(
    2.0, (*midiPitch - 69.0) / 12.0);
  cout <<
    "Output frequency: " << output
  << endl;

  return output;
}



//=============================================================================//


int main() {
  cout << endl;
  #if DEBUG
  cout << "Starting program...\n" << endl;
  #endif

  using namespace Utils;

//======================================================//


  cout << "test1:" << endl;

  float calculateFreq = 36.0;
  mtof midiPitch1(calculateFreq);

  // NOTE: typedef here?


  decltype(calculateFreq) frequency = static_cast<decltype(frequency)>(midiPitch1);


  // double frequency2 = midiPitch1.operator double*();
  // mtof

  string example_string = "abc";
  const char* test = example_string.c_str();

  cout <<
    "\nTest2\nValue in test: " << test <<
    "\nOf type: " << typeid(test).name()
  << endl;


  //====================================================//


  #if DEBUG
  cout << "\nProgram finished... shutting down" << endl;
  #endif

  cout << endl;
  return 0;
}
