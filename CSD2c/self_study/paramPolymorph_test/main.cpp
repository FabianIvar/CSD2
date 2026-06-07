#include <iostream>
using namespace std;
#define DEBUG 1



struct Foo {
  Foo(float important, float information) {
    cout << "Foo Constructor" << endl;
    m_important = important;
    m_information = information;
  }

  virtual ~Foo() {
    cout << "Foo Destructor" << endl;
  }

  virtual float calculate() = 0;

protected:
  float m_important;
  float m_information;
};



struct Bar : public Foo {
  Bar(float imp, float inf) : Foo(imp, inf) {
    cout << "Bar Constructor" << endl;
  }

  ~Bar() override { cout << "Bar Destructor" << endl; }

  float calculate() override {
    return m_important - m_information;
  }
};



int main() {
  cout << endl;
  #if DEBUG
  cout <<
    "Starting program...\n"
  << endl;
  #endif
//============================================================================//

  Foo* foo = new Bar(5.0, 3.0);
  float output = foo->calculate();
  cout << "output: " << output << endl;
  delete foo;
  foo = nullptr;

//============================================================================//
  #if DEBUG
  cout <<
    "\nProgram finished... shutting down"
  << endl;
  #endif

  cout << endl;
  return 0;
}
