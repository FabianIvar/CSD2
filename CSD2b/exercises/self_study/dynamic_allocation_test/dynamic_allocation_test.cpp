// Test with dynamic allocation

#include <iostream>
using namespace std;

class Foo {
public:

  virtual ~Foo();
  virtual void morph_this() = 0;

};

Foo::~Foo() {
  // delete abstractBasePtr;
  cout << "Foo Destructor" << endl;
}

//============================================================================//

class Bar : public Foo {
public:
  Bar();
  ~Bar() override;

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
  ~Foar() override;

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

  cout << "-={Polymorphism Test}=-" << endl;

  /*
  Create a pointer of the type Foo which is the base class,
  Foo is, in this case, an abstract class.
  */

  Foo* abstractBasePtr;

  /*
  Create an object of the derived class,
  (the object that has a function that should
  replace pure virual function of the bass class)
  */

  // Bar derivedBar;
  // Foar derivedFoar;

  cout << "\n==================\n" << endl;

  //==========================================================================//

  // Let user pick what object overrides the 'morph_this();' function
  string pickedObj;
  cout << "Pick an object\nOptions: bar | foar" << endl;
  getline(cin, pickedObj);

  // compare strings. 0 if strings are the same, 1 if strings are different.
  if (!(pickedObj.compare("bar"))) {
    abstractBasePtr = new Bar();
  }
  else if (!(pickedObj.compare("foar"))) {
    abstractBasePtr = new Foar;
  }
  else {
    cout << "Wrong input, closing program" << endl;
    exit(0);
  }

  abstractBasePtr->morph_this();

  cout << "\n==================\n" << endl;

  delete abstractBasePtr;
  abstractBasePtr = nullptr;

  cout << "\n==================\n" << endl;
  cout << "closing program...\n" << endl;

  return 0;

}
