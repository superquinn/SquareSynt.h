#include "SquareSynth.h"

void setup() {
  pinMode(11,OUTPUT);
  SquareSynth.begin(4,10,9,12,11);
}

void loop(){
  Channel[3].noteOn(60);
  Channel[1].noise();
  Channel[3].generate();
  Channel[1].generate();
}
