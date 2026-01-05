#include "callback.h"

int main () {

  ScopedMessageThreadEnabler scopedMessageThreadEnabler;
  CustomCallback audioSource(44100);
  JUCEModule juceModule(audioSource);
  juceModule.init(2, 2);
  appCtrl::displayQuitMessage();

  return 0;
}
