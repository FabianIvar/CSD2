/*
source: https://www.geeksforgeeks.org/cpp/advanced-c-virtual-constructor/#the-factory-method-best
Posted by Kartik: https://www.geeksforgeeks.org/profile/kartik?tab=overview
*/

#include <iostream>
#include <sstream>
using namespace std;
#define DEBUG 0


//============================================================================//


// Abstract class with the pure virtual function 'DisplayAction'
struct Base {

  static Base* Create(int id);

	Base() {}

	virtual ~Base() {}

  virtual tuple<void*,char> DisplayAction() = 0;
  // virtual float* DisplayAction(float* value);
  // virtual double* DisplayAction(double* value);
};


//============================================================================//


class Derived1 : public Base {
  int* intPtr;
public:
  Derived1(void* voidPtr) {
    this->intPtr = static_cast<int*>(voidPtr);
		cout << "Derived1 created" << endl;
	}
	~Derived1() {
		cout << "Derived1 destroyed" << endl;
	}

  int* DisplayAction() {
    return intPtr;}
};


//============================================================================//


class Derived2 : public Base {
  float* floatPtr;
public:
  Derived2(void* voidPtr) {
    this->floatPtr = static_cast<float*>(voidPtr);
		cout << "Derived2 created" << endl;
	}
	~Derived2() {
		cout << "Derived2 destroyed" << endl;
	}

  float* DisplayAction() {
    return floatPtr;}
};


//============================================================================//


class Derived3 : public Base {
  double* doublePtr;
public:
  Derived3(void* voidPtr) {
    this->doublePtr = static_cast<double*>(voidPtr);
		cout << "Derived3 created" << endl;
	}
	~Derived3() {
		cout << "Derived3 destroyed" << endl;
	}

  double* DisplayAction() {
    return doublePtr;}
};


//============================================================================//


// Factory 🏭 that creates the object according to the requirement
class Factory {
public:

    // Method that creates the object
  Base* create(char id, void* voidPtr) {

		// Just expand the if-else ladder, if new Derived class is created
		// User code need not be recompiled to create newly added class objects
    if( id == 'i') {return new Derived1(voidPtr);}
    else if( id == 'f') {return new Derived2(voidPtr);}
    else if(id == 'd') {return new Derived3(voidPtr);}
	}
};


//============================================================================//


class User {

  Base* pBase;
  char input;

public:
  User(char input, void* voidPtr) : pBase(nullptr) {
    this->input = input;

    while((input != 'i') && (input != 'f') && (input != 'd')) {
			cout << "Enter ID (1, 2 or 3 only): ";
			cin >> input;}

		Factory f;
    pBase = f.create(input,voidPtr);
	}

	~User() {
		if(pBase) {
			delete pBase;
			pBase = nullptr;
		}
	}

  // Base* Action() {
  //   pBase->DisplayAction();
  // }
};


//============================================================================//


int main() {
  int value1 = 1;
  // float value2 = 1.5;
  void* value1Void = static_cast<void*>(&value1);
  // void* value2Void = static_cast<void*>(&value2);
  User* user = new User('i',value1Void);
  // User* user2 = new User('f',value2Void);
  user->DisplayAction(); // should be get



  // user2->Action(value2Void);

  /* NOTE:
  pointer stays assigned to the memory location of the User object,
  even after it is deleted. Assign nullptr to free up memory
  */

  char charArray[] = "abc";

#if DEBUG
    cout << "\ntype of variable: " << user << endl;
    cout << "size of char array: %b\n" << sizeof(charArray) << endl;
#endif

	delete user;
  // delete user2;
  // user2 = nullptr;

#if DEBUG
    cout << "does user pointer still exist: " << user << endl;
#endif

  user = nullptr;

#if DEBUG
    cout << "and now?: " << user << endl;
#endif

	return 0;
}
