#include <iostream>
#include "utils.h"
#include <sstream>
using namespace std;
using namespace utils;

// template <typename T>
// T arrSum(T arr[], int start, int stop) {
//   T output = 0;
//
//   for (int i = start; i < stop; i++) {
//     output += arr[i];
//   }
//   return output;
// }

template <typename T>
void* toVoidPtr(T pointer) {
  return static_cast<void*>(pointer);
}

string toString(void* inputVoidPtr) {
  string outputString;
  stringstream ss;
  ss << inputVoidPtr;
  ss >> outputString;
  return outputString;
}

template <typename T> T subject = T(44.5);

int main() {
  cout << endl;
  // struct T {// Baseclass type to put into array
  //   virtual void dispType() = 0;};
  // struct C1 : public T {// Comparator1
  //   void dispType() override;};
  // struct C2 : public T {// Comparator2
  //   virtual void dispType() = 0;};
  // struct C3 : public T {// Comparator3
  //   virtual void dispType() = 0;};

  void* subjectPtr = &subject<int>;
  float* floatPtr = &subject<float>;
  double* doublePtr = &subject<double>;
  int* intPtr = &subject<int>;

  // void* subjectPtr = static_cast<void*>(subjectPtr0);
  // float* floatPtr = static_cast<void*>(floatPtr0);
  // double* doublePtr = static_cast<void*>(doublePtr0);
  // int* intPtr = static_cast<void*>(intPtr0);

  float testFloat = 5.5f;
  cout << "test 1 (toVoidPtr)" <<
          "\nType was: " << typeid(testFloat).name() <<
          "\ntype is now: " << typeid(toVoidPtr(testFloat)).name() <<
          endl;

  cout << "\ntest 2" << endl;
  string test1 = toString(toVoidPtr(&testFloat));
  cout <<
    "Value: " << testFloat << typeid(testFloat).name() <<
    "\nAddress: " << &testFloat <<
    " " << typeid(&testFloat).name() <<
    "\nAddress as string: " << test1 <<
    " " << typeid(test1).name() << "\n" << endl;

  vector<string> ptrList = {
    toString(toVoidPtr(intPtr)),
    toString(toVoidPtr(floatPtr)),
    toString(toVoidPtr(doublePtr))};

  for (int i = 0; i < ptrList.size(); i++) {
    if (!toString(subjectPtr).compare(ptrList[i])) {
      cout << "subjectPtr points to type: " <<
      i << endl;
    }
  }

  // vector<Comparator*> ptrList = {
  //
  // }

  float newValue = *static_cast<float*>(subjectPtr);

  cout << "Test 3: " <<
        "\nfloatPtr Value:   " << floatPtr <<
        "\nsubjectPtr Value: " << subjectPtr <<
        "\ndoublePtr Value:  " << doublePtr <<
        "\nintPtr Value:     " << intPtr <<
          "\nsubjectPtr size: " << sizeof(subjectPtr) <<
          "\nfloatPtr size: " << sizeof(subjectPtr) <<
          "\nnewValue size: " << sizeof(newValue) <<
          "\nnewValue Value: " << newValue << endl;

// interesting!
  int test2 = 5;
  int* testPtr = nullptr;
  if (true) {
    int addValue = test2 + 2;
    testPtr = &addValue;
  }

  cout << ">>>Test: " << *testPtr << endl;
  int intArray[] = {1,2,3,4};

  // template <class T>
  // int summedArray = arrSum(intArray, 0, 4);

  // cout << "summedArray: " << summedArray << endl;
  cout << endl;
  return 0;
}
