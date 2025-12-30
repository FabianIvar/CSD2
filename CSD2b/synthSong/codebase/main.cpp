#include "callback.h"
#include <ostream>

//==========================================================================//

int main () {

  ScopedMessageThreadEnabler scopedMessageThreadEnabler;
  CustomCallback audioSource(44100);
  JUCEModule juceModule(audioSource);

  // arg 1 = input channels, arg 2 = output channels
  juceModule.init(2, 2);

//==========================================================================//

  // This piece of code makes it so that the program keeps running.
  // TODO: add 'press q+enter to quit...' message to appcontroller
  std::cout << "\nPress q + Enter to quit...\n" << std::endl;
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
