// Standard libraries
#include "globals.h"
#include <ESP8266WiFi.h>
#include <SD.h>
#include <ThingSpeak.h>
#include <HX711_ADC.h>
#include <SPI.h>
#include <Adafruit_MAX31865.h>

// User created libraries
#include "to_spreadsheet.h"
#include "SD_Functions.h"
#include "loadCell.h"
#include "WiFi_Functions.h"
#include "PT100.h"
#include "Thingspeak_Functions.h"


// Wifi settings
// Declare and initialise global arrays for WiFi settings

WiFiClient client;

WiFi_FunctionsClass WiFi_func;

// Send to Google spreadsheet
GoogleSpreadsheet GSS;

// Send to thingspeak
Thingspeak_FunctionsClass TS;

// SD functions for init and write
SD_FunctionsClass SD_func;

//HX711 constructor (dout pin, sck pin)
HX711_ADC LoadCellBridge(D1, D0);

// Load cell
LoadCellClass LoadCell;

// MAX31865 - PT100 sensor
// Use software SPI: CS, DI, DO, CLK
Adafruit_MAX31865 PT100Bridge = Adafruit_MAX31865(4, 9, 10, 0);

PT100Class PT100;

////////////////////////////////////
//          MISC SETTINGS         //
///////////////////////////////////

int delaySeconds = 10;
int loopTime = delaySeconds * 1000;

long previousMillis_thingspeak = 0;
long previousMillis_google = 0;
long previousMillis_SD = 0;
long interval = 20000;

int SD_LED = D8;
int WiFi_LED = D3;
const int SD_pin = D4;

  ////////////////////////////////////
  //          SETUP                 //
  ///////////////////////////////////

void setup() {
	Serial.begin(115200);
	delay(10);
	
	// Define thingspeak channel
	TS.BoardDefine(3);

	// Initialize the PT100 sensor 
	PT100.init(PT100Bridge, MAX31865_3WIRE);
	
	// connect to WiFi
	WiFi_func.connectToWiFi(WiFi);

	// Initialize SD-card
	SD_func.init(SD_pin);

	// Initialize reading the load cell
	LoadCell.init(LoadCellBridge);

	// ThingSpeak setup
	ThingSpeak.begin(client);

}// end Setup

 ////////////////////////////////////
 //          MAIN                  //
 ///////////////////////////////////

void loop() {

	unsigned long timeMillis = millis();

	// Reads the temperature of the PT100or PT1000 sensor
	float temp = PT100.read(PT100Bridge);

	// read value from load cell
	float val = LoadCell.read(LoadCellBridge);

	// Writes the loadcell value and the temperature to the SD-card
	if ((timeMillis - previousMillis_SD) >= interval) {
		previousMillis_SD = timeMillis;
		SD_func.write(val, temp);
	}

	// Send to google spreadsheet
	if ((timeMillis - previousMillis_google) >= interval && WiFi.status() == 3) {
		previousMillis_google = timeMillis;
		// GSS.send(val, temp, client);
	}

	// send to thingspeak
	if ((timeMillis - previousMillis_thingspeak) >= interval && WiFi.status() == 3) {
		previousMillis_thingspeak = timeMillis;
		TS.send(val, temp);
	}
	
}// end main loop

