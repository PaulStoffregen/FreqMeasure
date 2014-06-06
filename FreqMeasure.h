#ifndef FreqMeasure_h
#define FreqMeasure_h

#include <inttypes.h>

class FreqMeasureClass {
public:
	static void begin(void);
	static uint8_t available(void);
	static uint32_t read(void);
	static void end(void);
};

extern FreqMeasureClass FreqMeasure;

#endif

