

#include <Adafruit_MAX31865.h>
#include <SD.h>
#include "globals.h"
#include "PID_v1.h"

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
double Setpoint;
double Input;
double Output;
double Kp = 0.1;
double Ki = 0.5;
double Kd = 0;

int pwmMin = 0;		// Minimum PWM-signal
int pwmMax = 850;	// Maximum PWM-signal

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, REVERSE);




int pMin = 27;	// minimum value from potentiometer
int pMax = 1024;	// maximum value from potentiometer
//float x = 0; // stores readings of the potentiometer
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

double setRefTemp() {
	int val = 0;
	bool done = false;
	while (!done)
	{
		Input = analogRead(A0);
		Setpoint = map(Input, pMin, pMax, 150, 350); // Translates potentiometer value and scales it from 150 to 350
		Setpoint = Setpoint / 10;	// Divides by 10 gives us a Setpoint from 15.0 to 35.0

		lcd.setCursor(1, 0);
		lcd.print("Set ref Temp:");
		lcd.setCursor(5, 1);
		lcd.print(Setpoint);
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
	return Setpoint;
}

void showStatus(float ref, double temp, bool mode, double Output) {
	
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
		
		y = map(Output, pwmMin, pwmMax, 0, 100);
		lcd.setCursor(0, 0);
		lcd.print("Load:");
		lcd.setCursor(6,0);
		lcd.print(y);
		lcd.setCursor(12,0);
		lcd.print("%");
	}
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

bool modeSwitch(double temp, bool mode, double Output ) {
	if (digitalRead(button) == 1) {
		mode = true;
	}
	else {
		mode = false;
	}
	lcd.clear();
	showStatus(Setpoint, temp, mode, Output);
	delay(50);
	return mode;
}

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



void manualMode(double temp) {
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

	// Tells the PID range between pwmMin and pwmMax.
	myPID.SetOutputLimits(pwmMin, pwmMax);

	// turn on the PID
	myPID.SetMode(AUTOMATIC);

	// Sets the reference temperature
	setRefTemp();
	delay(200);
	lcd.clear();

	// Asks the user to start
	start();
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
		modeSwitch(temp, mode, Output);
	}
	else {
		manualMode(temp);	
	}
}
