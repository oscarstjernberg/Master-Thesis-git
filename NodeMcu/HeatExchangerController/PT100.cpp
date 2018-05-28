// 
// 
// 

#include "PT100.h"

void PT100Class::init(Adafruit_MAX31865 &PT100Bridge, max31865_numwires n)
{
	// Starts the MAX31865 with n wires
	PT100Bridge.begin(n);
}

float PT100Class::read(Adafruit_MAX31865 &PT100Bridge) {
	uint16_t rtd = PT100Bridge.readRTD();


	float ratio = rtd;
	ratio /= 32768;

#ifdef SERIAL_PRINT_TEMPERATURE
	Serial.print("RTD value: "); Serial.println(rtd);
	Serial.print("Ratio = "); Serial.println(ratio, 8);
	Serial.print("Resistance = "); Serial.println(RREF * ratio, 8);
	Serial.print("Temperature = "); Serial.println(PT100Bridge.temperature(RNOMINAL, RREF));
#endif

	// Check and print any faults
	uint8_t fault = PT100Bridge.readFault();
	if (fault) {
		Serial.print("Fault 0x"); Serial.println(fault, HEX);
		if (fault & MAX31865_FAULT_HIGHTHRESH) {
			Serial.println("RTD High Threshold");
		}
		if (fault & MAX31865_FAULT_LOWTHRESH) {
			Serial.println("RTD Low Threshold");
		}
		if (fault & MAX31865_FAULT_REFINLOW) {
			Serial.println("REFIN- > 0.85 x Bias");
		}
		if (fault & MAX31865_FAULT_REFINHIGH) {
			Serial.println("REFIN- < 0.85 x Bias - FORCE- open");
		}
		if (fault & MAX31865_FAULT_RTDINLOW) {
			Serial.println("RTDIN- < 0.85 x Bias - FORCE- open");
		}
		if (fault & MAX31865_FAULT_OVUV) {
			Serial.println("Under/Over voltage");
		}
		PT100Bridge.clearFault();
	}
#ifdef SERIAL_PRINT_TEMPERATURE
	Serial.println();
#endif
	return PT100Bridge.temperature(RNOMINAL, RREF);

}

// PT100Class PT100;

