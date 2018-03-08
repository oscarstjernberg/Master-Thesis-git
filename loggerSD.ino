// Standard libraries
#include <ESP8266WiFi.h>
#include <SD.h>
#include <ThingSpeak.h>
#include <HX711_ADC.h>
#include <SPI.h>
#include <Adafruit_MAX31865.h>

// User created libraries
#include "globals.h"
#include "to_spreadsheet.h"
#include "SD_Functions.h"
#include "loadCell.h"
#include "WiFi_Functions.h"
#include "PT100.h"
#include "Thingspeak_Functions.h"

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

const int SD_pin = D4;

  ////////////////////////////////////
  //          SETUP                 //
  ///////////////////////////////////

void setup() {
  Serial.begin(115200);
  
  // Initialize the PT100 sensor 
  PT100.init(PT100Bridge, MAX31865_3WIRE);
  
  // Initialize SD-card
  SD_func.init(SD_pin);

  // Initialize reading the load cell
  LoadCell.init(LoadCellBridge);

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
  
}// end main loop

