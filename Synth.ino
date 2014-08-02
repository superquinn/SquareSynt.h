#include "SquareSynth.h"

void setup(){
  Synth.begin(11);
}

void loop(){
  Synth.note();
  Synth.generate();
}
