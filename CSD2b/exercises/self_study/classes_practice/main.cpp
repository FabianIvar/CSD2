#include <iostream>
using namespace std;

class Pet {
public:
  Pet(string name);
  void action();
  void drink();
protected:
  string name;
};

Pet::Pet(string name) {
  cout << "\n===============" << endl;
  cout << "Constructor Pet" << endl;
  cout << "===============\n" << endl;
  cout << "My pet is called " << name << endl;
  this->name = name;
}

void Pet::action() {
  cout << name << " does a flip!" << endl;
}

void Pet::drink() {
  cout << name << " drinks some water.." << endl;
}

class Dog : public Pet {
public:
  Dog(string name);
  void sound() {
    cout << name <<" stays silent" << endl;
  }
  void sound(int amount); // method overloading!
};

/*
Constructor delegation in inheritance
dit is hoe je zorgt dat name weer gebruikt kan worden in alle functies doordat je wat je intypt bij de class dog ook naar pet gaat en bij pet heb je
die 'this->' pointer
*/

// constructor delegation
Dog::Dog(string name) : Pet(name) {
  cout << "\n===============" << endl;
  cout << "constructor Dog" << endl;
  cout << "===============\n" << endl;
  cout << name << " is a dog" << endl;
}

void Dog::sound(int amount) {
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

// Is it better to ask for pet name in base class constructor?
// Or is it okay to set the name in the main() function?

class Cat : public Pet {
public:
  Cat(string name);
  void sound() {
    cout << name <<" stays silent" << endl;
  }
  void sound(int amount);
};

Cat::Cat(string name) : Pet(name) {
  cout << "\n===============" << endl;
  cout << "constructor Cat" << endl;
  cout << "===============\n" << endl;
  cout << "is a cat" << endl;
}

// duplicate code, but doesn't matter for this test
void Cat::sound(int amount) {
  cout << name << ": ";
  for (int i = 0; i < amount; i++) {
    if (i == 0) {
      cout << "'meow";
    } else {
      cout << " meow";
    }
  };
  cout << "'" << endl;
}

int main() {
  string pet_name;
  cout << "I have a pet called ";
  getline(cin, pet_name);

  string species;
  cout << pet_name << " is a ";
  getline(cin, species);

  Cat my_pet(pet_name);

  my_pet.action();
  my_pet.sound();
  my_pet.sound(6);
  my_pet.drink();
  return 0;
}
