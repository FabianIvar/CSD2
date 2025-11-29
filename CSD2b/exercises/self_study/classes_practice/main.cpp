#include <iostream>
using namespace std;

class Pet {
public:
  Pet(string name);
  void action();
protected:
  string name;
};

Pet::Pet(string name) {
  cout << "Constructor Pet\n" << endl;
  cout << "My pet is called " << name << endl;
  this->name = name;
}

void Pet::action() {
  cout << name << " does a flip!" << endl;
}

class Dog : public Pet {
public:
  Dog(string name);
  void bark() {
    cout << name <<" stays silent" << endl;
  };
  void bark(int amount); // method overloading!
};

// : Pet(name) snap ik nog niet helemaal, maar vgm is dit hoe je zorgt dat name weer gebruikt kan worden in alle functies doordat je wat je intypt bij de class dog ook naar pet gaat en bij pet heb je die this-> pointer
Dog::Dog(string name) : Pet(name) {
  cout << "constructor Dog\n" << endl;
  cout << "My dog is called " << name << endl;;
}

void Dog::bark(int amount) {
  cout << name << ": ";
  for (int i = 0; i < amount; i++) {
    if (i == 0) {
      cout << "'bark";
    } else {
      cout << " bark";
    }

  };
  cout << "'" << endl;
}


int main() {
  Dog myPet("George");
  myPet.action();
  myPet.bark();
  myPet.bark(6);
  return 0;
}
