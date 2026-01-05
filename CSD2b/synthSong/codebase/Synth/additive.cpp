#include "additive.h"

Additive::Additive(
  float _frequency, float _samplerate,
  int _waveType, int _voicesAmt)
    : Synth(_frequency, _samplerate),
    partialAmp(static_cast<size_t>(_voicesAmt),1.0f),
    voicesAmt(_voicesAmt), waveType(_waveType) {

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

  /* Create oscillators with the right
     wavetype for every voice */
  for (int i = 1; i < voicesAmt + 1; i++) {
    voices.push_back(*setWaveType(waveType));
  }
}

/* Using Utils entity_deleter
   See ../utils.h for credits */
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

void Additive::setOscAmplitude(int oscNum,
  float amp) {
  partialAmp[static_cast<size_t>(oscNum)] = amp;
}

void Additive::calculate() {

  float sampleCalc = 0.0f;
  int partialNum = 1u;
  for (auto i : voices) {
    i->setAmplitude(
      partialAmp[static_cast<size_t>(partialNum) -1]);
    i->setFrequency(
      frequency * partialNum);

    sampleCalc += i->getSample();
    partialNum++;
    i->tick();
  }

  /* '_sample' to avoid confusion,
  the variable name 'sample' (without '_') is
  already in use by the class 'Oscillator' */
  this->_sample =
    (sampleCalc / voicesAmt) * amplitude;
}
