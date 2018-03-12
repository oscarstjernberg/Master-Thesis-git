// loadCell.h

#ifndef _LOADCELL_h
#define _LOADCELL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
#include "globals.h"
#include <HX711_ADC.h>

class LoadCellClass
{


 protected:


 public:
	void init(HX711_ADC& LoadCellBridge);
	float read(HX711_ADC& LoadCellBridge);
};

extern LoadCellClass loadCell;

#endif

