#include <ESP8266WiFi.h>
#include <SD.h>
#include <ThingSpeak.h>
#include <HX711_ADC.h>
#include <SPI.h>
#include <Adafruit_MAX31865.h>

#define Board_3;  // Board_1, Board_2, Board_3

////////////////////////////////////
//          WIFI SETTINGS         //
////////////////////////////////////

WiFiClient client;

// Declare and initialise global arrays for WiFi settings
char ssid[] = "Combine";
char pass[] = "plasmakorv";
char server[] = "api.pushingbox.com";
char cmd[100];

int status = WL_IDLE_STATUS;

////////////////////////////////////
//          SD SETTINGS           //
///////////////////////////////////
File BackupFile;
const int SD_pin = D4;

enum months { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
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
#if defined(Board_1)
  unsigned long myChannelNumber = 420692; // Channel ID
  const char * myWriteAPIKey = "A86F3R21OEZKIIQQ";  // Channel API-key
#endif

#if defined(Board_2)
  unsigned long myChannelNumber = 441326; // Channel ID
  const char * myWriteAPIKey = "8H4EAGF3VE2IF6UT";  // Channel API-key
#endif

#if defined(Board_3)
  unsigned long myChannelNumber = 441330; // Channel ID
  const char * myWriteAPIKey = "Q3I84GD3QUIC1LQT";  // Channel API-key
#endif
////////////////////////////////////
//      Loadcell SETTINGS         //
////////////////////////////////////



//HX711 constructor (dout pin, sck pin)
HX711_ADC LoadCell(D1, D0);

long t;

////////////////////////////////////
//          MAX31865             //
///////////////////////////////////


// Use software SPI: CS, DI, DO, CLK
Adafruit_MAX31865 maxx = Adafruit_MAX31865(4, 9, 10, 0);
//Adafruit_MAX31865 maxx = Adafruit_MAX31865(D2);
// Reference value for a PT100 sensor, if using PT1000 use RREF = 4300.
#define RREF      430.0
#define RNOMINAL  100.0


////////////////////////////////////
//          MISC SETTINGS         //
///////////////////////////////////

int PotPin = A0;
int delaySeconds = 10;
int loopTime = delaySeconds * 1000;

// counters for data saving
int countPush = 10;
int countTS = 10;

long previousMillis = 0;
long interval = 20000;

int SD_LED = D8;
int WiFi_LED = D3;

SPISettings settingsPT(500000, MSBFIRST, SPI_MODE1);
SPISettings settingsSD(14000000, LSBFIRST, SPI_MODE0);

//////////////////// WiFi functions /////////////////////

void connectToWiFi() {
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFI connected!");
  digitalWrite(WiFi_LED, HIGH);     // Turns the LED on to indicate WiFi connection is established
  Serial.println();
  Serial.print(ssid);
  Serial.println();
  Serial.println(WiFi.localIP());
  Serial.print("Wifistatus ");
  Serial.println(WiFi.status());
}// end connectToWiFi

// WiFiConnection
void checkWiFiConnection() {
  if (WiFi.status() != 3) {
    status = WL_IDLE_STATUS;
    connectToWiFi();
    Serial.println("reconnect");
  }
}// end WiFiConnection

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
    BackupFile.print("Time\tMeasurement\tTemperature");
    BackupFile.println();
  }
  else {
    Serial.println(F("ERROR: File not found"));
  }
  BackupFile.close();
} // SD_init end


