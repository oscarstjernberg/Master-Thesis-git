// WarningLED.h

#include "globals.h"

#ifndef _Warning_h
#define _Warning_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class WarningClass
{
private:

public:
	void warning(double temp);
};

extern WarningClass WarningLED;

#endif

