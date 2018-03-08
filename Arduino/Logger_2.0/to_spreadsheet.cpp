// 
// 
// 

#include "to_spreadsheet.h"

void GoogleSpreadsheet::send(float val, float temp, Client &client)
{
	// Constructing GET request string
	sprintf(cmd, "GET /pushingbox?devid=vAADBEE37B57A997&meas=%d&temp=%d HTTP/1.1", 1234, 4567);
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
		client.stop();
		Serial.println("Data sent");
		Serial.println("Connection closed");
	}

}

GoogleSpreadsheet To_spreadsheet;

