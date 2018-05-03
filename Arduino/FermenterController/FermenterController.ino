#include <Wire.h>
#include <Adafruit_MAX31865.h>
#include <SD.h>

#include "Controller.h"
#include "LiquidCrystal_I2C.h"
#include "SD_Functions.h"
#include "PT100.h"
#include "globals.h"
#include "PID_v1.h"
#include "Start.h"
#include "ReadToTable.h"

// lcd(adress, cols, rows) adress may vary depending on I2C display. Common adresses are 0x27 and 0x3F.
// LiquidCrystal_I2C lcd(0x3F, 16, 2);

// Temperature sensor
Adafruit_MAX31865 PT100Bridge = Adafruit_MAX31865(D8);

PT100Class PT100;

// SD functions for init and write
SD_FunctionsClass SD_func;

// Read temperature profile from sd card
ReadToTableClass table_func;

// Initiate file for reading of sd-card
File file;

// Start function for the lcd display
StartClass start_func;

// Controller function
ControllerClass Controller;


////////////////////////////////////
//          DUTY CYCLE            //
///////////////////////////////////



////////////////////////////////////
//          PID SETTINGS         //
///////////////////////////////////

// Parameters
double Setpoint_PID;
double Input_PID;
double Output_PID;
double Kp = 0.1;
double Ki = 0.5;
double Kd = 0;

PID myPID(&Input_PID, &Output_PID, &Setpoint_PID, Kp, Ki, Kd, REVERSE);

////////////////////////////////////
//          MISC SETTINGS         //
///////////////////////////////////


// SD
const int SD_pin = D3;
const int control_pin = D4;

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
	lcd.begin(16, 2);
	lcd.init(); 
	lcd.backlight();
	lcd.createChar(1, degree); // Creates the degree sign and gives it the "call name" 1

	Serial.begin(9600);

	pinMode(button, INPUT);
	pinMode(control_pin, OUTPUT);

	start_func.start(lcd);

	// Initializes the PT100 sensor and amplifier
	PT100.init(PT100Bridge, MAX31865_3WIRE);

	table_func.init(SD_pin, file);
	// Read the file and import to Temp_ref and Time_ref
	// file must be named file.txt
	table_func.read(file);

	// turn on the PID
	myPID.SetMode(AUTOMATIC);
	 
}

void loop()
{
	// Reads the temperature from the PT100 sensor
	double temp = PT100.read(PT100Bridge);
	Serial.println("Temperature Measurement: ");
	Serial.println(temp);

	// Calculate error
	Input_PID = table_func.Temp_ref[table_func.currentIndex(millis())] - temp;
	
	// Calculate PID output
	myPID.Compute();

	// Control
	Controller.Control(Output_PID, control_pin);
	

	lcd.setCursor(1,0);
	lcd.print("Set temp");
	// reads the current temp from sd card
	lcd.setCursor(0,1);
	lcd.print("Cur temp");
	lcd.setCursor(9,1);
	delay(100);
}
