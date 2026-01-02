#include "fm.h"

// Ratio = at least 0.5

Fm::Fm(float _carrierFrequency, float _samplerate,
  int _carrierWaveType, int _modulatorWaveType,
  float _ratio, float _modulationIndex)
    : Synth(_carrierFrequency, _samplerate),
      carrier(nullptr), modulator(nullptr),
      carrierWaveType(_carrierWaveType),
      modulatorWaveType(_modulatorWaveType),
      ratio(_ratio),
      modulationIndex(_modulationIndex) {

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

  modulator = new Sine(frequency / ratio, samplerate);
  carrier = new Sine(frequency, samplerate);

  std::cout <<
    "Modulator address: " << modulator <<
    "\nCarrier address: " << carrier
  << std::endl;

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

  // std::cout <<
  //   "carrier: " << carrier <<
  //   "\nmodulator: " << modulator
  // << std::endl;

  float carrierSample = 0.0f;
  float modSample = 0.0f;

  modulator->setAmplitude(0.2f);
  modulator->setFrequency(220.0f);
  modSample = modulator->getSample();
  modulator->tick();

  carrier->setAmplitude(0.2f);
  carrier->setFrequency(225.0f);
  carrierSample = carrier->getSample();
  _sample = (modSample + carrierSample) / 2.0f;

  // carrier->setAmplitude(amplitude);
  // carrier->setFrequency(
  //   frequency + modSample);
  // carrierSample = carrier->getSample();
  // modulator->tick();
  // carrier->tick();
  //
  // this->_sample = carrierSample;
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

  #if DEBUG
    std::cout <<
      "Fm Destroyed"
    << std::endl;
  #endif

  // delete modulator;
  // modulator = nullptr;
  // delete carrier;
  // carrier = nullptr;
  // delete tempOsc;
  // tempOsc = nullptr;
}
