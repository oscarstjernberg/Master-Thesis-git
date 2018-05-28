#include "Showstatus.h"

void ShowStatusClass::showStatus(double ref, double temp, bool mode, double Output, LiquidCrystal_I2C &lcd, int y)
{
	
	if (mode == false) {
		lcd.setCursor(0, 0);
		lcd.print("Ref: ");
		lcd.setCursor(5, 0);
		lcd.print(ref);
		lcd.setCursor(9, 0);
		lcd.write(1);
		lcd.print("C");

		lcd.setCursor(0, 1);
		lcd.print("Cur: ");
		lcd.setCursor(5, 1);
		lcd.print(temp);
		lcd.setCursor(9, 1);
		lcd.write(1);
		lcd.print("C");
	}
	else {

		y = map(Output, pwmMin, pwmMax, 0, 100);
		lcd.setCursor(0, 0);
		lcd.print("Load:");
		lcd.setCursor(6, 0);
		lcd.print(y);
		lcd.setCursor(12, 0);
		lcd.print("%");
	}
}