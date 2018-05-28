// SD_FUNCTIONS.h

#ifndef _SD_FUNCTIONS_h
#define _SD_FUNCTIONS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <SD.h>

void SDinit(int SD_pin);
void SDwrite(int SG);

#endif

