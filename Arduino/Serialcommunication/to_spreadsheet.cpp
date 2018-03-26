// 
// 
// 

#include "to_spreadsheet.h"

void GoogleSpreadsheet::send(float val, float temp, Client &client)
{
	client.stop();
	delay(100);
	val_int = int32(val * 1000);
	temp_int = int32(temp * 1000);
	// Constructing GET request string
	sprintf(cmd, "GET /pushingbox?devid=vAADBEE37B57A997&meas=%f&temp=%f HTTP/1.1", val,temp);
	 Serial.println(cmd);
	 Serial.println(F("Starting connection to server..."));

	// if you get a connection, report back via serial
	if (client.connect(server, 80)) {
		 Serial.println(F("Connected to server"));
		// Make a HTTP request
		client.println(cmd);
		client.println(F("Host: api.pushingbox.com"));
		client.println(F("Connection: close"));
		client.println();
		delay(100);
		client.stop();
		Serial.println("Data sent");
		Serial.println("Connection closed");
	}
}

GoogleSpreadsheet To_spreadsheet;

