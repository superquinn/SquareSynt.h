#ifndef SquareSynt_h
#define SquareSynt_h

#include <Arduno.h>

// change these if you know what you're doing
#define MAX_ARPEGGIO 4 // also edit sendArpeggioOn()
// ------------------------------------------

class Synth_Class {
  public:
    Synth_Class();
    ~Synth_Class();
    void begin(int pin);
    void generate(); // place in loop for wave generation.
    void noteOn(int note, int duty=50);
    void pitchBend(int bend);
    void arpeggioOn(int offset1, int offset2=0, int offset3=0, int offset4=0);
    void arpeggioOff();
    void dutyCycle(int percent);
    void noise(int note=60);
    void noteOff();
  private:
    bool _noise; // checker for noise mode
    int _arpeggio[MAX_ARPEGGIO+1]; // checker for arpeggio values
    int _arpeggioCount; // amount of notes to arpeggiate
    int _arpeggioTrack; // keeps track of arpeg. cycling in generate()
    int _note; // keep track of MIDI note value for reference
    int _pin; // stores the pin number
    float _dutyCycle; //stores duty cycle percentage
    unsigned long _microWavelength; // stores wavelength in microseconds
    unsigned long _microTimerWave; // wavelength timer
    unsigned long _microTimerDuty; // duty cycle timer
    static const unsigned long _midiMap[128]; // mappings of midi to wavelength in microseconds
};

extern Synth_Class Synth;

#endif
