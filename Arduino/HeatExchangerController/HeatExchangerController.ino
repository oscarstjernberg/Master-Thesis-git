

#include <Adafruit_MAX31865.h>
#include "globals.h"
#include "PID_v1.h"

#include "PT100.h"
#include "SD_Functions.h"
#include "LiquidCrystal_I2C.h"
#include "SetRefTemp.h"
#include "Start.h"	
#include "ManualMode.h"
#include "ModeSwitch.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

SetRefTempClass SetRefTemp_func;

StartClass Start_func;

ManualModeClass ManualMode_func;

ModeSwitchClass ModeSwitch_func;

Adafruit_MAX31865 PT100Bridge = Adafruit_MAX31865(D4);
PT100Class PT100;


////////////////////////////////////
//          MISC SETTINGS         //
///////////////////////////////////

//int button = D0;	// ok/status button input
bool mode = false;	// Varible which decides what to be printed on the LCD
int PWM_out = D3;	// PWM output pin
int MA = 9;	// Manual/Automatic switch input
int warningLED = 3;
int load = 0;
int value = 0;

// PID parameters
double Setpoint;
double Input;
double Output;
double Kp = 0.1;
double Ki = 0.5;
double Kd = 0;
// Temporary variable used to show the PID output on the lcd.
int y = 0;

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, REVERSE);

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

void warning(double temp){
	if (temp > 26)		// If the output temperature exceeds this value, the warning led light up.
	{
		digitalWrite(warningLED, HIGH);
	}
	else
	{
		digitalWrite(warningLED, LOW);
	}
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
}


void loop()
{
	double temp = PT100.read(PT100Bridge);

	warning(temp);

	if (digitalRead(MA) == 0)
	{
		Input = temp;
		myPID.Compute();
		analogWrite(Output, PWM_out);
		// Prints the PWM-signal on the monitor
		Serial.println(Output);
		//modeSwitch(temp, mode, Output);
		mode = ModeSwitch_func.modeSwitch(temp, mode, Output, y, lcd, Setpoint);
	}
	else {
		ManualMode_func.manualMode(temp, load, value, lcd);
	}
}
