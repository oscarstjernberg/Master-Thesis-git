// Include SoftwareSerial and Wifi library
// Install libraries by go to Sketch --> Include Library --> Manage Libraries and search for WiFiesp.
// Communication with the WiFi-modelule is done by 9600 bd and the serial monitore communicates via 115200 bd.


#include <SoftwareSerial.h>
#include "WiFiEsp.h"
#include "ThingSpeak.h"

int PotPin = A0;


// Create WiFi module object on GPIO pin 6 (RX) and 7 (TX)
SoftwareSerial SerialWifi(6, 7);
WiFiEspClient client;


// Declare and initialise global arrays for WiFi settings
char ssid[] = "Combine";
char pass[] = "plasmakorv";

// Declare and initialise variable for radio status 
int status = WL_IDLE_STATUS;



unsigned long myChannelNumber  = 420692;
const char * myWriteAPIKey = "A86F3R21OEZKIIQQ";

void setup() {

  
  // Initialize serial for debugging
  Serial.begin(115200);
  
  // Initialize serial for ESP module
  SerialWifi.begin(9600);
  //Serial.begin(9600);
  
  connectToWiFi();

//  WiFiClient client;
  ThingSpeak.begin(client);
  
}// end of setup

void connectToWiFi()
{
  // Initialize ESP module
  WiFi.init(&SerialWifi);

  // Check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println(F("WiFi shield not present"));

    // Don't continue
    while (true);
  }

  // Attempt to connect to WiFi network
  while (status != WL_CONNECTED) {
    Serial.print(F("Attempting to connect to SSID: "));
    Serial.println(ssid);

    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  Serial.println(F("You're connected to the network"));
  printWifiStatus();
}//connectToWiFi

void printWifiStatus() {

  // Print the SSID of the network
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // Print the IP address
  IPAddress ip = WiFi.localIP();
  Serial.print(F("IP Address: "));
  Serial.println(ip);
}// printWifiStatus



void loop() {
  delay(2000);

 
  
  float p = analogRead(PotPin);

  Serial.print(analogRead(p));

  ThingSpeak.setField(1,p);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

}
