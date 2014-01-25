#ifndef SquareSynt_h
#define SquareSynt_h

#include <Arduno.h>

// change these if you know what you're doing
#define PIN_CHANNELS 4 // also edit begin()
#define MAX_ARPEGGIO 4 // also edit sendArpeggioOn()
// ------------------------------------------

class Synth_Class {
  public:
    Synth_Class();
    ~Synth_Class();
    void begin(int pin1, int pin2=0, int pin3=0, int pin4=0);
    void generate(); // place in loop for wave generation.
    void sendNoteOn(int note, int channel=0);
    void sendPitchBend(int bend, int channel=0);
    void sendArpeggioOn(int channel, int offset1, int offset2=0, int offset3=0, int offset4=0);
    void sendArpeggioOff(int channel);
    void sendDutyCycle(int percent, int channel=0);
    void sendNoise(int note=60, int channel=0);
    void sendNoteOff(int channel=0);
  private:
    bool _noise[PIN_CHANNELS]; // checker for noise mode
    int _arpeggio[PIN_CHANNELS][MAX_ARPEGGIO]; // checker for arpeggioes
    int _channelCount; // saves processing power by keeping track of actual number of outputs.
    int _pin[PIN_CHANNELS]; // stores the pin numbers
    int _dutyCycle[PIN_CHANNELS]; //stores duty cycle percentages
    unsigned long _microWavelength[PIN_CHANNELS]; // stores wavelength in microseconds per pin
    unsigned long _microTimerWave[PIN_CHANNELS]; // wavelength timer
    unsigned long _microTimerDuty[PIN_CHANNELS]; // duty cycle timer
    static const unsigned long _midiMap[128]; // mappings of midi to wavelength in microseconds
};

extern Synth_Class Synth;

#endif
