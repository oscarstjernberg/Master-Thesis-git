#include "ModeSwitch.h"

ShowStatusClass ShowStatus_func;

bool ModeSwitchClass::modeSwitch(double temp, bool mode, double Output, int y, LiquidCrystal_I2C &lcd, double Setpoint)
{
	if (digitalRead(button) == 1) {
		mode = true;
	}
	else {
		mode = false;
	}
	lcd.clear();
	ShowStatus_func.showStatus(Setpoint, temp, mode, Output, lcd, y);
	delay(50);
	return mode;
}