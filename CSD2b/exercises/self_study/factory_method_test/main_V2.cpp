/*
source: https://www.geeksforgeeks.org/cpp/advanced-c-virtual-constructor/#the-factory-method-best
Posted by Kartik: https://www.geeksforgeeks.org/profile/kartik?tab=overview
*/

#include <iostream>
#include <sstream>
using namespace std;
#define DEBUG 1


//============================================================================//


// Abstract class with the pure virtual function 'DisplayAction'
struct Base {

  /* 'Create' is a function with return type 'Base-pointer'

     Weird?? recursion? also static, so only one Create function exists,
     and no object is needed for the create function to be called*/

  static Base* Create(int id);

	Base() {}

  //
	virtual ~Base() {}

  // maybe fix with tuple? tuple can be made with different types.
  // assign nullptr to types that should not be used, then assign the value that
  // is not a pullptr to a new value and voila :)
  virtual tuple<int*,float*,double*> DisplayAction(void* value) = 0;
  // virtual void pv() = 0;
};


//============================================================================//


class Derived1 : public Base {
public:
	Derived1() {
		cout << "Derived1 created" << endl;
	}
	~Derived1() {
		cout << "Derived1 destroyed" << endl;
	}

  tuple<int*,float*,double*> DisplayAction(void* value) override {
		cout << "Action from Derived1" << endl;
    return make_tuple(static_cast<int*>(value), nullptr, nullptr);
	}
};


//============================================================================//


class Derived2 : public Base {
public:
	Derived2() {
		cout << "Derived2 created" << endl;
	}
	~Derived2() {
		cout << "Derived2 destroyed" << endl;
	}

  tuple<int*,float*,double*> DisplayAction(void* value) override {
		cout << "Action from Derived2" << endl;
    return make_tuple(nullptr, static_cast<float*>(value), nullptr);
	}
};


//============================================================================//


class Derived3 : public Base {
public:
	Derived3() {
		cout << "Derived3 created" << endl;
	}
	~Derived3() {
		cout << "Derived3 destroyed" << endl;
	}

  tuple<int*,float*,double*> DisplayAction(void* value) override {
		cout << "Action from Derived3" << endl;
    return make_tuple(nullptr, nullptr, static_cast<double*>(value));
	}
};


//============================================================================//


// Factory 🏭 that creates the object according to the requirement
class Factory {
public:

    // Method that creates the object
  Base* create(char id) {

		// Just expand the if-else ladder, if new Derived class is created
		// User code need not be recompiled to create newly added class objects
    if( id == 'i') {return new Derived1;}
    else if( id == 'f') {return new Derived2;}
    else if(id == 'd') {return new Derived3;}
	}
};


//============================================================================//


class User {
private:
  Base* pBase;

public:

  // constructor inherits from
  User(char input) : pBase(nullptr) {

		// Receives an object of Base hierarchy at runtime
		// int input;
    //
		// cout << "Enter ID (1, 2 or 3): ";
		// cin >> input;

    while((input != 'i') && (input != 'f') && (input != 'd')) {
			cout << "Enter ID (1, 2 or 3 only): ";
			cin >> input;
		}

		// Get object from the "Virtual Constructor"
		Factory f;
		pBase = f.create(input);
	}

    // When user object goes out of scope, delete pBase object
	~User() {
		if(pBase) {
			delete pBase;
			pBase = nullptr;
		}
	}

	// Delegates to actual object
  // Is this really needed?
  tuple<int*,float*,double*> Action(void* value) {
    pBase->DisplayAction(value);
	}
};

// Consumer of User (UTILITY) class
int main() {
  int value1 = 1;
  float value2 = 1.5;
  void* value1Void = static_cast<void*>(&value1);
  void* value2Void = static_cast<void*>(&value2);

  User* user = new User('i');
  User* user2 = new User('f');

	// Action required on any of Derived objects
  user->Action(value1Void); // should be get
  user2->Action(value2Void);

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
  delete user2;
  user2 = nullptr;

#if DEBUG
    cout << "does user pointer still exist: " << user << endl;
#endif

  user = nullptr;

#if DEBUG
    cout << "and now?: " << user << endl;
#endif

	return 0;
}
