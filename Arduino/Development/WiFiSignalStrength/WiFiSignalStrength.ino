#include <SPI.h>
#include <ESP8266WiFi.h>

//SSID of your network 
char ssid[] = "SadRobot";
char pass[] = "RiverTam";





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
digitalWrite(D3, HIGH);
Serial.println();
Serial.print(ssid);
Serial.println();
Serial.println(WiFi.localIP());
}



void setup()
{
  Serial.begin(9600);

  connectToWiFi();

 
 /*WiFi.begin(ssid, pass);

  if (WiFi.status() != WL_CONNECTED) { 
    Serial.println("Couldn't get a wifi connection");
    while(true);
  } 
  // if you are connected, print out info about the connection:
  else {
   // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("RSSI:");
  Serial.println(rssi);
  }*/
}

void loop () {
   long rssi = WiFi.RSSI();
  Serial.print("RSSI:");
  Serial.println(rssi);
  delay(500);
  }
