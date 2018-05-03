#include <Adafruit_MAX31865.h>

#include "LiquidCrystal_I2C.h"
#include "SD_Functions.h"
#include "PT100.h"
#include "globals.h"
#include "PID_v1.h"
#include "Start.h"
#include "ReadToTable.h"

// lcd(adress, cols, rows) adress may vary depending on I2C display. Common adresses are 0x27 and 0x3F.
LiquidCrystal_I2C lcd(0x3F, 16, 2);

Adafruit_MAX31865 PT100Bridge = Adafruit_MAX31865(D4);
PT100Class PT100;

// SD functions for init and write
SD_FunctionsClass SD_func;

ReadToTableClass read_func;

StartClass start_func;

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

// SD
const int SD_pin = D3;

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

void selectProfile()
{
 
}

void setup()
{
	lcd.begin(16, 2);
	lcd.init(); 
	lcd.backlight();
	lcd.createChar(1, degree); // Creates the degree sign and gives it the "call name" 1

	Serial.begin(9600);

	pinMode(button, INPUT);

	start_func.start(lcd);

	lcd.setCursor(1,0);
	lcd.print("Hello");
	Serial.println("Test");
	delay(10000);

	// Initializes the PT100 sensor and amplifier
	PT100.init(PT100Bridge, MAX31865_3WIRE);

	// turn on the PID
	myPID.SetMode(AUTOMATIC);
	 
}

void loop()
{
	// Reads the temperature from the PT100 sensor
	//double temp = PT100.read(PT100Bridge);

	myPID.Compute();
	s = 1 / (1 + exp(-slope * (Output - half)));
	Serial.println(s);

	lcd.setCursor(1,0);
	lcd.print("Set temp");
	// reads the current temp from sd card
	lcd.setCursor(0,1);
	lcd.print("Cur temp");
	lcd.setCursor(9,1);
	delay(1000);
}
