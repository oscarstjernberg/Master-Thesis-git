// 
// 
// 

#include "WiFi_Functions.h"

void WiFi_FunctionsClass::checkWiFiConnection(ESP8266WiFiClass &WiFi)
{
	if (WiFi.status() != 3) {
		status = WL_IDLE_STATUS;
		WiFi.disconnect(true);
		connectToWiFi(WiFi);
		Serial.println("reconnect");
	}

}

void WiFi_FunctionsClass::connectToWiFi(ESP8266WiFiClass &WiFi)
{
		// hej
	int WIFI_count = 0;
	Serial.println();
	Serial.println();
	Serial.print("Connecting to ");
	Serial.println(ssid);

	WiFi.begin(ssid, pass);

	while (WiFi.status() != WL_CONNECTED && WIFI_count <20) {
		delay(500);
		Serial.print(".");
		WIFI_count++;
	}
	if (WiFi.status() == 3)
	{	
	Serial.println("WiFI connected!");	Serial.println();
	Serial.print(ssid);
	Serial.println();
	Serial.println(WiFi.localIP());
	Serial.print("Wifistatus ");
	Serial.println(WiFi.status());
	WIFI_count = 0;
	}
	WiFi.localIP();
}

void WiFi_FunctionsClass::webTime(WiFiClient &client)
{
	unsigned long time = 0;
	int e = 1;
	// Just choose any reasonably busy web server, the load is really low
	while (e == 1) {
		if (client.connect("g.cn", 80))
		{
			e = 0;
			// Make an HTTP 1.1 request which is missing a Host: header
			// compliant servers are required to answer with an error that includes
			// a Date: header.
			client.print(F("GET / HTTP/1.1 \r\n\r\n"));

			char buf[5];      // temporary buffer for characters
			client.setTimeout(5000);
			if (client.find((char *)"\r\nDate: ") // look for Date: header
				&& client.readBytes(buf, 5) == 5) // discard day name
			{
				Serial.println("Connected and getting date");
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

				switch (DT.month_buf[0])
				{
				case 'J':
					switch (DT.month_buf[1])
					{
					case 'a': // Januari
						DT.month = "1";
						break;
					case 'u': // June or july
						switch (DT.month_buf[2])
						{
						case 'n': // June
							break;
							DT.month = "6";
						case 'l':// July
							DT.month = "7";
							break;
						default:
							break;
						}
					default:
						break;
					}
				case 'F': // feb
					DT.month = "2";
					break;
				case 'M': // march or May 
					switch (DT.month_buf[2])
					{
					case 'r': // march
						DT.month = "3";
						break;

					case 'y': // may
						DT.month = "5";
						break;

					default:
						break;
					}
					break;

				case 'A': // Apr or Aug
					switch (DT.month_buf[1])
					{
					case 'p': // april
						DT.month = "4";
						break;
					case 'u':
						DT.month = "8";
						break;
					default:
						break;
					}
					break;
				case 'S': //september
					DT.month = "9";
					break;

				case 'O': // October
					DT.month = "A";
					break;
				case 'N': // November
					DT.month = "B";
					break;
				case 'D': // December
					DT.month = "C";
					break;
				default:
					break;
				}
			}
		}
	}
	delay(10);
	client.flush();
	client.stop();
}


WiFi_FunctionsClass WiFi_Functions;

