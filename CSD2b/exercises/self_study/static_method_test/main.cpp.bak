#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdint>
// #include "utils.h"
using namespace std;

#define DEBUG 0

// Template Class
template <typename T> class Test1 {

private:
  T arg1;
  T arg2;

public:
  Test1(T val1, T val2) : arg1(val1), arg2(val2) {
    cout << "Test1 Constructor" << endl;
  }

  void displayType() {
    cout << "Type is: " << typeid(arg1).name() << endl;
  }

  void mult() {
    cout << arg1 << " * " << arg2 << " = " << (arg1 * arg2) << endl;
  }
};

// function Template Argument Deduction
template <typename T>
T multiply(T value1, T value2) {
  T output;
  return output;
}

// ??? did way too much,
  // I thought I needed pointer arithmatic to force typecasting
// template non-type template arguments with
// template <class T>
// auto arrSum(T arr[], int start, int stop) {
//
//   template <typename S>
//   S sumWhenTypeDefined(S array, S output) {
//
//   }
//
//   // Valid output types
//   int i = 0;
//   float f = 0;
//   double d = 0;
//
//
//   // Cast output type to input type
//   void* output;
//   string initVal = "0.0";
//   char inputType = *typeid(arr).name();
//
//   if (inputType == 'i') {
//
//   }
//   else if (inputType == 'f') {
//
//   }
//   else {
//
//   }
//
// }

template <typename T>
T arrSum(T arr[], int start, int stop) {
  T output = 0;

  for (int i = start; i <= stop; i++) {
    output += arr[i];
  }
  return output;
}

template <typename T>
string ptrToString(T pointer) {
  const void* address = static_cast<const void*>(pointer);
  stringstream ss;
  ss << address;
  string outputString = ss.str();
  return outputString;
}

// slices string
string stringSlice(string inputString, int start, int stop) {
  string outputString;

  for (int i = start; i <= stop; i++) {
    outputString += inputString[i];

    #if DEBUG
    cout << "Cycle: " << i << "outputString: " << outputString << endl;
    #endif
  }

  return outputString;
}

//===========================================================================//

int main() {

  cout << "\nTest 1, template class" << endl;
  Test1<double> foo(5, 2);
  foo.displayType();
  foo.mult();

/* 100 will always be seen as an int,
   100.0 always as a double unless stated that it is a float */

  // when 100 is entered compiler will throw an error
  float multiplied = multiply(1.5, 100.0);
  cout << "\nTest 2, template function" << endl;
  cout << "Should be int: " << typeid(multiply(2, 10)).name() <<
          "\nShould be float: " << typeid(multiply(1.5f, 2.5f)).name() <<
          "\nValue is: " << multiplied << "\nShould be float: " <<
          typeid(multiplied).name() << endl;

  int intArr[] = {5,5,5};
  float floatArr[] = {1.5,1.5,1.5};
  double doubleArr[] = {1.5,1.5,1.5};
  cout << "\nTest 3, non-type template arguments\n" <<
          "should be int: " << arrSum(intArr, 0, 3)
          << typeid(arrSum(intArr, 0, 3)).name() <<
          "\nshould be float: " << arrSum(floatArr, 0, 3)
          << typeid(arrSum(floatArr, 0, 3)).name() <<
          "\nshould be double: " << arrSum(doubleArr, 0, 3)
          << typeid(arrSum(doubleArr, 0, 3)).name() << endl;

  cout << "\nTest 3, typeid to char" << endl;
  double test3 = 0.5;
  char typeOfTest3 = *typeid(test3).name();
  cout << "char: " << typeOfTest3 << endl;
  // '' these commas mean it's of type char!
  if (typeOfTest3 == 'f') {
    cout << "true" << endl;
  }
  else {
    cout << "false" << endl;
  }

  cout << "\nTest 4, void pointer" << endl;
  string initVal = "0";
  void* voidPtr;
  float castToThis = stof(initVal);
  voidPtr = &castToThis;
  float test4 = *(static_cast<float*>(voidPtr));
  cout << test4 << " of type: " <<
  typeid(test4).name() << endl;

  /*
  Notice that last three characters never change? cool
  You might be able to convert a string to a pointer,
  and a pointer to a string. This allows messing with the
  pointer type.
  */
  cout << "\nTest 5, Pointer arithmetic" << endl;
  int n = 5;
  int in = int(n);
  float fn = float(n);
  double dn = double(n);
  int* i = &in;
  float* f = &fn;
  double* d = &dn;
  cout <<   "int:    " << i <<
          "\nfloat:  " << f <<
          "\ndouble: " << d <<
          "\nconvert "
          << endl;

  cout << "\nTest 6, Pointer address to String" << endl;
  int n2 = 5;
  int* n2Ptr = &n2;
  // Source - https://stackoverflow.com/a
  // Posted by Sarfaraz Nawaz
  // Retrieved 2025-12-21, License - CC BY-SA 3.0
  const void* address = static_cast<const void*>(n2Ptr);
  stringstream ss;
  ss << address;
  string name = ss.str();
  string stringTest = "test";
  cout << "Address of n2Ptr as string: " << name <<
          "\nShould be string: " << typeid(name).name() <<
          "\nShould be the same as: " << typeid(stringTest).name() << endl;

  cout << "\nTest 7, Going nuts with pointers" << endl;
  int n3 = 5;
  double n4 = 5;
  int* n3Ptr= &n3;
  double* n4Ptr = &n4;
  string iPtrString = ptrToString(n3Ptr);
  string dPtrString = ptrToString(n4Ptr);
  cout << "int* as string:    " << iPtrString <<
        "\ndouble* as string: " << dPtrString << endl;

  string slicedString = stringSlice(iPtrString, 0, 7);
  string doubleChars = stringSlice(dPtrString, 8, 10);

  string dStringPointer = slicedString + doubleChars;
  cout << "sliced int ptr:    " << slicedString <<
          "\nsliced double ptr:         " << doubleChars <<
          "\ncombined:          " << dStringPointer << endl;

  const char* charArray = dStringPointer.c_str();
  cout << "charArray: " << charArray << endl;

  long int dptrToLongInt = strtol(charArray, nullptr, 0);
  double* newDoublePtr = reinterpret_cast<double*>(dptrToLongInt);

  cout << "As long int: " << dptrToLongInt <<
          "\nAs pointer: " << newDoublePtr <<
          "\nValue stored in pointer: " << *newDoublePtr <<
          " of type: " << typeid(*newDoublePtr).name() << endl;

  return 0;
}
