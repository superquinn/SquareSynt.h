#ifndef SquareSynt_h
#define SquareSynt_h

#include <Arduno.h>

#define PIN_CHANNELS 4
#define DATA 1
#define DUTY_CYCLE 0

class Synth_Class {
  public:
    Synth_Class();
    ~Synth_Class();
    void begin(int pin1, int pin2=0, int pin3=0, int pin4=0);
    void generate();
    void sendNote(int note, int pin=0);
    void sendPitchBend(int bend, int pin=0);
    void sendArpeggio(int offset, int pin=0);
    void sendDutyCycle(int percent, int pin=0);
    void sendNoise(int pitch=60, int pin=0);
    void stop(int pin=0);
  private:
    int _midiMap[127]; // stores mappings of MIDI scale to wavelength in microseconds
    int _pinDefault; // default pin if none specified
    int _channelCount; // saves processing power by keeping track of actual number of outputs.
    int _pin[PIN_CHANNELS]; // stores the pin numbers
    int _dutyCycle[PIN_CHANNELS]; //stores duty cycle percentages
    unsigned long _microWavelength[PIN_CHANNELS]; // stores wavelength in microseconds per pin
    unsigned long _microTimerWave[PIN_CHANNELS]; // wavelength timer
    unsigned long _microTimerDuty[PIN_CHANNELS]; // duty cycle timer
    
};

#endif
