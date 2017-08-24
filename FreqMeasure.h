#ifndef FreqMeasure_h
#define FreqMeasure_h

#include <Arduino.h>

class FreqMeasureClass {
public:
	static void begin(void);
	static uint8_t available(void);
	static uint32_t read(void);
	static float countToFrequency(uint32_t count);
	static float countToNanoseconds(uint32_t count);
	static void end(void);
};

extern FreqMeasureClass FreqMeasure;

#endif

