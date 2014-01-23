#include <Arduino.h>
#include "SquareSynt.h"

Synth_Class Synth;

Synth_Class::Synth_Class(){
  
}

Synth_Class::~Synth_Class(){
  
}

void Synth_Class::begin(int pin1, int pin2, int pin3, int pin4){
  for(int i=0; i<PIN_CHANNELS; i++) {
    _pin[i]=_microWavelength[i]=_dutyCycle[i]=0;
    _microTimerWave[i]=micros();
    _noise[i]=false;
    for(int j=0; j<=MAX_ARPEGGIO; j++) _arpeggio[i][j]=0;
  }
  
  for(int x=0; x<127; ++x) _midiMap[x]=((1/((440/32)*(2^((x-9)/12))))*1000000); // MIDI to wavelength in microseconds
  
  _pinDefault=_pin[0]=pin1;
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
    unsigned long wave=_microWavelength[i];
    if(!wave); // setting the wavelength to 0 will stop the wave.
    else {
      unsigned long dutyMicro=_microTimerDuty[i]=micros()-_microTimerWave[i]; // keeps track of exact point of duty cycle
      if(dutyMicro<=wave/_dutyCycle[i]) digitalWrite(_pin[i], HIGH);
      else{
        digitalWrite(_pin[i], LOW);
        if(dutyMicro>=wave) {
          _microTimerWave[i]=micros(); // when duty completes, reset wave timer
          if(_noise[i]) _dutyCycle[i]=random(100); // quickly change duty cycles for pseudo-noise
          if(_arpeggio[i][0]);
        }
      }
    }
  }
}

void Synth_Class::sendNoteOn(int note, int pin){
  if(!pin) pin=_pinDefault;
  _microWavelength[pin]=_midiMap[note];
  return;
}

void Synth_Class::sendPitchBend(int bend, int pin){
  if(!pin) pin=_pinDefault;
  return;
}

void Synth_Class::sendArpeggioOn(int pin, int offset1, int offset2, int offset3, int offset4){
  _arpeggio[pin][1]=offset1;
  _arpeggio[pin][2]=offset2;
  _arpeggio[pin][3]=offset3;
  _arpeggio[pin][4]=offset4;
  _arpeggio[pin][0]=1;
  return;
}

void Synth_Class::sendArpeggioOff(int pin){
  for(int j=0; j<=MAX_ARPEGGIO; j++) _arpeggio[pin][j]=0;
  return;
}

void Synth_Class::sendDutyCycle(int percent, int pin){
  if(!pin) pin=_pinDefault;
  _dutyCycle[pin]=percent;
  _noise[pin]=false;
  return;
}

void Synth_Class::sendNoise(int note, int pin){
  if(!pin) pin=_pinDefault;
  _microWavelength[pin]=_midiMap[note];
  _dutyCycle[pin]=random(100);
  _noise[pin]=true;
  return;
}

void Synth_Class::sendNoteOff(int pin){
  if(!pin) pin=_pinDefault;
  _microWavelength[pin]=0;
  _noise[pin]=false;
  return;
}
