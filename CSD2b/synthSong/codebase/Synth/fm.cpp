#include "fm.h"

// Ratio = at least 0.5

Fm::Fm(float _frequency, float _samplerate,
  int carrierWaveType, int modulatorWaveType,
  float ratio, float modulationIndex)
    : Synth(_frequency, _samplerate),
      carrier(nullptr), modulator(nullptr),
      carWaveType(carrierWaveType),
      modWaveType(modulatorWaveType),
      inverseRatio(1 / ratio),
      modIndex(modulationIndex) {

  #if DEBUG
    std::cout <<
      "Fm constructor" <<
      "\nFrequency: " << frequency <<
      "\nRatio: " << ratio <<
      "\nWave type modulator: " << modulatorWaveType <<
      "\nWave type carrier: " << carrierWaveType <<
      "\nModulation index: " << modulationIndex << "\n"
    << std::endl;
  #endif

//==============================================//

  // setWaveType(modulatorWaveType);
  // modulator = tempOsc;
  // setWaveType(carrierWaveType);
  // carrier = tempOsc;
  // setWaveType('d');

  modulator = new Sine(220.0f, samplerate);
  carrier = new Sine(230.0f, samplerate);

  std::cout <<
    "Modulator address: " << modulator <<
    "\nCarrier address: " << carrier
  << std::endl;

}

// TODO: add amplitude  Initial frequency = 0;


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
      "Fm Destroyed"
    << std::endl;
  #endif

  delete modulator;
  modulator = nullptr;
  delete carrier;
  carrier = nullptr;
  // delete tempOsc;
  // tempOsc = nullptr;
}