// WRITES CONTENT OF SG TO SD CARD
void SDwrite(float SG, float temp) {

  digitalWrite(SD_LED, HIGH); // Indicates that we are writning to SD-card

  String time_str;

  // Open file for writing
  BackupFile = SD.open("Backup.txt", FILE_WRITE);

  // If the file is open-write
  if (BackupFile)
  {
    // Write time
    if (WiFi.status() == 3) {
      time_str = String(DT.year) + "-" + DT.month + "-" + String(DT.day) + ":" + String(DT.hour) +
                 ":" + String(DT.minute) + ":" + String(DT.second);
      Serial.println(time_str);
      BackupFile.print(time_str);
    }
    else {
      BackupFile.print(millis());
    }

    BackupFile.print("\t");
    // Write Measurement value
    BackupFile.print(SG);
    BackupFile.print("\t");
    BackupFile.println(temp);

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
void loadCellInit() {
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

///////////////////////////////// Temperature function ////////////////////////////////////////////
float tempRead() {
  uint16_t rtd = maxx.readRTD();

  Serial.print("RTD value: "); Serial.println(rtd);
  float ratio = rtd;
  ratio /= 32768;
  Serial.print("Ratio = "); Serial.println(ratio, 8);
  Serial.print("Resistance = "); Serial.println(RREF * ratio, 8);
  Serial.print("Temperature = "); Serial.println(maxx.temperature(RNOMINAL, RREF));


  // Check and print any faults
  uint8_t fault = maxx.readFault();
  if (fault) {
    Serial.print("Fault 0x"); Serial.println(fault, HEX);
    if (fault & MAX31865_FAULT_HIGHTHRESH) {
      Serial.println("RTD High Threshold");
    }
    if (fault & MAX31865_FAULT_LOWTHRESH) {
      Serial.println("RTD Low Threshold");
    }
    if (fault & MAX31865_FAULT_REFINLOW) {
      Serial.println("REFIN- > 0.85 x Bias");
    }
    if (fault & MAX31865_FAULT_REFINHIGH) {
      Serial.println("REFIN- < 0.85 x Bias - FORCE- open");
    }
    if (fault & MAX31865_FAULT_RTDINLOW) {
      Serial.println("RTDIN- < 0.85 x Bias - FORCE- open");
    }
    if (fault & MAX31865_FAULT_OVUV) {
      Serial.println("Under/Over voltage");
    }
    maxx.clearFault();
  }
  Serial.println();
  return maxx.temperature(RNOMINAL, RREF);

}// end tempRead
//////////////////////////////// Get time function ///////////////////////////////////////////////

void webTime(Client &client)
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
      DT.month = str.substring(0, 3);
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

} // end webTime

////////////////////////////// End functions //////////////////////////////////////////////////////

////////////////////////////////////
//          SETUP                 //
///////////////////////////////////

void setup() {

  // Status LEDs setup
  pinMode(WiFi_LED, OUTPUT);
  pinMode(SD_LED, OUTPUT);

  Serial.begin(115200);
  delay(10);

  // Starts the MAX31865 with a 3-wired connection, for 2 or 4 wire connection change to 2WIRE respectly 4Wire
  maxx.begin(MAX31865_3WIRE);

  // connect to WiFi
  connectToWiFi();

  // Initialize SD-card
  SDinit(SD_pin);

  // Initialize reading the load cell
  loadCellInit();

  // ThingSpeak setup
  ThingSpeak.begin(client);

  // Starts SPI protocol
  SPI.begin();

}// end Setup

////////////////////////////////////
//          MAIN                  //
///////////////////////////////////

void loop() {

  unsigned long timeMillis = millis();

  // Reads the temperature of the PT100or PT1000 sensor
  float temp = tempRead();

  digitalWrite(SD_LED, LOW);    // Turn off the status LED.
  delay(5000);

  // Get current time from the web
  if (WiFi.status() == 3) {
    webTime(client);
  }

  // read value from load cell
  float val = loadCellRead();

  // Writes the loadcell value and the temperature to the SD-card
  SDwrite(val, temp);

  // send to thingspeak
  if ((timeMillis - previousMillis) >= 20000 && WiFi.status() == 3) {
    previousMillis = timeMillis;
    Serial.print("Sending to ThingSpeak ");
    Serial.println(val);
    ThingSpeak.setField(1, val);    // Sends the loadcell value to field 1 in the ThingSpeak channel
    ThingSpeak.setField(2, temp);   // Sends the temperature to field 2 in the ThingSpeak channel
    ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  }
}// end main loop

