// Include SoftwareSerial and Wifi library
#include <SoftwareSerial.h>
#include "WiFiEsp.h"
#include <string.h>
#include <SD.h>
#include <avr/pgmspace.h>
#include "ThingSpeak.h"


////////////////////////////////////
//          WIFI SETTINGS         //
///////////////////////////////////

// Create WiFi module object on GPIO pin 6 (RX) and 7 (TX)
SoftwareSerial SerialWifi(6, 7);
WiFiEspClient client;


// Declare and initialise global arrays for WiFi settings
char ssid[] = "Combine";
char pass[] = "plasmakorv";
char server[] = "api.pushingbox.com";
char cmd[100];

// Declare and initialise variable for radio status
int status = WL_IDLE_STATUS;

////////////////////////////////////
//      ThingSpeak SETTINGS       //
////////////////////////////////////

unsigned long myChannelNumber  = 420692; // Channel ID
const char * myWriteAPIKey = "A86F3R21OEZKIIQQ";  // Channel API-key

////////////////////////////////////
//          SD SETTINGS           //
///////////////////////////////////
File BackupFile;
int SD_pin = 4;


////////////////////////////////////
//          MISC SETTINGS         //
///////////////////////////////////

int PotPin = A0;

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

  // Initialize ThingSpeak
  ThingSpeak.begin(client);

}


////////////////////////////////////
//          LOOP                  //
///////////////////////////////////
void loop() {
  int P = analogRead(PotPin);// turn integer to string
  Serial.println(P);
  Serial.println(WiFi.status());
  
  if(WiFi.status()!=1){
    status = WL_IDLE_STATUS;
    connectToWiFi();
      Serial.println("reconnect");
    }


  // Write to ThingSpeak
  ThingSpeak.setField(1,P );
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
    
  // Write to google spreadsheet
  sendToSpreadsheet(P);

  // Write to SD-card
  SDwrite(P);

 // Get current time from web
  webTime(client);
  delay(3000); //
  
}

////////////////////////////////////
//       Functions - WIFI         //
///////////////////////////////////

void sendToSpreadsheet(int P) {

  // Constructing GET request string
  sprintf(cmd, "GET /pushingbox?devid=vAADBEE37B57A997&status=%d HTTP/1.1", P);
  Serial.println(cmd);
  Serial.println(F("Starting connection to server..."));

  // if you get a connection, report back via serial
  if (client.connect(server, 80)) {
    Serial.println(F("Connected to server"));
    // Make a HTTP request
    client.println(cmd);
    client.println(F("Host: api.pushingbox.com"));
    client.println(F("Connection: close"));
    client.println();
    client.stop();
  }
}

//////////////////////////////////////////////////////////////////////

void connectToWiFi()
{
  // Initialize ESP module
  WiFi.init(&SerialWifi);

  // Check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    
    Serial.println(F("WiFi shield not present"));
    status = WL_NO_SHIELD;

  }

  // Attempt to connect to WiFi network
  if(status != WL_CONNECTED && status != WL_NO_SHIELD) {
    Serial.print(F("Attempting to connect to SSID: "));
    Serial.println(ssid);

    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }
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

//////////////////////////////////////////////////////////////////////
void webTime (Client &client)
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
      DT.month = str.substring(0,3);
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
    String time_str = String(DT.year)+DT.month+String(DT.day)+String(DT.hour)+String(DT.minute)+String(DT.second);
    Serial.println(time_str);
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
