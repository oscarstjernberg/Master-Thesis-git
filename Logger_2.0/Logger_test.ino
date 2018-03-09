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

long previousMillis_thingspeak = 0;
long previousMillis_google = 0;
long previousMillis_SD = 0;

const int SD_pin = D4;

// Check if first loop
bool first = true;

////////////////////////////////////
//          SETUP                 //
///////////////////////////////////

void setup() {
	ESP.wdtDisable();

	Serial.begin(115200);
	delay(10);

	// Define thingspeak channel
	// TS.BoardDefine(3);

	// Initialize the PT100 sensor 
	PT100.init(PT100Bridge, MAX31865_3WIRE);

	// connect to WiFi
	// WiFi_func.connectToWiFi(WiFi);

	// Get date
	// WiFi_func.webTime(client);

	// Initialize SD-card
	SD_func.init(SD_pin, WiFi_func);

	// Initialize reading the load cell
	LoadCell.init(LoadCellBridge);

	// ThingSpeak setup
	// ThingSpeak.begin(client);


	ESP.wdtEnable(WDTO_0MS);
}// end Setup

 ////////////////////////////////////
 //          MAIN                  //
 ///////////////////////////////////

void loop() {
	ESP.wdtFeed();

	unsigned long timeMillis = millis();

	// Reads the temperature of the PT100or PT1000 sensor
	float temp = PT100.read(PT100Bridge);

	// read value from load cell
	float val = LoadCell.read(LoadCellBridge);

#ifdef SD_CARD
	if ((timeMillis - previousMillis_SD) >= INTERVAL_SD || first == true) {
		previousMillis_SD = timeMillis;
		SD_func.write(val, temp, WiFi_func);
	}
#endif // SD_CARD


#ifdef GOOGLE_SPREADSHEET
	if ((timeMillis - previousMillis_google) >= INTERVAL_GOOGLE && WiFi.status() == 3 || first == true) {
		previousMillis_google = timeMillis;
		GSS.send(val, temp, client);
	}
#endif // GOOGLE_SPREADSHEET


#ifdef THINGSPEAK
	if ((timeMillis - previousMillis_thingspeak) >= INTERVAL_THINGSPEAK && WiFi.status() == 3 || first == true) {
		previousMillis_thingspeak = timeMillis;
		TS.send(val, temp);
}
#endif //THINKSPEAK 

	// WiFi_func.checkWiFiConnection(WiFi);

	// Check if first loop
	first = false;
}// end main loop

