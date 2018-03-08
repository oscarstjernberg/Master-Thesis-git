// 
// 
// 

#include "WiFi_Functions.h"

void WiFi_FunctionsClass::checkWiFiConnection(ESP8266WiFiClass &WiFi)
{
	if (WiFi.status() != 3) {
		status = WL_IDLE_STATUS;
		connectToWiFi(WiFi);
		Serial.println("reconnect");
	}

}

void WiFi_FunctionsClass::connectToWiFi(ESP8266WiFiClass &WiFi)
{
	Serial.println();
	Serial.println();
	Serial.print("Connecting to ");
	Serial.println(ssid);

	WiFi.begin(ssid, pass);

	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
	}
	Serial.println("WiFI connected!");	Serial.println();
	Serial.print(ssid);
	Serial.println();
	Serial.println(WiFi.localIP());
	Serial.print("Wifistatus ");
	Serial.println(WiFi.status());
}

void WiFi_FunctionsClass::webTime(WiFiClient &client)
{
	unsigned long time = 0;

	// Just choose any reasonably busy web server, the load is really low
	if (client.connect("g.cn", 80))
	{
		
		// Make an HTTP 1.1 request which is missing a Host: header
		// compliant servers are required to answer with an error that includes
		// a Date: header.
		client.print(F("GET / HTTP/1.1 \r\n\r\n"));

		char buf[5];      // temporary buffer for characters
		client.setTimeout(5000);
		if (client.find((char *)"\r\nDate: ") // look for Date: header
			&& client.readBytes(buf, 5) == 5) // discard day name
		{

			DT.day = client.parseInt();    // day number
			client.readBytes(buf, 1);    // discard
			client.readBytes(DT.month_buf, 3);    // month_buf
			String str(DT.month_buf);
			DT.month = str.substring(0, 3);
			DT.year = client.parseInt();    // year
			DT.hour = client.parseInt();   // hour
			DT.minute = client.parseInt(); // minute
			DT.second = client.parseInt(); // second
										   //      }
		}
	}
	delay(10);
	client.flush();
	client.stop();
}


WiFi_FunctionsClass WiFi_Functions;

