#include <iostream>

/*

frame = x-as van buffer/audio
sample = y-as -> waarde van de sample

--------------------------------------

TODO:

- Adsr
- Envelope -> Line?
- Signal (input -> audio going into env)

--------------------------------------

*/

struct Line {

  Line(
    float inputVal,
    float targetVal,
    float numFrames);

private:
  void tick();

};

Line::Line(
  float inputVal,
  float targetVal,
  float numFrames) {
    float deltaVal
  }

void Line::tick() {

}
