#include "additive.h"

// NOTE: would be cool to be able to
// change the wavetype after initialization
// maybe with a 'setwavetype' function.

/* TODO:

- At least one voice (constrain -> input validation)
- Implement setAmplitude function
- Implement setFrequency function

DONE:
- Fix duplicate code

*/


Additive::Additive(
  float _frequency, float _samplerate,
  int _waveType, int _voicesAmt)
    : Synth(_frequency, _samplerate),
      voicesAmt(_voicesAmt), waveType(_waveType) {
  #if DEBUG
    std::cout <<
      "Additive constructor" <<
      "\nFrequency: " << frequency <<
      "\nWave type: " << waveType <<
      "\nVoices amount: " << voicesAmt << "\n"
    << std::endl;
  #endif

  if (waveType == 0) { // Sine
    for (int i = 1; i < voicesAmt + 1; i++) {
      voices.push_back(new Sine(
        frequency * i, samplerate));
    }
  }
  else if (waveType == 1) { // Square
    for (int i = 1; i < voicesAmt + 1; i++) {
      voices.push_back(new Square(
        frequency * i, samplerate));
    }
  }
  else if (waveType == 2) { // Saw
    for (int i = 1; i < voicesAmt + 1; i++) {
        voices.push_back(new Saw(
          frequency * i, samplerate));
    }
  }
}


Additive::~Additive() {
  for_each(voices.begin(), voices.end(),
    Utils::entity_deleter<Oscillator>());

  std::vector<Oscillator*>::iterator new_end =
    remove(voices.begin(), voices.end(),
      static_cast<Oscillator*>(nullptr));

  voices.erase(new_end, voices.end());

  #if DEBUG
    std::cout <<
    "Additive Destroyed"
    << std::endl;
  #endif
}

void Additive::calculate() {

  float sampleCalc = 0.0f;
  for (auto i : voices) {
    sampleCalc += i->getSample();
    i->tick();
  }
  /* _sample to prevent confusion,
  the variable name 'sample' is already
  used inside the class 'Oscillator' */
  this->_sample = sampleCalc / voicesAmt;
}
