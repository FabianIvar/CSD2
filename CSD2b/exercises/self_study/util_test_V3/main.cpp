#include <iostream>
using namespace std;

// CONVERSION FUNCTIONS OH YEAGH! I can combine this with the factory method
// attempt at factory method

/*
For a class, a definition is required wherever the class is used in a way that
requires it to be complete.
So you can have a non-type class if the Type is incomplete.

There is no way to explicitly specify template arguments to overloaded
operators, conversion functions, and constructors, because they are called
without the use of the function name.

There can be more than one definition in a program as long as all following
conditions are satisfied:

declaration:
specialization
definition
instatiation



*/
namespace Utils {

  struct midiPitch {

    // "Virtual Constructor" 🤓
    static midiPitch* get(char id);
    virtual ~midiPitch(){}

    template<typename T>
    operator T*() {
      return 440 * pow(2.0, (const T& inputValue - 69));
    }
  };

//============================================================================//

  class Factory : public midiPitch {
    midiPitch* pMidiPitch;
    char type;

  public:
    Factory(char type) : pMidiPitch(nullptr) {
      this->type = type;
    }

    midiPitch* get(char type, void* inputValue) {
      if(type == 'i') {
        int* value = static_cast<int*>(inputValue);
        midiPitch
        return operator T*(const int* );}
      else if(type == 'f') {operator T*(const float* inputValue);}
      else if(type == 'd') {operator T*(const double* inputValue);}
      }

    ~Factory() {
      if(pMidiPitch){
        delete pMidiPitch;
        pMidiPitch = nullptr;
      }
    }
  };
}




    // implicit conversion
    operator int() const { return 7; }

    // explicit conversion
    explicit operator int*() const { return nullptr; }

    // Error: array operator not allowed in conversion-type-id
//  operator int(*)[3]() const { return nullptr; }

    using arr_t = int[3];
    operator arr_t*() const { return nullptr; } // OK if done through typedef
//  operator arr_t () const; // Error: conversion to array not allowed in any case


Utils::midiPitch::operator T*() {return 440 * pow(2.0, (midiPitch - 69));}


int main()
{
    Utils t;



//     int n = static_cast<int>(x);   // OK: sets n to 7
//     int m = x;                     // OK: sets m to 7
//
//     int* p = static_cast<int*>(x); // OK: sets p to null
// //  int* q = x; // Error: no implicit conversion
//
//     int (*pa)[3] = x;  // OK

  return 0
}
