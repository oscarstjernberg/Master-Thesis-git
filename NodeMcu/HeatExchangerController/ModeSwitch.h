// ModeSwitch.h

#include "LiquidCrystal_I2C.h"
#include "ShowStatus.h"

#ifndef _ModeSwitch_h
#define _ModeSwitch_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


class ModeSwitchClass
{
private:

public:
	bool modeSwitch(double temp, bool mode, double Output, int y, LiquidCrystal_I2C &lcd, double SetPoint);
};

extern ModeSwitchClass ModeSwitch;

#endif
