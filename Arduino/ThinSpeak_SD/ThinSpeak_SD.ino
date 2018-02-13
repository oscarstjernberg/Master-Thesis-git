 // Include SoftwareSerial and Wifi library
#include <SoftwareSerial.h>
#include "ThingSpeak.h"
#include "WiFiEsp.h"
#include <string.h>
#include <SD.h>
#include <avr/pgmspace.h>

////////////////////////////////////
//          WIFI SETTINGS         //
///////////////////////////////////

// Create WiFi module object on GPIO pin 6 (RX) and 7 (TX)
SoftwareSerial SerialWifi(6, 7);
WiFiEspClient client;

// Declare and initialise global arrays for WiFi settings
char ssid[] = "Combine";
char pass[] = "plasmakorv";

// Declare and initialise variable for radio status
int status = WL_IDLE_STATUS;

// TingSpeak channel ID and API-key.
unsigned long myChannelNumber  = 420692;
const char * myWriteAPIKey = "A86F3R21OEZKIIQQ";

////////////////////////////////////
//          SD SETTINGS           //
///////////////////////////////////
File BackupFile;
int SD_pin = 4;


////////////////////////////////////
//          MISC SETTINGS         //
///////////////////////////////////

int PotPin = A0;

////////////////////////////////////
//          SETUP                 //
///////////////////////////////////
void setup() {

  // Initialize serial for SerialWifiging
  Serial.begin(115200);

  // Initialize serial for ESP module
  SerialWifi.begin(9600);
  
  // Initialize SD-card
   SDinit(SD_pin);
   
  // Connect to wifi
  connectToWiFi();

  // Starts thingspeak client 
  ThingSpeak.begin(client);

}

////////////////////////////////////
//          LOOP                  //
///////////////////////////////////
void loop() {
  
  int P = analogRead(PotPin);// turn integer to string
  Serial.println(P);

  // Write to ThingSpeak channel
  ThingSpeak.setField(1,P);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

  // Write to SD-card
  SDwrite(P);

  delay(3000); //
}

////////////////////////////////////
//       Functions - WIFI         //
///////////////////////////////////

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

//////////////////////////////////////////////////////////////////////

void printWifiStatus() {

  // Print the SSID of the network
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // Print the IP address
  IPAddress ip = WiFi.localIP();
  Serial.print(F("IP Address: "));
  Serial.println(ip);
}// printWifiStatus


////////////////////////////////////
//       Functions - SD           //
///////////////////////////////////

  // INITIALIZES SD CARD
  
  void SDinit(int SD_pin)
  {
    Serial.print(F("Initializing SD card..."));
    if (!SD.begin(SD_pin)) {
      Serial.println(F("Initialization SD-card failed!"));
      while (1);
    }
    Serial.println(F("Initialization SD-card done."));

    // Open file for writing
    BackupFile = SD.open("Backup.txt", FILE_WRITE);

    // If the file is open-write
    if (BackupFile)
    {
      BackupFile.print("Time\tMeasurement");
      BackupFile.println();
    }
    else {
      Serial.println(F("ERROR: File not found"));
    }
    BackupFile.close();
  } // SD_init

//////////////////////////////////////////////////////////////////////
    // WRITES CONTENT OF SG TO SD CARD
  void SDwrite(int SG) {

    // Open file for writing
    BackupFile = SD.open("Backup.txt", FILE_WRITE);

    // If the file is open-write
    if (BackupFile)
    {
      // Write time
      BackupFile.print(millis());
      BackupFile.print("\t");
      // Write Measurement value
      BackupFile.println(SG);

      Serial.print(F("Writing to SD-card: \t"));
      Serial.print(millis());
      Serial.print("\t");
      // Write Measurement value
      Serial.println(SG);
    }
    else {
      Serial.println(F("ERROR: File not found"));
    }
    BackupFile.close();

  } // Write to sd

  //////////////////////////////////////////////////////////////////////
