#include <iostream>
#include <numeric>
// #include "utils.h"
#include <cmath>
#include <sstream>
using namespace std;

// #define DEBUG 1

// R stands for ReturnType
  // template <typename T> T subject = T(44.5);
  // auto value = subject;
  // static pack(T valueToPack) : subject(valueToPack) {
  //   cout << "pack" << endl;
  // };

// class R {
// private:
//   string toString(void* inputVoidPtr) {
//     stringstream ss;
//     ss << inputVoidPtr;
//     string outputString = ss.str();
//     return outputString;
//   }
//
// public:
//   static void unpack(void* subject) {
//     cout << "unpack" << endl;
//     // void* subjectPtr = &subject<int>;
//     // int* intPtr = &subject<int>;
//     // float* floatPtr = &subject<float>;
//     // double* doublePtr = &subject<double>;
//
//     vector<string> comparators;
//     auto type[] = {int,float,double};
//     for (auto i : type) {
//       comparators.push_back(&subject<type[i]);
//     }
//     // = {
//     //   toString(static_cast<int*>(subject)),
//     //   toString(static_cast<float*>(subject)),
//     //   toString(static_cast<double*>(subject))};
//
//
//     // stringstream in;
//     // for (auto i = comparators.begin(); i < comarators.size()) {
//     //   if(!toString(subject).compare(comparators[i])) {
//
//       }
//     }
//
//     stringstream in(comparators);
//
//     vector<string> comparators;
//     string outputString;
//     stringstream ss(comparators).str();
//     while (ss >> string i;) {
//       cout << i << endl;
//     }
//
//   }
// };

template <typename T>
T newFuncTest(void* )

string toString(auto inputPtr) {
  void* voidPtr = static_cast<void*>(inputPtr);
  stringstream ss;
  ss << inputPtr;
  string outputString = ss.str();
  return outputString;
}

class Store {
  char StoredType;
public:
  Store(int storeType) {this->StoredType = typeid(storeType).name()}
  Store(float storeType) {this->StoredType = typeid(storeType).name()}
  Store(double storeType) {this->StoredType = typeid(storeType).name()}
  Store(string storeType) {this->StoredType = typeid(storeType).name()}

  char retreive(){this->storedType;}
};

class Base {
void* address
public:
  Base(void* val1, char val2) : address(val1), targetType(val2){}
};

class Extract{
  void* addressToCast;
  string typeToCastTo;
  Store storedType;
  // float
public:
  void set(int type, void* intAddress)  {
    this->typeToCastTo = typeid(type).name();
    this->addressToCast = intAddress;}
  void set(float type, void* floatAddress) {
    this->typeToCastTo = typeid(type).name();
    this->addressToCast = floatAddress;}
  void set(double type, void* doubleAddress) {
    this->typeToCastTo = typeid(type).name();
    this->addressToCast = doubleAddress;}
  void set(string type, Void* charAddress) {
    this->typeToCastTo = typeid(type).name();
    this->addressToCast = stringAddress;}

  int* get(int referenceType){
    return static_cast<int*>(addressToCast);
  }
};


  //
  // static int* getType(int* value) {
  //   return static_cast<int*>(y)}
  //   static float* getType(float* value){
  //     return static_cast<int*>(y)}
  //   static double* getType(double* value){
  //     return static_cast<int*>(y)}
  //   static string* getType(string* value){
  //     return static_cast<int*>(y)}

// Compares strings containing void pointer address and returns the value with the correct
class T {
  void* inputValue;
  auto returnType = {int,float,double,string};

protected:
  T(void* x);
  auto typeFunc();
};

T::T(void* x) : inputValue(x) {
  cout << "T1 Constructor\nTypesAmt: " << endl;
}

