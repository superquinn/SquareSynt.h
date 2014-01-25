#include "SquareSynt.h"

void setup() {
  pinMode(11,OUTPUT);
  //Serial.begin(9600);
  Synth.begin(11);
  Synth.sendNoteOn(60);
}

void loop(){
  Synth.generate();
}
