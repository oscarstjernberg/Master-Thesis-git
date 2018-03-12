// PT100.h

#ifndef _PT100_h
#define _PT100_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
#include "globals.h"
#include <Adafruit_MAX31865.h>

class PT100Class
{
 protected:


 public:
	void init(Adafruit_MAX31865 &PT100Bridge, max31865_numwires n);
	float read(Adafruit_MAX31865 &PT100Bridge);
};

extern PT100Class PT100;

#endif

