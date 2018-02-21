// 
// 
// 

#include "SD_FUNCTIONS.h"

File BackupFile;


// INITIALIZES SD CARD

void SDinit(int SD_pin)
{
	Serial.print(F("Initializing SD card..."));
	if (!SD.begin(SD_pin)) {
		Serial.println(F("Initialization SD-card failed!"));
		while (1);
	}
	Serial.println(F("Initialization SD-card done."));

	// Open file for writing
	BackupFile = SD.open("Backup.txt", FILE_WRITE);

	// If the file is open-write
	if (BackupFile)
	{
		BackupFile.print("Time\tMeasurement");
		BackupFile.println();
	}
	else {
		Serial.println(F("ERROR: File not found"));
	}
	BackupFile.close();
} // SD_init



  //////////////////////////////////////////////////////////////////////
  // WRITES CONTENT OF SG TO SD CARD
void SDwrite(int SG) {

	String time_str;

	// Open file for writing
	BackupFile = SD.open("Backup.txt", FILE_WRITE);

	// If the file is open-write
	if (BackupFile)
	{
		// Write time
		if (WiFi.status() == 1) {
			time_str = String(DT.year) + "-" + DT.month + "-" + String(DT.day) + ":" + String(DT.hour) + ":" + String(DT.minute) + ":" + String(DT.second);
			Serial.println(time_str);
			BackupFile.print(time_str);
		}
		else {
			BackupFile.print(millis());
		}

		BackupFile.print("\t");
		// Write Measurement value
		BackupFile.println(SG);

		Serial.print(F("Writing to SD-card: \t"));
		Serial.print(time_str);
		Serial.print("\t");
		// Write Measurement value
		Serial.println(SG);
	}
	else {
		Serial.println(F("ERROR: File not found"));
	}
	BackupFile.close();

} // Write to sd

  //////////////////////////////////////////////////////////////////////
