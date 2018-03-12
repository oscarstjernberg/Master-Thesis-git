// 
// 
// 

#include "SD_Functions.h"

void SD_FunctionsClass::createFileName(WiFi_FunctionsClass &Wifi_func)
{
#ifdef ONLINE_FILE_NAME
	fileName = Wifi_func.DT.month + String(Wifi_func.DT.day) + 
		String(Wifi_func.DT.hour) + String(Wifi_func.DT.minute) + String(int(Wifi_func.DT.second / 10)) + ".txt";
	Serial.print("File created with name:");
	Serial.println(fileName);
	Serial.println(int(Wifi_func.DT.second/10));
#else
	fileName = "BACKUP.TXT";
#endif
}

void SD_FunctionsClass::init(int SD_pin, WiFi_FunctionsClass &Wifi_func)
{
	Serial.print(F("Initializing SD card..."));
	if (!SD.begin(SD_pin)) {
		Serial.println(F("Initialization SD-card failed!"));
		while (1);
	}
	createFileName(Wifi_func);
	Serial.println(F("Initialization SD-card done."));
	
	// Open file for writing
	BackupFile = SD.open(fileName, FILE_WRITE);

	// If the file is open-write
	if (BackupFile)
	{
		BackupFile.print("Time\tMeasurement\tTemperature");
		BackupFile.println();

	}
	else {
		Serial.println(F("ERROR: File not found"));
		Serial.println(fileName);
	}
	BackupFile.close();
}


void SD_FunctionsClass::write(float SG, float temp , WiFi_FunctionsClass &Wifi_func)
{
	String time_str;

	

	// Open file for writing
	BackupFile = SD.open(fileName, FILE_WRITE);

	// If the file is open-write
	if (BackupFile)
	{
		BackupFile.print(millis());
		BackupFile.print("\t");
		// Write Measurement value
		BackupFile.print(SG);
		BackupFile.print("\t");
		// Write temperature
		BackupFile.println(temp);

		Serial.print(F("Writing to SD-card: \t"));
		Serial.print(millis());
		Serial.print("\t");
		// Write Measurement value
		Serial.println(SG);
	}
	else {
		Serial.println(F("ERROR: File not found"));
		Serial.println(fileName);
	}
	BackupFile.close();
}


SD_FunctionsClass SD_Functions;

