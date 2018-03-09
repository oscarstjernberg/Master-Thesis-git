// 
// 
// 

#include "loadCell.h"

void LoadCellClass::init(HX711_ADC &LoadCellBridge)
{
	Serial.begin(115200);
	LoadCellBridge.begin();
	long stabilisingtime = 2000; // tare preciscion can be improved by adding a few seconds of stabilising time
	LoadCellBridge.start(stabilisingtime);
	LoadCellBridge.setCalFactor(2090.0); // user set calibration factor (float)
	Serial.println("Startup + tare is complete");
}

float LoadCellClass::read(HX711_ADC &LoadCellBridge)
{
	//update() should be called at least as often as HX711 sample rate; >10Hz@10SPS, >80Hz@80SPS
	//longer delay in scetch will reduce effective sample rate (be carefull with delay() in loop)
	LoadCellBridge.update();
	float val;
	long t;
	//get smoothed value from data set + current calibration factor
	if (millis() > t + 250) {
		val = LoadCellBridge.getData();
#ifdef SERIAL_PRINT_LOADCELL
		Serial.print("Load_cell output val: ");
		Serial.println(val);
#endif
		t = millis();
	}

	//receive from serial terminal
	if (Serial.available() > 0) {
		val;
		char inByte = Serial.read();
		if (inByte == 't') LoadCellBridge.tareNoDelay();
	}

	//check if last tare operation is complete
	if (LoadCellBridge.getTareStatus() == true) {
		Serial.println("Tare complete");
	}

	return	val;
}


LoadCellClass loadCell;

