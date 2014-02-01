#include "SquareSynth.h"

void setup(){
  SquareSynth.begin(1,11);
}

void loop(){
  
  drumTest();
  
  SquareSynth.tempo(200);
  bassRiffA();
  bassRiffA();
  bassRiffA();
  bassRiffB();
  Channel[0].transposeOn(3);
  bassRiffA();
  bassRiffA();
  bassRiffA();
  bassRiffB();
  Channel[0].transposeOff();
}

void drumTest(){
  Channel[0].kick();
  SquareSynth.eighth();
  Channel[0].kick();
  SquareSynth.eighth();
  Channel[0].tom(_C5);
  SquareSynth.eighth();
  Channel[0].tom(_C5);
  SquareSynth.eighth();
  Channel[0].kick();
  SquareSynth.eighth();
  Channel[0].kick();
  SquareSynth.eighth();
  Channel[0].tom(_B4);
  SquareSynth.eighth();
  Channel[0].tom(_B4);
  SquareSynth.eighth();
  Channel[0].kick();
  SquareSynth.eighth();
  Channel[0].kick();
  SquareSynth.eighth();
  Channel[0].tom(_A4);
  SquareSynth.eighth();
  Channel[0].tom(_A4);
  SquareSynth.eighth();
  Channel[0].kick();
  SquareSynth.eighth();
  Channel[0].kick();
  SquareSynth.eighth();
  Channel[0].tom(_F4);
  SquareSynth.eighth();
  Channel[0].tom(_F4);
  SquareSynth.eighth();
  return; 
}

void bassRiffB(){
  Channel[0].note(_D3, 50, 40, 2);
  SquareSynth.quarter();
  Channel[0].note(_E3, 50, 40, 2);
  SquareSynth.quarter();
  Channel[0].note(_F3, 50, 40, 2);
  SquareSynth.quarter();
  Channel[0].note(_DS3, 50, 40, 2);
  SquareSynth.quarter();
  return; 
}

void bassRiffA(){
  Channel[0].noise(_C3);
  SquareSynth.eighth();
  Channel[0].note(_D3);
  SquareSynth.eighth();
  
  Channel[0].note(_DS3);
  SquareSynth.eighth();
  Channel[0].note(_D3);
  SquareSynth.eighth();
  
  Channel[0].note(_C3);
  SquareSynth.eighth();
  Channel[0].note(_DS3);
  SquareSynth.eighth();
  
  Channel[0].noise(_C3);
  SquareSynth.eighth();
  Channel[0].note(_CS3);
  SquareSynth.eighth();
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
