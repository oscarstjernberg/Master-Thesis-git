// SD_Functions.h

#ifndef _SD_FUNCTIONS_h
#define _SD_FUNCTIONS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "globals.h"
#include "WiFi_Functions.h"

#ifndef __SD_H__
#include <SD.h>
#endif // !__SD_H__

class SD_FunctionsClass
{
 protected:
	File BackupFile;
	String fileName;

 public:
	void init(int SD_pin, WiFi_FunctionsClass &Wifi_func);
	void write(float SG, float temp, WiFi_FunctionsClass &Wifi_func);
	void createFileName(WiFi_FunctionsClass &Wifi_func);
};

extern SD_FunctionsClass SD_Functions;

#endif