auto T::typeFunc() {
  // cout << "inputValue: " << toString(inputValue) << endl;
  Extract* output = nullptr;

  void* subject = this->inputValue;
  string comparator[] = {
    toString(static_cast<int*>(subject)),
    toString(static_cast<float*>(subject)),
    toString(static_cast<double*>(subject)),
    toString(static_cast<string*>(subject))};

    enum typeEnum {I, F, D, STR, SIZE};

  for (int i = 0; i < SIZE; i++) {
    if (!toString(subject).compare(comparator[i])) {
       if(i == I) {output.set(1, comparator[i]);}
       else if(i == F) {output.set(1.0f, comparator[i]);}
       else if(i == D) {output.set(1.0, comparator[i]);}
       else if(i == STR) {output.set("ye", comparator[i]);}
    }

  }

  return output.get();
};


int main() {
  cout << "Hello World" << endl;

  // int test1Int = 5;
  // void* test1Void = &test1Int;
  // T testObj();
  //
  // for (int i = 0; i < types.Size; i++)
  // string test1String = toString(test1Void);
  //
  // cout << "test1String: " << test1String << endl;

  // unpackPointer = &R::unpack(void*);

  return 0;
}












// string utils::color(string textInput, string color) {
//   #if DEBUG
//   cout << "utils::color" << endl;
//   #endif
//
//   string ansiColors[14] = {
//     "red",
//     "green",
//     "yellow",
//     "blue",
//     "magenta",
//     "cyan",
//     "white",
//     "brightBlack",
//     "brightRed",
//     "brightGreen",
//     "brightYellow",
//     "brightBlue",
//     "brightMagenta",
//     "brightCyan",
//   };
//
//   string ansiCode;
//
//   for (int i = 0; i < 14; i++) {
//     if (!(color.compare(ansiColors[i]))) {
//       if (i <= 6) {
//         // ANSI code 30 is black and not visable in the terminal
//         ansiCode = to_string(31 + i);
//       }
//       else {
//         // Starting from 90 are the bright variants of the colors
//         ansiCode = to_string(83 + i);
//       }
//     }
//   }
//
//   string suffix = "\033[0m";
//   string prefix = "\x1B[" + ansiCode + "m";
//   string output = prefix + textInput + suffix;
//
//   #if DEBUG
//   cout << "outut: " << output << endl;
//   #endif
//
//   return output;
// }
//
//
// void* utils::arrSum(vector<void*> arr, int start, int stop) {
//   decltype(returnType(arr[])) output = 0;
//
//   for (int i = start; i <= stop; i++) {
//     output += arr[i];
//   }
//   // return output;
//
//
// }
//
//
// T utils::constrain(T inputValue, T minimum, T maximum) {
//   return min(maximum, max(minimum, inputValue));
// }
//
// float utils::noteSampleDur(float lenQNotes, int sampleRate) {
//   #if DEBUG
//   cout << "utils::noteSampleDur" << endl;
//   #endif
//
//   /* lenQNotes means the note length expressed as amount of quarter notes.
//   lenQNotes = 2.0 means 2 quarter notes, so a half note.
//   With a bpm of 120, a quarter note is: 60/ 120 = 0,5
//   With a sampleRate of 44100 samples per second,
//   The amount of samples in 0,5 seconds is 44100 * 0,5 = 22050 samples */
//
//   float noteTimeDurSec = (60.0f/120.0f) * lenQNotes;
//   int durInSamples = sampleRate * noteTimeDurSec;
//
//   #if DEBUG
//   cout << ">>> " << lenQNotes << " " << sampleRate << " " << noteTimeDurSec << " " << endl;
//   #endif
//
//   return durInSamples;
// }
//
// float utils::mtof(int midiPitch) {
// /* Source - https://git.jaydee.systems/chromaticsol/CSD2/src/commit/c8c69fe00e59fb6191f1c6304b2514295bc0057d/CSD2b/SynthTests/Codebase/utils.cpp
// By Vida, slightly modified to fit this project. */
//
//   float frequency = 440.0f * pow(2.0f, (midiPitch - 69.0f) / 12.0f);
//   return frequency;
// }
//
// float utils::velToAmp(int midiVel) {
//   float amplitude = midiVel / 127.0f;
//   return amplitude;
// }
