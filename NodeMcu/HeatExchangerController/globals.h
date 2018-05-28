// globals.h

#ifndef _GLOBALS_h
#define _GLOBALS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

// Reference value for a PT100 sensor, if using PT1000 use RREF = 4300.
#define RREF      430.0
#define RNOMINAL  100.0

// Time interval for logging of data
#define INTERVAL_SD 200
#define INTERVAL_GOOGLE 260000 // every 260 seconds ~= 5min
#define INTERVAL_THINGSPEAK 120000

// Reference values for setting the reference temperature
#define pMin 27
#define pMax 1024

// Reference Values for the PWM-signal
#define pwmMin 450
#define pwmMax 700

#define button D0
#define warningLED 3

// Temporary variable used to show the PID output on the lcd.
//#define y 0

// Serial print inside functions

// #define SERIAL_PRINT_TEMPERATURE
// #define SERIAL_PRINT_LOADCELL

// File name definition
 #define ONLINE_FILE_NAME

// Define what functions to run
#define SD_CARD
#define GOOGLE_SPREADSHEET
// #define THINGSPEAK