#include "LiquidCrystal_I2C.h"
#include <Wire.h>
// Construct an LCD object and pass it the 
// I2C address, width (in characters) and
// height (in characters). Depending on the
// Actual device, the IC2 address may change.
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

	//Wire.begin(4,5);
	lcd.begin(16, 2);
	lcd.init();

	
	lcd.backlight();
	lcd.setCursor(5,0);
	lcd.print("Kabbel");
	lcd.setCursor(5, 1);
	lcd.print("WORLD");
}

void loop() {
}