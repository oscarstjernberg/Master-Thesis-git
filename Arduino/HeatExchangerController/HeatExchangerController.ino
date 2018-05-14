#include <Adafruit_MAX31865.h>
#include "globals.h"
#include "LiquidCrystal_I2C.h"

#include "PID_v1.h"
#include "PT100.h"
#include "SD_Functions.h"
#include "SetRefTemp.h"
#include "Start.h"	
#include "ManualMode.h"
#include "ModeSwitch.h"
#include "Warning.h"

////////////////////////////////////
//           Class cals          //
///////////////////////////////////

// lcd(adress, cols, rows) adress may vary depending on microprocessor
LiquidCrystal_I2C lcd(0x27, 16, 2);

SetRefTempClass SetRefTemp_func;

StartClass Start_func;

ManualModeClass ManualMode_func;

ModeSwitchClass ModeSwitch_func;

WarningClass warning_func;

Adafruit_MAX31865 PT100Bridge = Adafruit_MAX31865(D4, D6, D7, D5);
PT100Class PT100;

////////////////////////////////////
//          PID SETTINGS         //
///////////////////////////////////

// Parameters
double Setpoint;
double Input;
double Output;
double Kp = 30;
double Ki = 3;
double Kd = 0;
// Temporary variable used to show the PID output on the lcd.
int y = 0; // remove!

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, REVERSE);  

////////////////////////////////////
//          MISC SETTINGS         //
///////////////////////////////////

//int button = D0;	// ok/status button input
bool mode = false;	// Varible which decides what to be printed on the LCD
int PWM_out = D3;	// PWM output pin
int MA = 9;	// Manual/Automatic switch input
int load = 0;
int value = 0;

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
	// Starts the LCD screen
	lcd.begin(16, 2);
	lcd.init();
	lcd.backlight();

	Serial.begin(9600);		// Starts serial communication
	lcd.createChar(1, degree); // Creates the degree sign and gives it the "call name" 1

	// Set specific pins to input and output
	pinMode(button, INPUT);
	pinMode(MA, INPUT);
	pinMode(warningLED, OUTPUT);

	// Initializes the PT100 sensor and amplifier
	PT100.init(PT100Bridge, MAX31865_3WIRE);

	// Tells the PID range between pwmMin and pwmMax.
	myPID.SetOutputLimits(pwmMin, pwmMax);

	// turn on the PID
	myPID.SetMode(AUTOMATIC);

	// Sets the reference temperature
	Setpoint = SetRefTemp_func.setRefTemp(Input, Setpoint, lcd);

	delay(200);
	lcd.clear();

	// Asks the user to start
	//start();
	Start_func.start(lcd);
}// end setup


void loop()
{
	// Reads the temperature from the PT100 sensor
	double temp = PT100.read(PT100Bridge);

	// Checks that the output temperarure is not to high
	warning_func.warning(temp);

	// Running automaticmode using a PID or manual
	bool AutoManual = digitalRead(MA);
	Serial.print("A/M state: ");
	Serial.println(AutoManual);

	if (!AutoManual)
	{
		Input = temp;
		myPID.Compute();
		analogWrite(PWM_out, Output);
		
		//modeSwitch(temp, mode, Output);
		mode = ModeSwitch_func.modeSwitch(temp, mode, Output, y, lcd, Setpoint);
	}
	else {
		ManualMode_func.manualMode(temp, load, value, lcd);
	}
	// Prints the PWM-signal on the monitor
	Serial.print(Output);
	Serial.print("\t");
	Serial.print(temp);
	Serial.print("\t");
	Serial.print(millis());
	Serial.println();

	
}// end loop