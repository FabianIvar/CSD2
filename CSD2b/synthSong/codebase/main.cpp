#include "callback.h"
#include <iostream>
using namespace std;

// QUESTION: what does thread do? is it included in the std namespace?



#define DEBUG 1


//==========================================================================//


int main () {

  ScopedMessageThreadEnabler scopedMessageThreadEnabler;
  CustomCallback audioSource(44100);
  JUCEModule juceModule(audioSource);

  double actualSampleRate = audioSource.getSampleRate;

  #if DEBUG
  cout << "\nActual samplerate: " << actualSampleRate << endl;
  #endif

  // arg 1 = input channels, arg 2 = output channels
  juceModule.init(2, 2);


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
