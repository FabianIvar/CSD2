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

int species_to_int(string species) {
  if (species.compare("dog") == 0) {
    // cout << "input was dog" << endl;
    return 1;
  }
  else if (species.compare("cat") == 0) {
    // cout << "input was cat" << endl;
    return 2;
  }
  else {
    return 0;
  }
}

class Dog : public Pet {
public:
  Dog(string name);
  void sound() {
    cout << name <<" stays silent" << endl;
  };
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
  string petName;
  cout << "I have a pet called ";
  getline(cin, petName);

  string species;
  cout << petName << " is a ";
  getline(cin, species);

  int species_as_int = species_to_int(species);


// Switch case doesn't work for creating objects?
  // switch (species_as_int) {
  //   case 1:
  //     Dog myPet(petName);
  //     cout << "dog" << endl;
  //     break;
  //   case 2:
  //     // Cat myPet(petName);
  //     cout << "cat" << endl;
  //     break;
  //   default:
  //     cout << "Doesn't know the species '" << species << "'" << endl;
  //     break;
  // }

  if (species_as_int == 1) {
    Dog myPet(petName);
    Dog* ptr = &myPet;
  }
  else if (species_as_int == 2) {
    Cat myPet(petName);
    Cat* ptr = &myPet;
  }
  else if (species_as_int == 0) {
    cout << "Invalid input... closing program" << endl;
  };

  *ptr.action();
  *ptr.sound();
  *ptr.sound(6);
  *ptr.drink();
  return 0;
}
