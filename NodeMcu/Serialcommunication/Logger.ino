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

void setup()
{
	Serial.begin(9600);

}


void loop()
{
	Serial.println(10);
	delay(2000);
}