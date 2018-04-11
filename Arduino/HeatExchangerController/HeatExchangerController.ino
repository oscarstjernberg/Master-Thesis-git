


#include <LiquidCrystal.h>
#include <Adafruit_MAX31865.h>
#include <SD.h>

#include "PT100.h"
#include "SD_Functions.h"

LiquidCrystal lcd(D0, D1, D2, D3, D4, 10);
int button = 9;

int pMin = 20;	// minimum value from potentiometer
int pMax = 1004;	// maximum value from potentiometer
int x = 0; // stores readings of the potentiometer

// MAX31865 - PT100 sensor
// Use software SPI: CS, DI, DO, CLK
Adafruit_MAX31865 PT100Bridge = Adafruit_MAX31865(3, D7, D6, D5);
// use hardware SPI, just pass in the CS pin
//Adafruit_MAX31865 PT100Bridge = Adafruit_MAX31865(3);

PT100Class PT100;

byte degree[8] =
{
	0b00011,
	0b00011,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000
};

float setRefTemp() {
	int val = 0;
	bool done = false;
	while (!done)
	{
		x = analogRead(A0);

		//Serial.print(x);

		x = map(x, pMin, pMax, 0, 100); // Translates potentiometer value and scales it from 0 to 100
		Serial.print("\t");
		//Serial.println(x);

		if (x == -1){
			x = 0;
		}

		if (x>100){
			x = 100;
		}


		lcd.setCursor(1, 0);
		lcd.write("Set ref Temp:");
		lcd.setCursor(5, 1);
		lcd.print(x);
		lcd.setCursor(11, 1);
		lcd.write(1);
		lcd.write("C"); 
		delay(100);
		lcd.clear();

		Serial.print(val);
		val = digitalRead(button);
		if (val == 1)
		{
			done = true;
		}

	}
	return x;
}

float showTemp(float ref,float temp) {

	lcd.setCursor(0, 0);
	lcd.write("Ref: ");
	lcd.setCursor(10, 0);
	lcd.print(ref);

	lcd.setCursor(0, 1);
	lcd.write("Current: ");
	lcd.setCursor(10, 1);
	lcd.print(temp);

	//return temp;
}



void setup()
{
	lcd.begin(16, 2);
	Serial.begin(9600);
	lcd.createChar(1, degree);
	pinMode(button, INPUT);

	PT100.init(PT100Bridge, MAX31865_3WIRE);

	//SD_func.init(SD_pin, WiFi_func);

	setRefTemp();
	
}

void loop()
{

	//Serial.print(digitalRead(button));

	
	float temp = PT100.read(PT100Bridge);
	//showTemp(x,temp);	
	

}
