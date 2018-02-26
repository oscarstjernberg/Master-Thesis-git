#include <ESP8266WiFi.h>
#include <SD.h>
#include <ThingSpeak.h>
#include <HX711_ADC.h>
#include <SPI.h>

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
int SD_pin = 15;

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
//      Loadcell SETTINGS         //
////////////////////////////////////



//HX711 constructor (dout pin, sck pin)
HX711_ADC LoadCell(D1, D2);

long t;

////////////////////////////////////
//          MISC SETTINGS         //
///////////////////////////////////

int PotPin = A0;
int delaySeconds = 10;
int loopTime = delaySeconds * 1000;

// counters for data saving
int countPush = 10;
int countTS = 10;


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
} // SD_init end


// WRITES CONTENT OF SG TO SD CARD  
void SDwrite(float SG) {

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

} // Write to sd end

////////////////////////////// Load cell functions //////////////////////////////////////////////////////

// Initialize load cell
void loadCellInit(){
	ESP.wdtDisable();
	ESP.wdtEnable(WDTO_8S);
	delay(0);
	Serial.begin(115200);
	LoadCell.begin();
	long stabilisingtime = 2000; // tare preciscion can be improved by adding a few seconds of stabilising time
	LoadCell.start(stabilisingtime);
	LoadCell.setCalFactor(696.0); // user set calibration factor (float)
	Serial.println("Startup + tare is complete");
} // Initialize load cell end


float loadCellRead() {
	ESP.wdtFeed();
	//update() should be called at least as often as HX711 sample rate; >10Hz@10SPS, >80Hz@80SPS
	//longer delay in scetch will reduce effective sample rate (be carefull with delay() in loop)
	LoadCell.update();
  float val;
	//get smoothed value from data set + current calibration factor
	if (millis() > t + 250) {
		val = LoadCell.getData();
		Serial.print("Load_cell output val: ");
		Serial.println(val);
		t = millis();
	}

	//receive from serial terminal
	if (Serial.available() > 0) {
		val;
		char inByte = Serial.read();
		if (inByte == 't') LoadCell.tareNoDelay();
	}

	//check if last tare operation is complete
	if (LoadCell.getTareStatus() == true) {
		Serial.println("Tare complete");
	}
	
	return	val;

} // loadCellRead end

////////////////////////////// End functions //////////////////////////////////////////////////////

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

  // Initialize reading the load cell
  loadCellInit();

  // ThingSpeak setup
  ThingSpeak.begin(client);

}

////////////////////////////////////
//          MAIN                  //
///////////////////////////////////

void loop() {

	// read value from load cell
	float val = loadCellRead();

	// Write to SD-card
	SDwrite(val);
  
	// send to thingspeak
  ThingSpeak.setField(1,val);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);


  
}

