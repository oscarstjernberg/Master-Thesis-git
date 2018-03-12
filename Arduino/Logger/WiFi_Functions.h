// WiFi_Functions.h

#ifndef _WIFI_FUNCTIONS_h
#define _WIFI_FUNCTIONS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
#include "globals.h"
#include <WiFiClient.h>
#include <ESP8266WiFi.h>

class WiFi_FunctionsClass
{
 protected:
	 char ssid[10] = "Combine";
	 char pass[15] = "plasmakorv";
	 int status = WL_IDLE_STATUS;

	 enum month_enum {Sep, Oct, Nov, Dec };
	 month_enum month_switch;

 public:
	void checkWiFiConnection(ESP8266WiFiClass &WiFi);
	void connectToWiFi(ESP8266WiFiClass &WiFi);
	void webTime(WiFiClient &client);

	struct DateandTime {
		char month_buf[3];
		String month;
		int month_int;
		byte year;
		unsigned day;
		byte hour;
		byte minute;
		byte second;
	}DT;
};

extern WiFi_FunctionsClass WiFi_Functions;

#endif

