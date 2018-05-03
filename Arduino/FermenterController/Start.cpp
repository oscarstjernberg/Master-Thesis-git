#include "Start.h"

void StartClass::start(LiquidCrystal_I2C &lcd)
{
	lcd.setCursor(2, 0);
	lcd.print("Press ok to");
	lcd.setCursor(5, 1);
	lcd.print("start");
	while (digitalRead(button) == 0) {
		delay(20);
	}
	lcd.clear();
}