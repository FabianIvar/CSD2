#include "additive.h"

// NOTE: would be cool to be able to
// change the wavetype after initialization
// maybe with a 'setwavetype' function.

/* TODO:

- At least one voice
  (constrain -> input validation)
- Implement setPartialAmplitude function
- Implement setFrequency function

DONE:
- Fix duplicate code

*/


Additive::Additive(
  float _frequency, float _samplerate,
  int _waveType, int _voicesAmt)
    : Synth(_frequency, _samplerate),
    partialAmp(static_cast<size_t>(_voicesAmt),
      1.0f),
      voicesAmt(_voicesAmt),
      waveType(_waveType)
       {

  #if DEBUG
    std::cout <<
      "Additive constructor" <<
      "\nFrequency: " << frequency <<
      "\nWave type: " << waveType <<
      "\nVoices amount: " << voicesAmt << "\n"
    << std::endl;

    for (auto i : partialAmp)
    std::cout << i << std::endl;
  #endif

  for (int i = 1; i < voicesAmt + 1; i++) {
    voices.push_back(*setWaveType(waveType));
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

// TODO: constrain to voicesAmt
void Additive::setOscAmplitude(int oscNum,
  float amp) {
  partialAmp[static_cast<size_t>(oscNum)] = amp;
}

void Additive::calculate() {

  float sampleCalc = 0.0f;
  // float freqMultiplier = 1.0f;
  int num = 1u;
  for (auto i : voices) {
    i->setAmplitude(
      partialAmp[static_cast<size_t>(num) -1]);
    i->setFrequency(
      frequency * num);

    sampleCalc += i->getSample();
    num++;
    i->tick();
  }

  /* _sample to prevent confusion,
  the variable name 'sample' is already
  used inside the class 'Oscillator' */
  this->_sample =
    (sampleCalc / voicesAmt) * amplitude;
}
