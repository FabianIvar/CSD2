#include <iostream>
// #include <vector>
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

  int* intptr = new int(1234);
  cout << "Test 1: " << *intptr << endl;
  delete intptr;
  intptr = nullptr;

  int exampleInt = 123;

  cout << endl;


  int* intptr2[2];
  vector<int*> ptrVector;

  for (int i = 0; i < 2; i++) {
    intptr2[i] = new int(123);
    ptrVector.push_back(intptr2[i]);
  }

  for (auto i : ptrVector) cout << "test: " << i << endl;

  for (auto i : ptrVector) {
    cout << typeid(i).name() << endl;
    delete *i;
    cout << typeid(i).name() << endl;
  }

  cout << "\n" << ptrVector[0] << " " << typeid(ptrVector[0]).name() << endl;




//============================================================================//
  #if DEBUG
  cout <<
    "\nProgram finished... shutting down"
  << endl;
  #endif

  cout << endl;
  return 0;
}
