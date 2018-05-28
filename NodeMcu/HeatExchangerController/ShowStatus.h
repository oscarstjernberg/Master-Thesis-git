// ShowStatus.h

#include "LiquidCrystal_I2C.h"
#include "globals.h"

#ifndef _ShowStatus_h
#define _ShowStatus_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class ShowStatusClass
{
private:

public:
	void showStatus(double ref, double temp, bool mode, double Output, LiquidCrystal_I2C &lcd, int y);
};

extern ShowStatusClass ShowStatus;

#endif