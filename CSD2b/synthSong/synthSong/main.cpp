#include <iostream>
#include "customCallback.h"
using namespace std;

// 1 to enable debug comments 0 to disable debug
#define DEBUG 0

int main() {

  // wtf doet dit?
  ScopedMessageThreadEnabler scopedMessageThreadEnabler;

// sets sampleRate
  CustomCallback audioSource (48000);


  void setSamplerate(float samplerate);
  JUCEModule juceModule (audioSource);
  juceModule.init(1,1);




  cout << "test" << endl;

  #if DEBUG
  cout << "whats up gamers" << endl;
  #endif

  std::cout << "Press q + Enter to quit..." << std::endl;
  bool running = true;
  while (running) {
      switch (std::cin.get()) {
          case 'q':
              running = false;
              break;
      }
  // here comes code that's performed 48000 times per second


  }







  return 0;
}
