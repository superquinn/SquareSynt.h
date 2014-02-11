#include "SquareSynth.h"

void setup(){
  SquareSynth.begin(2,11,12);
}

void loop(){
  LRtest();
  //drumTest();

  SquareSynth.tempo(180);
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

void LRtest(){
  Channel[0].note();
  SquareSynth.quarter();
  Channel[0].noteOff();
  SquareSynth.quarter();
  Channel[1].note();
  SquareSynth.quarter();
  Channel[1].noteOff();
  SquareSynth.quarter();
}

void drumTest(){
  Channel[0].cymbal();
  SquareSynth.whole();
  //Channel[0].hihat();
  //SquareSynth.whole();
  //Channel[0].snare();
  //SquareSynth.whole();
  //Channel[0].hihatOpen();
  //SquareSynth.whole();
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
  Channel[0].noise(_C3);Channel[1].kick();
  SquareSynth.eighth();
  Channel[0].note(_D3);Channel[1].kick();
  SquareSynth.eighth();
  
  Channel[0].note(_DS3);Channel[1].tom(_C5);
  SquareSynth.eighth();
  Channel[0].note(_D3);Channel[1].tom(_C5);
  SquareSynth.eighth();
  
  Channel[0].note(_C3);Channel[1].kick();
  SquareSynth.eighth();
  Channel[0].note(_DS3);Channel[1].kick();
  SquareSynth.eighth();
  
  Channel[0].noise(_C3);Channel[1].tom(_C5);
  SquareSynth.eighth();
  Channel[0].note(_CS3);Channel[1].tom(_C5);
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
