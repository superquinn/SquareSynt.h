#include <SquareSynth.h>

// example sketch, cycling through stable range of notes.
// toggling between noise mode and a tone at 50% duty cycle

long unsigned timer;
long unsigned count;
int note=36;
int toggle[2]={1,0};

void setup() {
  pinMode(11,OUTPUT);
  SquareSynth.begin(1, 11);
  timer=millis();
}

void loop(){
  count=millis();
  if(count-timer>=50) {
    if(note>95 || note<36) {
      toggle[0]*=-1;
      toggle[1]++;
    }
    if(toggle[0]>0) note++;
    else note--;
    if(toggle[1]>3) toggle[1]=0;
    if(toggle[1]>1) Channel[0].noteOn(note, 50);
    else Channel[0].noise(note);
    timer=count;
  }
  Channel[0].generate();
}
