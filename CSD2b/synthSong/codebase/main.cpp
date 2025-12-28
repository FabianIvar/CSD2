#include "callback.h"
#include "appcontroller.h"
#include <ostream>
using namespace std;
using namespace appController;

#define DEBUG 1
#define STARTUP_MESSAGE 1


//==========================================================================//

int main () {
  cout << endl;
  cout << "Starting program...\n" << endl;

  ScopedMessageThreadEnabler scopedMessageThreadEnabler;
  CustomCallback audioSource(44100);
  JUCEModule juceModule(audioSource);

  // arg 1 = input channels, arg 2 = output channels
  juceModule.init(2, 2);


//==========================================================================//

  #if STARTUP_MESSAGE
    displayTitlescreen();
  #endif

  // cout << "Press q + Enter to quit..." << endl;
  // bool running = true;
  // while (running) {
  //   switch (cin.get()) {
  //     case 'q':
  //       running = false;
  //   }
  // }


//==========================================================================//


  cout << "Closing program...\n" << endl;

  return 0;
}
