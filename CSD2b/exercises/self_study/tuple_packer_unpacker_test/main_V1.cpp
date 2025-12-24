#include <iostream>
#include <sstream>
using namespace std;

//============================================================================//
//
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

/*
1) Cast the input void pointer to int float and double pointers
2) Cast the pointer back to type 'void*'
3) Store the address of the void pointer in a string with stringstream
4) Compare the address to the address of the input value.

explanation: When casting a float* to void* the address stays the same.
             That means, when you cast a void* back to its original type,
             the address will also stay the same.
             Using this principle you can deduce the type of the void pointer
             before it was casted. */

// class prep {
//   auto prepared_value = input;
// public
//   prep(int input) : prepared_value
//   prep(float input)
//   prep(double input)
// }

void deducePtrType(void* subject) {

  string subject = toString(inputVoidPtr);
  int intPtr = *static_cast<int*>(inputVoidPtr);
  float floatPtr = *static_cast<float*>(inputVoidPtr);
  double doublePtr = *static_cast<double*>(inputVoidPtr);

  vector<string> comparator = {
    toString(static_cast<void*>(intPtr)),
    toString(static_cast<void*>(floatPtr)),
    toString(static_cast<void*>(doublePtr))};

  cout << "subject: " << subject << endl;

  for (int i = 0; i < 3; i++) {
    // if(!(subject.compare(comparator[i]))) {
      cout << i << " -> " << comparator[i] << endl;
      cout << endl;
      // return "ifd"[i];
    // }
  }

}


//============================================================================//


int main() {
  float testVal = 5.0f;
  int* intPtr = &inputVal;
  float* floatPtr = &inputVal;
  double* doublePtr = &inputVal;
  void* voidPtr = &inputVal;

  string stringTest = toString(voidPtr);
  char deducedType = deduceType(voidPtr);

  cout <<
    "stringTest: " << stringTest << " of type: " <<
    typeid(stringTest).name() <<
    "\n\ndeduceType: " << deducedType << "\n" << endl;


  cout << "closing program..." << endl;
  return 0;
}
