// SD_functions.h

#ifndef _SD_FUNCTIONS_h
#define _SD_FUNCTIONS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
	
#include <SD.h>

	File BackupFile;

	// INITIALIZES SD CARD
	void SDinit(int SD_pin)
	{
		Serial.print("Initializing SD card...");
		if (!SD.begin(SD_pin)) {
			Serial.println("initialization failed!");
			while (1);
		}
		Serial.println("initialization done.");

		// Open file for writing
		BackupFile = SD.open("Backup.txt", FILE_WRITE);

		// If the file is open-write
		if (BackupFile)
		{
			BackupFile.print("Time\tMeasurement");
			BackupFile.println();
		}
		else {
			Serial.println("ERROR: File not found");
		}
		BackupFile.close();
	} // SD_init


	  // WRITES CONTENT OF SG TO SD CARD
	void SDwrite(int SG) {

		// Open file for writing
		BackupFile = SD.open("Backup.txt", FILE_WRITE);

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
		}
		else {
			Serial.println("ERROR: File not found");
		}
		BackupFile.close();

	} // Write to sd

#endif