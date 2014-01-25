#include <Arduino.h>
#include "SquareSynt.h"

Synth_Class Synth;

Synth_Class::Synth_Class(){
  
}

Synth_Class::~Synth_Class(){
  
}

const unsigned long Synth_Class::_midiMap[128]={122312,115447,108967,102851,97079,91630,86487,81633,77051,72727,68645,64792,61156,57723,54483,51425,48539,45815,43243,40816,38525,36363,34322,32396,30578,28861,27241,25712,24269,22907,21621,20408,19262,18181,17161,16198,15289,14430,13620,12856,12134,11453,10810,10204,9631,9090,8580,8099,7644,7215,6810,6428,6067,5726,5405,5102,4815,4545,4290,4049,3822,3607,3405,3214,3033,2863,2702,2551,2407,2272,2145,2024,1911,1803,1702,1607,1516,1431,1351,1275,1203,1136,1072,1012,955,901,851,803,758,715,675,637,601,568,536,506,477,450,425,401,379,357,337,318,300,284,268,253,238,225,212,200,189,178,168,159,150,142,134,126,119,112,106,100,94,89,84,79};

void Synth_Class::begin(int pin1, int pin2, int pin3, int pin4){
  for(int i=0; i<PIN_CHANNELS; i++) {
    _pin[i]=_microWavelength[i]=0;
    _microTimerWave[i]=micros();
    _noise[i]=false;
    _dutyCycle[i]=50;
    for(int j=0; j<=MAX_ARPEGGIO; j++) _arpeggio[i][j]=0;
  }
  
  _pin[0]=pin1;
  _channelCount=1;
  if(pin2){
    _pin[1]=pin2;
    _channelCount=2;
  }
  if(pin3){
    _pin[2]=pin3;
    _channelCount=3;
  }
  if(pin4) {
    _pin[3]=pin4;
    _channelCount=4;
  }
}

void Synth_Class::generate(){
  for(int i=0; i<_channelCount; i++){
    long unsigned wave=_microWavelength[i];
    if(!wave) return; // setting the wavelength to 0 will stop the wave.
    else {
      unsigned long dutyMicro=_microTimerDuty[i]=micros()-_microTimerWave[i]; // keeps track of exact point of duty cycle
      //Serial.println(wave/_dutyCycle[i]);
      if(dutyMicro<=wave/_dutyCycle[i]) {
        digitalWrite(_pin[i], HIGH);
      }
      else{
        digitalWrite(_pin[i], LOW);
        if(dutyMicro>=wave) {
          _microTimerWave[i]=micros(); // when duty completes, reset wave timer
          if(_noise[i]) _dutyCycle[i]=random(100); // quickly change duty cycles for pseudo-noise
          //if(_arpeggio[i][0]);
        }
      }
    }
  }
  return;
}

void Synth_Class::sendNoteOn(int note, int channel){
  _microWavelength[channel]=_midiMap[note];
  return;
}

void Synth_Class::sendPitchBend(int bend, int channel){
  return;
}

void Synth_Class::sendArpeggioOn(int channel, int offset1, int offset2, int offset3, int offset4){
  _arpeggio[channel][1]=offset1;
  _arpeggio[channel][2]=offset2;
  _arpeggio[channel][3]=offset3;
  _arpeggio[channel][4]=offset4;
  _arpeggio[channel][0]=1;
  return;
}

void Synth_Class::sendArpeggioOff(int channel){
  for(int j=0; j<=MAX_ARPEGGIO; j++) _arpeggio[channel][j]=0;
  return;
}

void Synth_Class::sendDutyCycle(int percent, int channel){
  _dutyCycle[channel]=percent;
  _noise[channel]=false;
  return;
}

void Synth_Class::sendNoise(int note, int channel){
  _microWavelength[channel]=_midiMap[note];
  _dutyCycle[channel]=random(100);
  _noise[channel]=true;
  return;
}

void Synth_Class::sendNoteOff(int channel){
  _microWavelength[channel]=0;
  _noise[channel]=false;
  return;
}
