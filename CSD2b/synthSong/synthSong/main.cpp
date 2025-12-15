#include "callback.h"
#include <iostream>
using namespace std;
// QUESTION: what does thread do? is it included in the std namespace?
// #include <thread>

#define DEBUG 1


//==========================================================================//


int main () {

  ScopedMessageThreadEnabler scopedMessageThreadEnabler;
  CustomCallback audioSource (48000);
  JUCEModule juceModule (audioSource);

  // QUESTION: What does this init do? does it make it stereo?
  juceModule.init (1, 1);


//==========================================================================//


#if DEBUG
  cout << "debug message test" << endl;
#endif

  cout << "Press q + Enter to quit..." << endl;
  bool running = true;
  while (running) {
    switch (cin.get()) {
      case 'q':
        running = false;
    }
  }


//==========================================================================//


  cout << "Closing program...\n" << endl;

  return 0;
}
