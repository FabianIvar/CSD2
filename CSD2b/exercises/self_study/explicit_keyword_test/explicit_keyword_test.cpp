#include <iostream>
using namespace std;

template <typename T>
void typeOf(T val) {
  cout << val << " of type: " << typeid(val).name() << endl;
}

/*
When the 'explicit' keyword is not present a constructor with a single argument
becomes a conversion constructor. This constructor allows conversion of the type
of this argument.

Example
===============================================

class NormalClass {
private:
  float stored_value;

  NormalClass(float b) : stored_value(b) {
      
    }

};

int a = 5;
NormalClass testObj(a);

===============================================
This returns f, which means the int a got turned into a float.

implicit conversions like this might not be desirable and can sometimes
cause unexpected errors.
To prevent this from happening you can use the 'explicit' keyword.
With the 'explicit' keyword you prevent implicit type conversions.

Example
===============================================

struct NormalClass {

  explicit NormalClass(float b) {
    std::cout << typeid(b).name() << endl;
    }

};

int a = 5;
NormalClass testObj(a);



*/

class TypeChanger {

public:

  TypeChanger(double y) {
      cout << "TypeChanger Constructor\n" << endl;
      this->y = y;
  }

  void displayNewType() {
    // const type_info& type = typeid(y);
    string type = typeid(y).name();
    cout << "The type of the variable is: " << type << "\n" << endl;

  }

  double getNewValue() {
    auto newValue = y;
    return newValue;
  }

private:
  double y;
};

class ExplicitTest {
private:
  float onlyFloat;

public:
  explicit ExplicitTest(float value = 0.0) : onlyFloat(value) {
    cout << "ExplicitTest Constructor" << endl;
    cout << value << "\n" << endl;
    // cout << "Value is " << value << " of type " << typeid(value).name() << endl;
  }

  bool operator == (ExplicitTest inputVariable) {
    return (onlyFloat == inputVariable.onlyFloat);
  }

  ~ExplicitTest(){
    cout << "ExplicitTest Destructor\n" << endl;

  }
};

int main() {
  int x = 12;

  TypeChanger value(x);
  value.displayNewType();
  auto newValue = value.getNewValue();

  cout << "Old value was: ";
  typeOf(x);

  cout << "New value is: ";
  typeOf(newValue);

  cout << "\nTesting an explicit constructor\n" << endl;

  float z = 5.5;

  ExplicitTest test(x); // Should throw an error.

  if (test == 12) {
    cout << "Is the same!" << endl;
  }
  else {
    cout << "Not the same :(" << endl;
  }

  cout << "\nFinished, closing program...\n" << endl;

  return 0;
}
