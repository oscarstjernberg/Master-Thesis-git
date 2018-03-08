// to_spreadsheet.h

#ifndef _TO_SPREADSHEET_h
#define _TO_SPREADSHEET_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "globals.h"
#include <WiFiClient.h>

class GoogleSpreadsheet
{
 protected:
	 char cmd[100];
	 char server[25] = "api.pushingbox.com";
 public:
	void send(float val, float temp, Client &client);
};

extern GoogleSpreadsheet To_spreadsheet;

#endif

