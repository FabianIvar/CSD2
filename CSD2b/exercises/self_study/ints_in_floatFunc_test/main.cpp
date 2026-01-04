#include <iostream>
using namespace std;

float testFunc(float value) {
  return (10.0 / 3.0) + value;
}

int main() {
  cout << endl;
  #if DEBUG
  cout <<
    "Starting program...\n"
  << endl;
  #endif
//============================================================================//



  float output = testFunc(1.0f);

  cout << "output: " << output << endl;



//============================================================================//
  #if DEBUG
  cout <<
    "\nProgram finished... shutting down"
  << endl;
  #endif

  cout << endl;
  return 0;
}
