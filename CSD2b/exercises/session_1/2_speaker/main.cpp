#include <iostream>

class Tweeter : Public Speaker{
public:
  // default constructor
  Tweeter();
  // overloaded constructor
  Tweeter(float diam);

  // fields

};

Tweeter::Tweeter() {
  std::cout << "Tweeter - default constructor\n";
  // NOTE: duplicate code alarm!!
  // constructor delegation is a better strategy!
    // ?? constructor delegation?
  // in cm
  diameter = 2.5f;
  // number with an f --> indicate it is a float
  conePosition = 0.0f;
}

// code voor constructor van class Woofer
// dit heeft bijna dezelfde code als tweeter, hoe laat
//  ik de constructor de code van een andere
//  constructor overnemen? -> inheritance?

class Woofer : Public Speaker{
public:
  // constructor
  Woofer();
  // overloaded constructor? was da?
  Woofer(float diam);

  // member_variables

};

Woofer::Woofer() {
  std::cout << "Woofer - default constructor\n";
  diameter = 15.0f;
  conePosition = 0.0f;
}

// arguments are 'diam'
Tweeter::Tweeter(float diam) {
  std::cout << "Tweeter - constructor with float diam parameter\n";
  diameter = diam;
  conePosition = 0.0f;
}


class Speaker{
public:
  float diameter;
  float conePosition;
  Speaker();
  Tweeter aTweeter;
  Woofer aWoofer;
};

Speaker::Speaker() {
  std::cout << "Speaker - constructor\n";
  aTweeter.diameter = 2.4;
  std::cout << "The diameter of the tweeter is: "
    << aTweeter.diameter << "\n";
  aWoofer.diameter = 15.0;
  std::cout << "The diameter of the tweeter is: "
    << aWoofer.diameter << "\n";
}

// TODO - add woofer

int main() {
  Speaker aSpeaker;
};
