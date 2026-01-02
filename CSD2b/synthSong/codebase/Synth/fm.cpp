#include "fm.h"

Fm::Fm(float _carrierFrequency, float _samplerate,
  int _carrierWaveType, int _modulatorWaveType,
  float _ratio, float _modulationIndex)
    : Synth(_carrierFrequency, _samplerate),
      carrierFrequency(_carrierFrequency),
      carrierWaveType(_carrierWaveType),
      modulatorWaveType(_modulatorWaveType),
      ratio(_ratio),
      modulationIndex(_modulationIndex),
      carrier(nullptr), modulator(nullptr),
      amplitude(0.10f) {

  #if DEBUG
    std::cout <<
      "Fm constructor" <<
      "\nFrequency: " << carrierFrequency <<
      "\nRatio: " << ratio <<
      "\nWave type modulator: " << modulatorWaveType <<
      "\nWave type carrier: " << carrierWaveType <<
      "\nModulation index: " << voicesAmt << "\n"
    << std::endl;
  #endif

//==============================================//

  setWaveType(modulatorWaveType);
  modulator = *tempOsc;
  setWaveType(carrierWaveType);
  carrier = *tempOsc;
  setWaveType('d');

  // tuple<Oscillator*, int> modulatorOsc(modulator,
  //   _modulatorWaveType);
  // tuple<Oscillator*, int> carrierOsc(carrier,
  //   _carrierWaveType);


/* NOTE:
- osc is a typedef for:
  vector<tuple<Oscillator*, int>>
- Variable 'oscillators' contains
  wavetypes of carrier and modulator
  in a vector */

  // osc unPreparedOsc = {modulatorOsc, carrierOsc}
  // osc preparedOsc = setWaveType(unPreparedOsc)

  // add amplitude
}

// TODO: add amplitude  Initial frequency = 0;


void Fm::calculate() {

  std::cout <<
    "carrier: " << carrier <<
    "\nmodulator: " << modulator
  << std::endl;

  modulator->setAmplitude(modulationIndex);
  modulator->setFrequency(carrierFrequency / ratio);
  float modSample = modulator->getSample() * modulationIndex;
  modulator->tick();

  carrier->setFrequency(carrierFrequency + modSample);
  this->_sample = carrier->getSample() * amplitude;
  carrier->tick();
}

// void Fm::calculate(osc input) {
//   for (auto i : input) {
//     switch (get<1>(i)) {
//       case 0:
//         get<0>(i) = new
//     }
//
//   }
// }


Fm::~Fm() {
  delete modulator;
  modulator = nullptr;
  delete carrier;
  carrier = nullptr;
  delete tempOsc;
  tempOsc = nullptr;
}
