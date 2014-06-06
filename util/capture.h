#ifndef FreqMeasure_capture_h_
#define FreqMeasure_capture_h_

#include <avr/io.h>
#include <avr/interrupt.h>

// Arduino Uno, Duemilanove, LilyPad, Mini, Fio, etc
#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__)
  #define CAPTURE_USE_TIMER1       // ICP1 is pin 8

// Teensy 1.0
#elif defined(__AVR_AT90USB162__)
  #define CAPTURE_USE_TIMER1       // ICP1 is pin 16

// Teensy 2.0
#elif defined(__AVR_ATmega32U4__)
  // #define CAPTURE_USE_TIMER1    // ICP1 is pin 22
  #define CAPTURE_USE_TIMER3       // ICP3 is pin 10

// Teensy++ 1.0 & 2.0
#elif defined(__AVR_AT90USB646__) || defined(__AVR_AT90USB1286__)
  // #define CAPTURE_USE_TIMER1    // ICP1 is pin 4
  #define CAPTURE_USE_TIMER3       // ICP3 is pin 17

// Sanguino
#elif defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644__)
  #define CAPTURE_USE_TIMER1       // ICP1 is pin 14

// Arduino Mega
#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
  // #define CAPTURE_USE_TIMER1    // ICP1 is not connected
  // #define CAPTURE_USE_TIMER3    // ICP3 is not connected
  #define CAPTURE_USE_TIMER4       // ICP4 is pin 49
  // #define CAPTURE_USE_TIMER5    // ICP5 is pin 48

#else
  #error "Unknown chip, please edit me with timer+counter definitions"

#endif


#if defined(CAPTURE_USE_TIMER1)

static uint8_t saveTCCR1A, saveTCCR1B;

static inline void capture_init(void)
{
	saveTCCR1A = TCCR1A;
	saveTCCR1B = TCCR1B;
	TCCR1B = 0;
	TCCR1A = 0;
	TCNT1 = 0;
	TIFR1 = (1<<ICF1) | (1<<TOV1);
	TIMSK1 = (1<<ICIE1) | (1<<TOIE1);
}

static inline void capture_start(void)
{
	TCCR1B = (1<<ICNC1) | (1<<ICES1) | (1<<CS10);
}

static inline uint16_t capture_read(void)
{
	return ICR1;
}

static inline uint8_t capture_overflow(void)
{
	return TIFR1 & (1<<TOV1);
}

static inline uint8_t capture_overflow_reset(void)
{
	return TIFR1 = (1<<TOV1);
}

static inline void capture_shutdown(void)
{
	TCCR1B = 0;
	TIMSK1 = 0;
	TCCR1A = saveTCCR1A;
	TCCR1B = saveTCCR1B;
}


#define TIMER_OVERFLOW_VECTOR  TIMER1_OVF_vect
#define TIMER_CAPTURE_VECTOR   TIMER1_CAPT_vect 


#elif defined(CAPTURE_USE_TIMER3)

static uint8_t saveTCCR3A, saveTCCR3B;

static inline void capture_init(void)
{
	saveTCCR3A = TCCR3A;
	saveTCCR3B = TCCR3B;
	TCCR3B = 0;
	TCCR3A = 0;
	TCNT3 = 0;
	TIFR3 = (1<<ICF3) | (1<<TOV3);
	TIMSK3 = (1<<ICIE3) | (1<<TOIE3);
}

static inline void capture_start(void)
{
	TCCR3B = (1<<ICNC3) | (1<<ICES3) | (1<<CS30);
}

static inline uint16_t capture_read(void)
{
	return ICR3;
}

static inline uint8_t capture_overflow(void)
{
	return TIFR3 & (1<<TOV3);
}

static inline uint8_t capture_overflow_reset(void)
{
	return TIFR3 = (1<<TOV3);
}

static inline void capture_shutdown(void)
{
	TCCR3B = 0;
	TIMSK3 = 0;
	TCCR3A = saveTCCR3A;
	TCCR3B = saveTCCR3B;
}

#define TIMER_OVERFLOW_VECTOR  TIMER3_OVF_vect
#define TIMER_CAPTURE_VECTOR   TIMER3_CAPT_vect 



#elif defined(CAPTURE_USE_TIMER4)

static uint8_t saveTCCR4A, saveTCCR4B;

static inline void capture_init(void)
{
	saveTCCR4A = TCCR4A;
	saveTCCR4B = TCCR4B;
	TCCR4B = 0;
	TCCR4A = 0;
	TCNT4 = 0;
	TIFR4 = (1<<ICF4) | (1<<TOV4);
	TIMSK4 = (1<<ICIE4) | (1<<TOIE4);
}

static inline void capture_start(void)
{
	TCCR4B = (1<<ICNC4) | (1<<ICES4) | (1<<CS40);
}

static inline uint16_t capture_read(void)
{
	return ICR4;
}

static inline uint8_t capture_overflow(void)
{
	return TIFR4 & (1<<TOV4);
}

static inline uint8_t capture_overflow_reset(void)
{
	return TIFR4 = (1<<TOV4);
}

static inline void capture_shutdown(void)
{
	TCCR4B = 0;
	TIMSK4 = 0;
	TCCR4A = saveTCCR4A;
	TCCR4B = saveTCCR4B;
}

#define TIMER_OVERFLOW_VECTOR  TIMER4_OVF_vect
#define TIMER_CAPTURE_VECTOR   TIMER4_CAPT_vect 



#elif defined(CAPTURE_USE_TIMER5)

static uint8_t saveTCCR5A, saveTCCR5B;

static inline void capture_init(void)
{
	saveTCCR5A = TCCR5A;
	saveTCCR5B = TCCR5B;
	TCCR5B = 0;
	TCCR5A = 0;
	TCNT5 = 0;
	TIFR5 = (1<<ICF5) | (1<<TOV5);
	TIMSK5 = (1<<ICIE5) | (1<<TOIE5);
}

static inline void capture_start(void)
{
	TCCR5B = (1<<ICNC5) | (1<<ICES5) | (1<<CS50);
}

static inline uint16_t capture_read(void)
{
	return ICR5;
}

static inline uint8_t capture_overflow(void)
{
	return TIFR5 & (1<<TOV5);
}

static inline uint8_t capture_overflow_reset(void)
{
	return TIFR5 = (1<<TOV5);
}

static inline void capture_shutdown(void)
{
	TCCR5B = 0;
	TIMSK5 = 0;
	TCCR5A = saveTCCR5A;
	TCCR5B = saveTCCR5B;
}

#define TIMER_OVERFLOW_VECTOR  TIMER5_OVF_vect
#define TIMER_CAPTURE_VECTOR   TIMER5_CAPT_vect 




#endif // CAPTURE_USE_***


#endif
