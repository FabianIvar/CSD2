// Test with runtime polymorphism using pure virtual functions
// NOTE: With dynamic allocation you don't have to create objects you won't use.

#include <iostream>
using namespace std;

class Foo {
public:
  virtual void morph_this() = 0;

};

//============================================================================//

class Bar : public Foo {
public:
  Bar();
  ~Bar();

  void morph_this() override;
};

Bar::Bar() {
  cout << "Bar Constructor" << endl;
}

Bar::~Bar() {
  cout << "Bar Destructor" << endl;
}

void Bar::morph_this() {
  cout << "\nmorph_this function is overridden by Bar" << endl;
}

//============================================================================//

class Foar : public Foo {
public:
  Foar();
  ~Foar();

  void morph_this() override;
};

Foar::Foar() {
  cout << "Foar Constructor" << endl;
}

Foar::~Foar() {
  cout << "Foar Destructor" << endl;
}

void Foar::morph_this() {
    cout << "\nmorph_this function is overridden by Foar" << endl;
  }


//============================================================================//

int main() {

  cout << "-={Polymorphism Test}=-\n" << endl;

  /*
  Create a pointer to the base class,
  in this case Foo (which is an abstract class)
  */

  Foo* abstractBasePtr;

  /*
  Create an object of the derived class,
  (the object that has a function that should
  replace pure virual function of the bass class)
  */

  Bar derivedBar;
  Foar derivedFoar;

  cout << "\n==================\n" << endl;
  //==========================================================================//

  // Let user pick what object overrides the 'morph_this();' function
  string pickedObj;
  cout << "Pick an object\nOptions: bar | foar" << endl;
  getline(cin, pickedObj);

  // compare strings. 0 if strings are the same, 1 if strings are different.
  if (!(pickedObj.compare("bar"))) {
    abstractBasePtr = &derivedBar;
  }
  else if (!(pickedObj.compare("foar"))) {
    abstractBasePtr = &derivedFoar;
  }

  abstractBasePtr->morph_this();

  cout << "\n==================\n" << endl;

  return 0;

}
