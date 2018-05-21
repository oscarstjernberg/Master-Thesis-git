// 
// 
// 

#include "Controller.h"

void ControllerClass::Sigmoid(double error)
{
	duty_cycle_fraction = 1 / (1+exp(-slope*(error-half)));
}

void ControllerClass::Control(double error, int control_pin) 
{	
	// Calculate the fraction of active cycle time
	Sigmoid(error);

	if (millis()-duty_cycle_fraction*duty_cycle < millis_start_active_phase || just_active)
	{
		analogWrite(control_pin, 1024);
		if (just_active)
		{
			millis_start_active_phase = millis();
			just_active = false;
		}
	}
	else
	{
		analogWrite(control_pin, 0);
		if (millis() > millis_start_active_phase+duty_cycle)
		{
			just_active = true;
		}
	}

	
}
ControllerClass Controller;