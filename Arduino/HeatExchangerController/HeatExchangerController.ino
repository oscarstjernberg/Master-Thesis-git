

#include <Adafruit_MAX31865.h>
#include <SD.h>
#include "globals.h"
#include <PID_v1.h>

#include "PT100.h"
#include "SD_Functions.h"
#include "LiquidCrystal_I2C.h"


Adafruit_MAX31865 PT100Bridge = Adafruit_MAX31865(D4);
PT100Class PT100;


////////////////////////////////////
//          MISC SETTINGS         //
///////////////////////////////////


//LiquidCrystal lcd(D0, D1, D2, D3, D4, 10);
LiquidCrystal_I2C lcd(0x27, 16 ,2);
int button = D0;	// ok/status button input
bool mode = false;	// Varible which decides what to be printed on the LCD
int PWM_out = D3;	// PWM output pin
int MA = 9;	// Manual/Automatic switch input
int warningLED = 3;

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
		lcd.print("Set ref Temp:");
		lcd.setCursor(5, 1);
		lcd.print(x);
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
	return x;
}

float showStatus(float ref,float temp, bool mode) {
	
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
		y = analogRead(A0);
		y = map(y, 27, 1024, 100, 0);
		lcd.setCursor(0, 0);
		lcd.print("Load:");
		lcd.setCursor(6,0);
		lcd.print(y);
		lcd.setCursor(12,0);
		lcd.print("%");
	}
	return y;
}

void start() {
	lcd.setCursor(2, 0);
	lcd.print("Press ok to");
	lcd.setCursor(5, 1);
	lcd.print("start");
	while (digitalRead(button) == 0) {
		delay(20);
	}
	lcd.clear();
}


/*bool alarm(float a) {
	if (a > 90)
	{
		// Warning high capacity or something........
		return true;
	}
	else {
		return false;
	}
}*/

void manualMode(float temp) {
	lcd.clear();
	int load = 0;
	int value = analogRead(A0);
	value = map(value, 8, 1024, 0, 850);
	analogWrite(D3,value);
	delay(30);
	lcd.setCursor(0, 0);
	lcd.print("Temp:");
	lcd.setCursor(7,0);
	lcd.print(temp);
	lcd.setCursor(11,0);
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

void setup()
{
	lcd.begin(16, 2);
	lcd.init();
	lcd.backlight();
	Serial.begin(9600);
	lcd.createChar(1, degree);
	pinMode(button, INPUT);
	pinMode(MA, INPUT);
	pinMode(warningLED, OUTPUT);

	PT100.init(PT100Bridge, MAX31865_3WIRE);

	setRefTemp();
	delay(200);
	lcd.clear();
	start();
}


void loop()
{
	float temp = PT100.read(PT100Bridge);

	if (temp > 26)		// If the output temperature exceeds this value, the warning led light up.
	{
		digitalWrite(warningLED, HIGH);
	}
	else
	{
		digitalWrite(warningLED, LOW);
	}

	if (digitalRead(MA) == 0)
	{
		if (digitalRead(button) == 1) {
			mode = true;
		}
		else {
			mode = false;
		}
		lcd.clear();
		showStatus(x, temp, mode);
		Serial.println(digitalRead(button));
		delay(50);
	}
	else {

		manualMode(temp);
		
	}

}
