#include <ESP8266WiFi.h>
#include <SD.h>


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
File BackupFile;
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


//////////////////////// SD-card functions ////////////////////////////////////

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


// WRITES CONTENT OF SG TO SD CARD  
void SDwrite(int SG) {

  String time_str;

  // Open file for writing
  BackupFile = SD.open("Backup.txt", FILE_WRITE);

  // If the file is open-write
  if (BackupFile)
  {
    // Write time
    if (WiFi.status() == 1) {
      time_str = String(DT.year) + "-" + DT.month + "-" + String(DT.day) + ":" + String(DT.hour) + ":" + String(DT.minute) + ":" + String(DT.second);
      Serial.println(time_str);
      BackupFile.print(time_str);
    }
    else {
      BackupFile.print(millis());
    }

    BackupFile.print("\t");
    // Write Measurement value
    BackupFile.println(SG);

    Serial.print(F("Writing to SD-card: \t"));
    Serial.print(time_str);
    Serial.print("\t");
    // Write Measurement value
    Serial.println(SG);
  }
  else {
    Serial.println(F("ERROR: File not found"));
  }
  BackupFile.close();

} // Write to sd


////////////////////////////// main //////////////////////////////////////////////////////

void loop() {
  // put your main code here, to run repeatedly:

}

