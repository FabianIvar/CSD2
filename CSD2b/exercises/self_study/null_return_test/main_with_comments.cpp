#include <iostream>
#include <sstream>
using namespace std;

#define DEBUG 1

// C++ Program to illustrate the factory method
// for delegating the construction of the
// object to virtual static function
// source: https://www.geeksforgeeks.org/cpp/advanced-c-virtual-constructor/#the-factory-method-best
// Posted by Kartik: https://www.geeksforgeeks.org/profile/kartik?tab=overview

// ----- LIBRARY CODE START FROM HERE -----
struct Base {

	// The "Virtual Constructor"
  static Base* Create(int id); // type = Base pointer, argument id is an integer

	Base() {}

	// Ensures to invoke actual object destructor
	virtual ~Base() {}

	// An interface
	virtual void DisplayAction() = 0;
};

class Derived1 : public Base {
public:
	Derived1() {
		cout << "Derived1 created" << endl;
	}

	~Derived1() {
		cout << "Derived1 destroyed" << endl;
	}

	void DisplayAction() override {
		cout << "Action from Derived1" << endl;
	}
};

class Derived2 : public Base {
public:
	Derived2() {
		cout << "Derived2 created" << endl;
	}

	~Derived2() {
		cout << "Derived2 destroyed" << endl;
	}

	void DisplayAction() override {
		cout << "Action from Derived2" << endl;
	}
};

class Derived3 : public Base {
public:
	Derived3() {
		cout << "Derived3 created" << endl;
	}

	~Derived3() {
		cout << "Derived3 destroyed" << endl;
	}

	void DisplayAction() override {
		cout << "Action from Derived3" << endl;
	}
};

// Create a factory that creates the object
// according to the requirement
class Factory {
public:

    // Method that creates the object
	Base* create(int id) {

		// Just expand the if-else ladder, if new Derived class is created
		// User code need not be recompiled to create newly added class objects
		if( id == 1 )
			return new Derived1;
		else if( id == 2 )
			return new Derived2;
		else
			return new Derived3;
	}
};
// ----- LIBRARY CODE ENDS HERE -----

class User {
  // class is private by default, so there is no need for "private:"
  Base* pBase;
public:
	User() : pBase(nullptr) {

		// Receives an object of Base hierarchy at runtime
		int input;

		cout << "Enter ID (1, 2 or 3): ";
		cin >> input;

		while((input != 1) && (input != 2) && (input != 3)) {
			cout << "Enter ID (1, 2 or 3 only): ";
			cin >> input;
		}

		// Get object from the "Virtual Constructor"
		Factory f;
		pBase = f.create(input);
	}

	~User() {
		if(pBase) {
			delete pBase;
			pBase = nullptr;
		}
	}

	// Delegates to actual object
	void Action() {
		pBase->DisplayAction();
	}

};

// Consumer of User (UTILITY) class
int main() {
	User* user = new User();

	// Action required on any of Derived objects
  user->Action(); // should be get

  /* NOTE:
  pointer stays assigned to the memory location of the User object,
  even after it is deleted. Assign nullptr to free up memory
  */

#if DEBUG
    cout << "type of variable: " << user << endl; #endif

	delete user;

#if DEBUG
    cout << "does user pointer still exist: " << user << endl; #endif

  user = nullptr;

#if DEBUG
    cout << "and now?: " << user << endl; #endif

	return 0;
}
