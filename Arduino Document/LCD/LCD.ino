#include <LiquidCrystal.h>

LiquidCrystal lcd(D0, D1, D2, D3, D4, D5);

int potPin = A0;

void setup() {
	lcd.begin(16, 2);
	Serial.begin(9600);
}

void loop() { 
	int potVal = analogRead(potPin);

	lcd.setCursor(3, 0);
	lcd.write("Pot value");
	lcd.setCursor(4, 1);
	lcd.print(potVal);
	delay(100);
	lcd.clear();
	Serial.println(potVal);
}