// Libraries

#include <SPI.h>
#include "globals.h"

// User defined libraries

#include "SD_functions.h"

// Definitions

int SD_pin = 4;
int PotPin = A0;
int SG;

// Time between measurements in seconds
int seconds_delay = 1;

void setup() {
  Serial.begin(9600);
  SDinit(SD_pin);

} // setup

void loop() {

  int SG = analogRead(PotPin);

  
  SDwrite(SG);


  delay(seconds_delay * 1000);

} // loop

