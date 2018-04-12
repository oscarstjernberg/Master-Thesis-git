


#include <LiquidCrystal.h>
#include <Adafruit_MAX31865.h>
#include <SD.h>
#include "globals.h"
#include <PID_v1.h>

#include "PT100.h"
#include "SD_Functions.h"


// MAX31865 - PT100 sensor
// Use software SPI: CS, DI, DO, CLK

Adafruit_MAX31865 PT100Bridge = Adafruit_MAX31865(3, D7, D6, D5);

PT100Class PT100;


////////////////////////////////////
//          MISC SETTINGS         //
///////////////////////////////////


LiquidCrystal lcd(D0, D1, D2, D3, D4, 10);
int button = 9;
bool mode = false;	// Varible which decides what to be printed on the LCD

// PID parameters
double Setpoint, Input, Output;
PID myPID(&Input, &Output, &Setpoint, 2, 5, 1, DIRECT);

int pMin = 27;	// minimum value from potentiometer
int pMax = 1024;	// maximum value from potentiometer
float x = 0; // stores readings of the potentiometer
float y;


// Generates the degree sign
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
		x = map(x, pMin, pMax, 350, 150); // Translates potentiometer value and scales it from 15 to 35
		x = x / 10;

		lcd.setCursor(1, 0);
		lcd.write("Set ref Temp:");
		lcd.setCursor(5, 1);
		lcd.print(x);
		lcd.setCursor(11, 1);
		lcd.write(1);
		lcd.write("C"); 
		delay(100);

		val = digitalRead(button);
		if (val == 1)
		{
			done = true;
		}
		Serial.println(analogRead(A0));
	}
	return x;
}

float showStatus(float ref,float temp, bool mode) {
	y = analogRead(A0);
	y = map(y, 27, 1024, 100, 0);
	if (mode == false) {
		lcd.setCursor(0, 0);
		lcd.write("Ref: ");
		lcd.setCursor(5, 0);
		lcd.print(ref);
		lcd.setCursor(9, 0);
		lcd.write(1);
		lcd.write("C");

		lcd.setCursor(0, 1);
		lcd.write("Cur: ");
		lcd.setCursor(5, 1);
		lcd.print(temp);
		lcd.setCursor(9, 1);
		lcd.write(1);
		lcd.write("C");
	}
	else {
	
		lcd.setCursor(0, 0);
		lcd.write("Load:");
		lcd.setCursor(6,0);
		lcd.print(y);
		lcd.setCursor(9,0);
		lcd.write("%");
	}
	return y;
}

void start() {
	lcd.setCursor(2, 0);
	lcd.write("Press ok to");
	lcd.setCursor(5, 1);
	lcd.write("start");
	while (digitalRead(button) == false) {
		delay(50);
	}
	lcd.clear();
}

void setup()
{
	lcd.begin(16, 2);
	Serial.begin(9600);
	lcd.createChar(1, degree);
	pinMode(button, INPUT);

	PT100.init(PT100Bridge, MAX31865_3WIRE);

	setRefTemp();
	delay(50);
	lcd.clear();
	start();
}

bool alarm(float a) {
	if (a > 90)
	{
		// Warning high capacity or something........
		return true;
	}else{
		return false;
	}
}

void loop()
{
	float temp = PT100.read(PT100Bridge);
	if (digitalRead(button) == 1){
		mode = true;
	}
	else{
		mode = false;
	}
	lcd.clear();
	showStatus(x,temp, mode);

	alarm(y);

}
