#include "ManualMode.h"

void ManualModeClass::manualMode(double temp, int load, int value, LiquidCrystal_I2C &lcd)
{
	lcd.clear();
	load = 0;
	value = analogRead(A0);
	value = map(value, 8, 1024, 0, 850);
	analogWrite(D3, value);
	delay(30);
	lcd.setCursor(0, 0);
	lcd.print("Temp:");
	lcd.setCursor(7, 0);
	lcd.print(temp);
	lcd.setCursor(11, 0);
	lcd.write(1);
	lcd.print("C");
	lcd.setCursor(0, 1);
	lcd.print("Load:");
	lcd.setCursor(7, 1);
	load = map(value, 0, 850, 0, 100);
	lcd.print(load);	// Prints the total "load" on the lcd
	lcd.setCursor(11, 1);
	lcd.print("%");
	Serial.println(value);
	delay(100);
}