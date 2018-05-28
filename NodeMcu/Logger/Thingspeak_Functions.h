// Thingspeak_Functions.h

#ifndef _THINGSPEAK_FUNCTIONS_h
#define _THINGSPEAK_FUNCTIONS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
#include "globals.h"
#include <ThingSpeak.h>
class Thingspeak_FunctionsClass
{
 protected:


 public:
	void BoardDefine(int board);
	void send(float val, float temp);
};

extern Thingspeak_FunctionsClass Thingspeak_Functions;

#endif

