// globals.h

#ifndef _GLOBALS_h
#define _GLOBALS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

// Reference value for a PT100 sensor, if using PT1000 use RREF = 4300.
#define RREF      430.0
#define RNOMINAL  100.0