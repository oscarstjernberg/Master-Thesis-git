#include <SoftwareSerial.h>
#include "WiFiEsp.h"
int PotPin = A0;
int value_pot;

#define DEBUG FALSE //comment out to remove debug msgs

//*-- Hardware Serial
#define _baudrate 9600

//*-- Software Serial
//
//#define _rxpin      2
//#define _txpin      3
SoftwareSerial debug(2,3); // RX, TX

                    //*-- IoT Information
#define SSID "Combine"
#define PASS "plasmakorv"
#define IP "184.106.153.149" // ThingSpeak IP Address: 184.106.153.149

                    // GET /update?key=[THINGSPEAK_KEY]&field1=[data 1]&field2=[data 2]...;
String GET = "GET /update?key=update?api_key=A86F3R21OEZKIIQQ";

void setup() {
  Serial.begin(9600);
  debug.begin(9600);

  sendDebug("AT");
  delay(5000);
  connectWiFi();
 
  
  if (Serial.find("OK"))
  {
    debug.println("RECEIVED: OK\nData ready to sent!");
    connectWiFi();
  }
  else 
  {
    Serial.println("Kabbel");
    
    }
    

}

void loop() {
  value_pot = analogRead(PotPin);

  String pot = String(value_pot);// turn integer to string

  updateTS(pot);
  delay(3000); //
}

//----- update the  Thingspeak string with 3 values
void updateTS(String P)
{
  // ESP8266 Client
  String cmd = "AT+CIPSTART=\"TCP\",\"";// Setup TCP connection
  cmd += IP;
  cmd += "\",80";
  sendDebug(cmd);
  delay(2000);
  if (Serial.find("Error"))
  {
    debug.print("RECEIVED: Error\nExit1");
    return;
  }

  cmd = GET + "&field1=" + P + "\r\n";
  Serial.print("AT+CIPSEND=");
  Serial.println(cmd.length());
  //Serial.println(cmd);
  //if (Serial.find(">"))
  //{
    debug.print(">");
    debug.print(cmd);
    Serial.println(cmd);
  //}
  //else
  //{
    sendDebug("AT+CIPCLOSE");//close TCP connection
  //}
  if (Serial.find("OK"))
  {
    debug.println("RECEIVED: OK");
  }
  else
  {
    debug.println("RECEIVED: Error\nExit2");
  }
}

void sendDebug(String cmd)
{
  debug.print("SEND: ");
  debug.println(cmd);
  Serial.println(cmd);
}

boolean connectWiFi()
{
  Serial.println("AT+CWMODE=1");//WiFi STA mode - if '3' it is both client and AP
  delay(2000);
  //Connect to Router with AT+CWJAP="SSID","Password";
  // Check if connected with AT+CWJAP?
  String cmd = "AT+CWJAP=\""; // Join accespoint
  cmd += SSID;
  cmd += "\",\"";
  cmd += PASS;
  cmd += "\"";
  sendDebug(cmd);
  delay(5000);
  if (Serial.find("OK"))
  {
    debug.println("RECEIVED: OK");
    return true;
  }
  else
  {
    debug.println("RECEIVED: Error");
    return false;
  }

  cmd = "AT+CIPMUX=0";// Set Single connection
  sendDebug(cmd);
  if (Serial.find("Error"))
  {
    debug.print("RECEIVED: Error");
    return false;
  }
}
