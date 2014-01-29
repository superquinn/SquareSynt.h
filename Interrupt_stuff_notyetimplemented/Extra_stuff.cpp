SQUARESYNTH_TIMER_INIT(SQUARESYNTH_OCR);

#if F_CPU
#define SQUARESYNTH_FREQ 60UL
#define SQUARESYNTH_OCR (F_CPU/(8UL*256UL*SQUARESYNTH_FREQ))
#else
// 130 == 60 Hz (on 16 MHz part)
#define SQUARESYNTH_OCR 130
#endif

ISR(SOFTPWM_TIMER_INTERRUPT){};

// for timer2, 249=8khz

////////////////////////////////////////////
// my attempt at making it user definable //
////////////////////////////////////////////
#if F_CPU
#define GET_OCR_VAL (F_CPU/(8UL*256UL*frequency))
#else
#define GET_OCR_VAL (math goes here)
#endif
