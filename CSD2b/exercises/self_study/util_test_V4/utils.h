#pragma once
// using namespace std;
// #include <sstream>
#define EXCLUDE 1
#define DEBUG 0


//============================================================================//


namespace Utils {

/* NOTE: mtof and vtoa could share a class.
  This would probably prevent duplicate code.
  But this is out of scope for now.

  Constructor can deduce type and assign
  a value to a variable inside the class called
  output. Then the operator can return that output*/

  template<typename M> struct mtof {

    M* midiPitch;
    mtof(M& midiPitch);

    operator M();
  };

  template<typename V> struct vtoa {

    V* midiVelocity;
    vtoa(V midiVelocity);

    operator V();
  };

  template<typename C> struct constrain{

    C* output;
    constrain(C &inputValue, C &minimum, C &maximum);

    operator C();
  };

  // overloaded function
  // int noteSampleDur(double qNotes, double sampleRate);
  // int noteSampleDur(double bpm, double qNotes, double sampleRate);

}







#if !EXCLUDE
void func() {std::cout << "test" << std::endl;}
struct utils_old {
  // std::string color(
  //   std::string text, std::string color);
  // // auto arrSlice(
  // //   auto inputArray[], int startPos, int stopPos);
  //
  // float arrSum(
  //   float inputArray[], int start, int stop);
  // float constrain(
  //   float inputValue, float minimum, float maximum);
  //
  // double noteSampleDur(
  //   int bpm, float LenQNotes, double sampleRate);
  // double mtof(
  //   int midiPitch);
  // double velToAmp(
  //   int midiVel);
  //
  // template <typename T>
  // std::string pToString(const T& pointer);
};
#endif
