#include "fm.h"

Fm::Fm(float _frequency, float _samplerate,
  int carrierWaveType, int modulatorWaveType,
  float ratio, float modulationIndex)
    : Synth(_frequency, _samplerate),
      carrier(nullptr), modulator(nullptr),
      carWaveType(carrierWaveType),
      modWaveType(modulatorWaveType),
      inverseRatio(1 / ratio),
      modIndex(modulationIndex) {

  modulator = *setWaveType(modulatorWaveType);
  carrier = *setWaveType(carrierWaveType);

  #if DEBUG
  std::cout <<
    "\nFm constructor" <<
    "\nFrequency: " << frequency <<
    "\nRatio: " << ratio <<
    "\nWave type modulator: " << modulatorWaveType <<
    "\nWave type carrier: " << carrierWaveType <<
    "\nModulation index: " << modulationIndex <<
    "\nModulator address: " << modulator <<
    "\nCarrier address: " << carrier << "\n"
  << std::endl;
  #endif

}

void Fm::calculate() {

  float modSignal = 0.0f;
  float modFrequency = inverseRatio * frequency;

// modulator deviation
  modulator->setFrequency(modFrequency);
  modulator->setAmplitude(modIndex * modFrequency);
  modSignal = modulator->getSample();
  modulator->tick();

// carrier frequency
carrier->setFrequency(frequency + modSignal);
// carrier amplitude
  carrier->setAmplitude(0.2f);
// sample output
  _sample = carrier->getSample();
  carrier->tick();

}

Fm::~Fm() {

  #if DEBUG
    std::cout <<
      "\nFm Destroyed"
      "\nModulator: " << modulator << " Destroyed"
      "\nCarrier: " << carrier << " Destroyed\n"
    << std::endl;
  #endif

  delete modulator;
  modulator = nullptr;
  delete carrier;
  carrier = nullptr;
}
