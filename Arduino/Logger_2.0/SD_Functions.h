// SD_Functions.h

#ifndef _SD_FUNCTIONS_h
#define _SD_FUNCTIONS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "globals.h"
#include <SD.h>

class SD_FunctionsClass
{
 protected:
	File BackupFile;

 public:
	void init(int SD_pin);
	void write(float SG, float temp);
};

extern SD_FunctionsClass SD_Functions;

#endif

