#include "SquareSynth.h"

void setup(){
  Synth.begin(12); // specify output pin
}

// note that there is also the option for running multiple synth instances in an array. check out the commands in the .h file for more info.

void loop(){
  // This is all you need for some rudimentary synthing
  Synth.note(_C4);
  
  // A generate() command MUST be placed in a running loop to generate the waves!
  Synth.generate();
}

/*
    Summary of most common commands:
    (use Channel[].command() OR Synth.command() for these. If only using one output, use Synth. It's much simpler)
    (  The Channel[] array of objects are initialised with SquareSynth.begin(instances,pin,...); )
    
    Synth.begin(int pin);
    Synth.generate(); // place in loop for wave generation.
    Synth.pitchBend(int bend=0); // not fully tested yet! bend from -1000 to +1000 for a bend of +- two notes
    Synth.arpeggioOn(int offset1, int offset2=0, int offset3=0, int offset4=0);
    Synth.arpeggioOff();
    Synth.dutyCycle(int percent); // change duty cycle on the fly!
    Synth.noise(int pitch=60, int minDuty=1, int maxDuty=51); // pseudo noise!
    Synth.noteOff(); // stops the note being played!
    Synth.transposeOn(int transposition); // +- amount of notes you want to transpose by!
    Synth.transposeOff();
    Synth.clearFlags(); // use this to clear effects you applied if you lose count, or want to jump to clean play without much overhead
    
    Synth.transform(int destination, int steps); // transforms current note to specified note, spanning x many steps
    Synth.addDepth(int duty=15, int steps=2); // bends the duty cycle briefly, starting at specified duty and ending at original; spanning x many steps
    Synth.autoKill(int steps=1, bool killArpeggio=false); // kills note after specified number of steps. the boolean arguments are used in some of the drum synth functions.
    
    ////////////////////////////////////////////////
    // High-level routines (instruments & stuff!) //
    ////////////////////////////////////////////////
    
    // Simple commands:
    Synth.note(int pitch=60, int duty=50, int depth=30, int steps=1);
    
    // other commands available, but not vetted yet.
    
*/
