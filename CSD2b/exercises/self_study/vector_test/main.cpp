#include <iostream>
#include <algorithm>
#include <functional>

// #include <vector>
using namespace std;
#define DEBUG 1


struct Oscillator {
  Oscillator(){}
  virtual ~Oscillator(){
    cout << "Oscillator Destructor" << endl;
  }
  virtual void calculate() = 0;
};

struct Sine : public Oscillator {
  Sine(){}
  ~Sine() override {
    cout << "Sine Destructor" << endl;
  }
  void calculate() override {
    cout << "AYOO" << endl;
  }
};

template <typename E>
struct entity_deleter {
/*
Source - https://stackoverflow.com/a
Posted by rlbond, modified by community.
Retrieved 2025-12-29, License - CC BY-SA 2.5
*/

  void operator()(E*& entity) {
    delete entity;
    entity = nullptr;
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

  int voicesAmt = 3;
  vector<Oscillator*> voices;

  for (int i = 0; i < voicesAmt; i++) {
      voices.push_back(new Sine());
  }

  for (auto i : voices) i->calculate();


  // applies entity_deleter on every object stored in the vector
  for_each(voices.begin(), voices.end(), entity_deleter<Oscillator>());
  vector<Oscillator*>::iterator new_end =
    remove(voices.begin(), voices.end(), static_cast<Oscillator*>(nullptr));
  voices.erase(new_end, voices.end());





//============================================================================//
  #if DEBUG
  cout <<
    "\nProgram finished... shutting down"
  << endl;
  #endif

  cout << endl;
  return 0;
}

// Source - https://stackoverflow.com/a
// Posted by rlbond, modified by community.
// Retrieved 2025-12-29, License - CC BY-SA 2.5
