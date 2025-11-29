#ifndef _PET_H_ // Dit zijn include guards
#define _PET_H_
#include <iostream>

class Pet
{
public:
  // constructor and destructor
  Pet(std::string name);
  ~Pet();

  // methods
  void sleep();
  void eat();
protected:
  std::string name;
};

#endif
