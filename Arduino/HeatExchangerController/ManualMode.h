// ManualMode.h

#include "LiquidCrystal_I2C.h"


#ifndef _ManualMode_h
#define _ManualMode_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class ManualModeClass
{
protected:

public:
	void manualMode(double temp, int load, int value, LiquidCrystal_I2C &lcd);
};

extern ManualModeClass ManualMode;

#endif