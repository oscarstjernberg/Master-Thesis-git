// Libraries

#include <SPI.h>
#include <SD.h>

// Definitions

File BackupFile;
int SD_pin = 4;
int PotPin = A0;
int SG;

// Time between measurements in seconds
int seconds_delay = 1;

void setup() {
  Serial.begin(9600);
  
  Serial.print("Initializing SD card...");
  if (!SD.begin(SD_pin)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  // Open file for writing
  BackupFile = SD.open("BackupFile.txt", FILE_WRITE);

  // If the file is open-write
  if (BackupFile)
  {
    BackupFile.print("Time\tMeasurement");
    BackupFile.println();
  } else {
    Serial.println("ERROR: File not found");
  }
  BackupFile.close();
}
// setup

void loop() {

  SG = analogRead(PotPin);
  Serial.println(SG);
  
  // Open file for writing
  BackupFile = SD.open("BackupFile.txt", FILE_WRITE);

  // If the file is open-write
  if (BackupFile)
  {
    // Write time
    BackupFile.print(millis());
    BackupFile.print("\t");
    // Write Measurement value
    BackupFile.println(SG);

    Serial.print(millis());
    Serial.print("\t");
    // Write Measurement value
    Serial.println(SG);
  } else {
    Serial.println("ERROR: File not found");
  }
  BackupFile.close();

  delay(seconds_delay * 1000);

}
// loop



