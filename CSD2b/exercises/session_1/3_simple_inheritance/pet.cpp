#include "pet.h"

//constructor and destructor
Pet::Pet(std::string name)
{
  std::cout << "Pet::Pet - constructor, name: "
    << name << "\n";
  this->name = name; // dit is een 'this' pointer, zorgt er voor dat de variabele 'name' mee wordt gegeven aan de rest van de class. -> dit is de constructor namenlijk
}

Pet::~Pet()
{
  std::cout << "Pet::~Pet - destructor, name: "
    << name << "\n";
}

void Pet::sleep()
{
  std::cout << name << " is sleeping\n";
}
void Pet::eat()
{
  std::cout << name << " is eating\n";
}
