
//------------------------------------------------------------------------------
#define errorHalt(msg) {Serial.println(F(msg)); while(1);}
//------------------------------------------------------------------------------

#include <SPI.h>
#include <SD.h>
#include <time.h>

#include "ReadToTable.h"
#define CS_PIN 53


File file;
ReadToTableClass Table;

void setup() {
  Serial.begin(9600);

  // Initialize the SD.
  if (!SD.begin(CS_PIN)) {
    errorHalt("begin failed");
  }
  // Create or open the file.
  file = SD.open("file.txt", FILE_WRITE);
  if (!file) {
    errorHalt("open failed");
  }
  file.close();

  // Read the file and import to Temp_ref and Time_ref
  // file must be named file.txt
  // Accessed via Table.Temp_ref[i] Table.Time_ref[i] 
  Table.init(file);


}
//------------------------------------------------------------------------------
void loop() {
}