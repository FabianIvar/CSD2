#include <iostream>
using namespace std;
#define DEBUG 1


int main() {
  cout << endl;
  #if DEBUG
  cout <<
    "Starting program...\n"
  << endl;
  #endif
//============================================================================//

  double test = 1.5;
  int test2 = int(test);

// when casting double or float to int, decimal points are removed

/*
Difference between int(x) and static_cast<int>(x):
In C++ the static_cast<>() will allow the compiler to check whether
the pointer and the data are of same type or not.
If not it will raise incorrect pointer assignment exception during
compilation.
'int(x)' is called C-like casting, and it casts the
value during run-time. Some weird errors are able to happen when
casting like this. Because it is possible to have a pointer point
to for example an int, and then the int can be casted to a char.
when derefrencing that pointer it may generate a rontume error or
it will overwrite some adjecent memory.
*/

  cout <<
    "type is: " << typeid(test).name() <<
    "\ntype changed to: " << typeid(test2).name() <<
    "\nValue stored in test2: " << test2
  << endl;

//============================================================================//
  #if DEBUG
  cout <<
    "\nProgram finished... shutting down"
  << endl;
  #endif

  cout << endl;
  return 0;
}
