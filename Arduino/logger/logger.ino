#include <ESP8266WiFi.h>
#include "SD_FUNCTIONS.h"
////////////////////////////////////
//          WIFI SETTINGS         //
////////////////////////////////////

WiFiClient client;

// Declare and initialise global arrays for WiFi settings
char ssid[] = "Combine";
char pass[] = "plasmakorv";
char server[] = "api.pushingbox.com";
char cmd[100];

////////////////////////////////////
//          SD SETTINGS           //
///////////////////////////////////
int SD_pin = 53;

enum months  {Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};
months switch_month;
struct DateandTime {
  char month_buf[3];
  String month;
  int year;
  unsigned day;
  byte hour;
  byte minute;
  byte second;
} DT;

////////////////////////////////////
//      ThingSpeak SETTINGS       //
////////////////////////////////////

unsigned long myChannelNumber  = 420692; // Channel ID
const char * myWriteAPIKey = "A86F3R21OEZKIIQQ";  // Channel API-key

////////////////////////////////////
//          MISC SETTINGS         //
///////////////////////////////////

int PotPin = A0;
int delaySeconds = 10;
int loopTime = delaySeconds * 1000;

// counters for data saving
int countPush = 10;
int countTS = 10;




////////////////////////////////////
//          SETUP                 //
///////////////////////////////////

void setup() {
  Serial.begin(115200);
  delay(10);

  // connect to WiFi
  connectToWiFi();

  // Initialize SD-card
  SDinit(SD_pin);

}

void loop() {
  // put your main code here, to run repeatedly:

}

//////////////////// WiFi functions /////////////////////

void connectToWiFi(){
Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);

WiFi.begin(ssid,pass);

while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("WiFI connected!");
Serial.println();
Serial.print(ssid);
Serial.println();
Serial.println(WiFi.localIP());
}



