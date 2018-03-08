// 
// 
// 

#include "SD_Functions.h"

void SD_FunctionsClass::init(int SD_pin)
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
		BackupFile.print("Time\tMeasurement\tTemperature");
		BackupFile.println();
	}
	else {
		Serial.println(F("ERROR: File not found"));
	}
	BackupFile.close();
}


void SD_FunctionsClass::write(float SG, float temp)
{
	String time_str;

	// Open file for writing
	BackupFile = SD.open("Backup.txt", FILE_WRITE);

	// If the file is open-write
	if (BackupFile)
	{
		// Write time
		//if (WiFi.status() == 3) {
		//	time_str = String(DT.year) + "-" + DT.month + "-" + String(DT.day) + ":" + String(DT.hour) +
		//		":" + String(DT.minute) + ":" + String(DT.second);
		//	Serial.println(time_str);
		//	BackupFile.print(time_str);
		//}
		//else {
		BackupFile.print(millis());
		//}

		BackupFile.print("\t");
		// Write Measurement value
		BackupFile.print(SG);
		BackupFile.print("\t");
		BackupFile.println(temp);

		Serial.print(F("Writing to SD-card: \t"));
		Serial.print(millis());
		Serial.print("\t");
		// Write Measurement value
		Serial.println(SG);
	}
	else {
		Serial.println(F("ERROR: File not found"));
	}
	BackupFile.close();
}


SD_FunctionsClass SD_Functions;

