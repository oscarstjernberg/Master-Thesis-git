// Include SoftwareSerial and Wifi library
// Install libraries by go to Sketch --> Include Library --> Manage Libraries and search for WiFiesp.
// Communication with the WiFi-modelule is done by 9600 bd and the serial monitore communicates via 115200 bd.


#include <SoftwareSerial.h>
#include "WiFiEsp.h"

// Create WiFi module object on GPIO pin 6 (RX) and 7 (TX)
SoftwareSerial Serial1(6, 7);

// Declare and initialise global arrays for WiFi settings
char ssid[] = "Combine";
char pass[] = "plasmakorv";

// Declare and initialise variable for radio status 
int status = WL_IDLE_STATUS;

void setup() {
  
  // Initialize serial for debugging
  Serial.begin(115200);
  
  // Initialize serial for ESP module
  Serial1.begin(9600);
  
  // Initialize WiFi-module
  WiFi.init(&Serial1);

  // Check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    
    // Don't continue
    while (true);
  }
  
  // Attempt to connect to WiFi network
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  Serial.println("You're connected to the network");
  printWifiStatus();
}

void printWifiStatus() {
  
  // Print the SSID of the network
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // Print the IP address
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}

void loop() {

}
