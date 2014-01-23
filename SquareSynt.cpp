#include "Arduino.h"
#include "SquareSynt.h"

Synth_Class Synth;

Synth_Class::Synth_Class(){
  for(int i=0; i<PIN_CHANNELS; i++) _pin[i]=0;
  for(int x=0; x<127; ++x) _midiMap[x]=((1/((440/32)*(2^((x-9)/12))))*1000000); // MIDI to wavelength in microseconds
  for(int y=0; y<PIN_CHANNELS; y++) _microTimerWave[y]=micros();
}

Synth_Class::~Synth_Class(){
  
}

void Synth_Class::begin(int pin1, int pin2, int pin3, int pin4){
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
      unsigned long duty=_microTimerDuty[i]=micros()-_microTimerWave[i]; // keeps track of exact point of duty cycle
      if(duty<=wave/_dutyCycle[i]) digitalWrite(_pin[i], HIGH);
      else{
        digitalWrite(_pin[i], LOW);
        if(duty>=wave) _microTimerWave[i]=micros(); // when duty completes, reset wave timer
      }
    }
  }
}

void Synth_Class::sendNote(int note, int pin){
  if(!pin) pin=_pinDefault;
  _microWavelength[pin]=_midiMap[note];
  return;
}

void Synth_Class::sendPitchBend(int bend, int pin){
  if(!pin) pin=_pinDefault;
  return;
}

void Synth_Class::sendArpeggio(int offset, int pin){
  if(!pin) pin=_pinDefault;
  return;
}

void Synth_Class::sendDutyCycle(int percent, int pin){
  if(!pin) pin=_pinDefault;
  _dutyCycle[pin]=percent;
  return;
}

void Synth_Class::sendNoise(int pitch, int pin){
  if(!pin) pin=_pinDefault;
  
  return;
}

void Synth_Class::stopNote(int pin){
  if(!pin) pin=_pinDefault;
  _microWavelength[pin]=0;
  return;
}
