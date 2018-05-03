// Controller.h

#ifndef _Controller_h
#define _Controller_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class ControllerClass
{
 protected:
	 double slope = 3;
	 double half = 0.45;
	 double duty_cycle = 360000;
 public:
	 void Control(double error, int control_pin);

private:
	 int duty_cycle_fraction;
	 void Sigmoid(double error);
	 bool just_active = true;	// Bättre namn?
	 int millis_start_active_phase;
};

extern ControllerClass Controller;

#endif

