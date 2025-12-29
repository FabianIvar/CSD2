#include "callback.h"
#include <ostream>
// #include <thread>
// using namespace std;

#define DEBUG 1
#define STARTUP_MESSAGE 1

//==========================================================================//

int main () {

  ScopedMessageThreadEnabler scopedMessageThreadEnabler;
  CustomCallback audioSource(44100);
  JUCEModule juceModule(audioSource);

  // arg 1 = input channels, arg 2 = output channels
  juceModule.init(2, 2);

//==========================================================================//

  // This piece of code makes it so that the program keeps running.
  std::cout << "Press q + Enter to quit..." << std::endl;
  bool running = true;
  while (running) {
    switch (std::cin.get()) {
      case 'q':
        running = false;
    }
  }

//==========================================================================//


  return 0;
}
