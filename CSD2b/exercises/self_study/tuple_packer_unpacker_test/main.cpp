#include <iostream>
#include <sstream>
using namespace std;
#define DEBUG 0


//============================================================================//

// struct Base {
//   static Base* create(int id, void* voidPtr);
//
//   virtual tuple<void*, char> getTuple() = 0;
//   Base(){ }
// };
//
// class Derived1 : public Base {
//   void* voidPtr;
//
// public:
//   Derived1(void* voidPtr) {
//     cout << "Derived1 Constructor" << endl;
//     this->voidPtr = voidPtr;
//   }
//
//   tuple<void*,char> getTuple() override {
//     return make_tuple(voidPtr,'i');
//   }
// };
//
// class Derived2 : public Base {
//   void* voidPtr;
//
// public:
//   Derived2(void* voidPtr) {
//     cout << "Derived1 Constructor" << endl;
//     this->voidPtr = voidPtr;
//   }
//
//   tuple<void*,char> getTuple() override {
//     return make_tuple(voidPtr,'f');
//   }
// };
//
// class Derived3 : public Base {
//   void* voidPtr;
//
// public:
//   Derived3(void* voidPtr) {
//     cout << "Derived1 Constructor" << endl;
//     this->voidPtr = voidPtr;
//   }
//
//   tuple<void*,char> getTuple() override {
//     return make_tuple(voidPtr,'d');
//   }
// };
//
// class T {
//   Base* pBase;
//   char id;
// public:
//   Base* create(void* voidPtr) {
//     if( id == 'i') {pBase = new Derived1(voidPtr);}
//     else if( id == 'f') {pBase = new Derived2(voidPtr);}
//     else if(id == 'd') {pBase = new Derived3(voidPtr);}
//   }
//   tuple<void*,char> get() {
//     pBase->getTuple();
//   }
// };

string toString(void* inputPointer) {
  stringstream ss;
  ss << inputPointer;
  return ss.str();
}

// class prep {
//   auto prepared_value = input;
// public
//   prep(int input) : prepared_value
//   prep(float input)
//   prep(double input)
// }

void toVoidPtr(std::tuple<int*,float*,double*> pointer) {
  int i = 1;
  cout << "tuple test: " << get<1>(pointer) << endl;
  // return static_cast<void*>(pointer);
}


// void deduceType(void* inputVoidPtr) {
//
//   string subject = toString(inputVoidPtr);
//   int valueInt = *static_cast<int*>(inputVoidPtr);
//   float valueFloat = *static_cast<float*>(inputVoidPtr);
//   double valueDouble = *static_cast<double*>(inputVoidPtr);
//
//   vector<string> comparator = {
//     toString(static_cast<void*>(&intPtr)),
//     toString(static_cast<void*>(&floatPtr)),
//     toString(static_cast<void*>(&doublePtr))};
//
//   cout << "subject: " << subject << endl;
//
//   for (int i = 0; i < 3; i++) {
//     // if(!(subject.compare(comparator[i]))) {
//       cout << i << " -> " << comparator[i] << endl;
//       cout << endl;
//       // return "ifd"[i];
//     // }
//   }
// }


//============================================================================//


// Initialize comparator types
template <typename T> T inputVal = T(44.5);

int main() {
  cout << endl;

  // float inputVal = 5.0f;
  // int* intPtr = &inputVal<int>;
  // float* floatPtr = &inputVal<float>;
  // double* doublePtr = &inputVal<double>;
  // void* voidPtr = &inputVal<int>;

  // string stringTest = toString(voidPtr);
  // char deducedType = deduceType(voidPtr);

  tuple<int*,float*,double*> tupleTest(
    &inputVal<float>,
    &inputVal<double>,
    &inputVal<int>);

  toVoidPtr(tupleTest);

  #if DEBUG
  cout <<
    "stringTest: " << stringTest << " of type: " <<
    typeid(stringTest).name() <<
    "\n\ndeduceType: " << deducedType << "\n" << endl;
  #endif

  cout << "closing program..." << endl;
  return 0;
}
