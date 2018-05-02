#include <Adafruit_MAX31865.h>

#include "LiquidCrystal_I2C.h"
#include "SD_Functions.h"
#include "PT100.h"
#include "globals.h"
#include "PID_v1.h"

// lcd(adress, cols, rows) adress may vary depending on microprocessor
LiquidCrystal_I2C lcd(0x27, 16, 2);

Adafruit_MAX31865 PT100Bridge = Adafruit_MAX31865(D4);
PT100Class PT100;

////////////////////////////////////
//          PID SETTINGS         //
///////////////////////////////////

// Parameters
double Setpoint;
double Input;
double Output;
double Kp = 0.1;
double Ki = 0.5;
double Kd = 0;

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, REVERSE);

////////////////////////////////////
//          MISC SETTINGS         //
///////////////////////////////////

// Sigmoid
double s;
double slope = 3;
double half = 0.45;

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

void setup()
{
	lcd.begin(16,2);
	lcd.init(); 
	lcd.backlight();

	Serial.begin(9600);

	// Initializes the PT100 sensor and amplifier
	PT100.init(PT100Bridge, MAX31865_3WIRE);

	// turn on the PID
	myPID.SetMode(AUTOMATIC);

}

void loop()
{
	// Reads the temperature from the PT100 sensor
	double temp = PT100.read(PT100Bridge);

	myPID.Compute();
	s = 1 / (1 + exp(-slope * (Output - half)));
	Serial.println(s);

	lcd.setCursor(0,0);
	lcd.print("Set temp");
	// reads the current temp from sd card
	lcd.setCursor(0,1);
	lcd.print("Cur temp");
	lcd.setCursor(9,1);

}
