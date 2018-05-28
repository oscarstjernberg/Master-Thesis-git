// 
// 
// 

#include "Thingspeak_Functions.h"

void Thingspeak_FunctionsClass::BoardDefine(int board)
{
	if (board == 1) {
		#define myChannelNumber  420692; // Channel ID
		#define myWriteAPIKey  "A86F3R21OEZKIIQQ";  // Channel API-key
	}

	if (board == 2) {
		#define myChannelNumber  441326; // Channel ID
		#define myWriteAPIKey  "8H4EAGF3VE2IF6UT";  // Channel API-key
	}

	if (board == 3) {
		#define myChannelNumber  441330 // Channel ID
		#define myWriteAPIKey  "Q3I84GD3QUIC1LQT"  // Channel API-key
	}
}


void Thingspeak_FunctionsClass::send(float val, float temp) {
	Serial.print("Sending to ThingSpeak ");
	Serial.println(val);
	ThingSpeak.setField(1, val);    // Sends the loadcell value to field 1 in the ThingSpeak channel
	ThingSpeak.setField(2, temp);   // Sends the temperature to field 2 in the ThingSpeak channel
	ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
}

Thingspeak_FunctionsClass Thingspeak_Functions;

