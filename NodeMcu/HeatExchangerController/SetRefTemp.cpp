#include "SetRefTemp.h"

double SetRefTempClass::setRefTemp(double Input, double Setpoint, LiquidCrystal_I2C &lcd)
{
	int val = 0;
	bool done = false;
	while (!done)
	{
		Input = analogRead(A0);
		Setpoint = map(Input, pMin, pMax, 150, 350); // Translates potentiometer value and scales it from 150 to 350
		Setpoint = Setpoint / 10;	// Divides by 10 gives us a Setpoint from 15.0 to 35.0

		lcd.setCursor(1, 0);
		lcd.print("Set ref Temp:");
		lcd.setCursor(5, 1);
		lcd.print(Setpoint);
		lcd.setCursor(11, 1);
		lcd.write(1);
		lcd.print("C");
		delay(100);

		val = digitalRead(button);
		if (val == 1)
		{
			done = true;
		}
		Serial.println(analogRead(A0));
	}
	return Setpoint;
}