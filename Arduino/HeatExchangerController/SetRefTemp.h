// SetRefTemp.h

#include "globals.h"
#include "LiquidCrystal_I2C.h"

#ifndef _SetRefTemp_h
#define _SetTempRef_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class SetRefTempClass
{
protected:

public:
	double setRefTemp(double Input, double Setpoint, LiquidCrystal_I2C &lcd);
};

extern SetRefTempClass SetRefTemp;

#endif