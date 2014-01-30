#include "SquareSynth.h"

void setup(){
  SquareSynth.begin(1,11);
}

void loop(){
  songHolder1();
}

void songHolder1(){
  SquareSynth.tempo(158);
  chunk1();
  chunk1();
  chunk2();
  chunk3();
  chunk4();
  chunk5();
  chunk6();
  chunk6();
  return;
}

void chunk1(){
  
  Channel[0].note(_A3);
  SquareSynth.quarter();
  
  Channel[0].note(_A3);
  SquareSynth.quarter();
  
  Channel[0].note(_A3);
  SquareSynth.quarter();
  
  Channel[0].note(_G3);
  SquareSynth.quarter();
  
  return;
}

void chunk2(){
  
  Channel[0].note(_A3);
  SquareSynth.quarter();
  
  Channel[0].note(_A3);
  SquareSynth.quarter();
  
  Channel[0].note(_A3);
  SquareSynth.quarter();
  
  Channel[0].note(_A3);
  SquareSynth.quarter();
  
  return;
}

void chunk3(){
  
  Channel[0].note(_GS3);
  SquareSynth.quarter();
  
  Channel[0].note(_G3);
  SquareSynth.quarter();
  
  Channel[0].note(_G3);
  SquareSynth.quarter();
  
  Channel[0].note(_G3);
  SquareSynth.quarter();
  
  return;
}
void chunk4(){
  
  Channel[0].note(_G3);
  SquareSynth.quarter();
  
  Channel[0].note(_A3);
  SquareSynth.quarter();
  
  Channel[0].note(_B3);
  SquareSynth.quarter();
  
  Channel[0].note(_C4);
  SquareSynth.quarter();
  
  return;
}
void chunk5(){
  Channel[0].note(_D4);
  SquareSynth.eighth();
  
  Channel[0].note(_D4);
  SquareSynth.eighth();
  Channel[0].noteOff();
  
  SquareSynth.quarter();
  SquareSynth.half();
  
  return;
}
void chunk6(){
  Channel[0].note(_F4);
  SquareSynth.eighth();
  
  Channel[0].note(_F4);
  SquareSynth.eighth();
  Channel[0].noteOff();
  
  SquareSynth.eighth();
  
  Channel[0].note(_C4);
  SquareSynth.eighth();
  
  Channel[0].note(_F4);
  SquareSynth.half();
}
