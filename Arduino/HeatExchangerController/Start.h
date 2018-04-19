// Start.h

#include "globals.h"
#include "LiquidCrystal_I2C.h"

#ifndef _Start_h
#define _Start_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif



class StartClass
{
protected:

public:
	void start(LiquidCrystal_I2C &lcd);
};

extern StartClass Start;

#endif 

