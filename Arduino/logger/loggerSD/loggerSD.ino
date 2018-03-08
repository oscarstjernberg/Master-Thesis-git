#include <SD.h>
#include <HX711_ADC.h>
#include <Adafruit_MAX31865.h>

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

long previousMillis = 0;
long interval = 2000;    // Data collect interval

//////////////////////// SD-card functions ////////////////////////////////////

// INITIALIZES SD CARD

void SDinit(int SD_pin)
{
  Serial.print("Initializing SD card...");
  if (!SD.begin(SD_pin)) {
    Serial.println("Initialization SD-card failed!");
    while (1);
  }
  Serial.println("Initialization SD-card done.");

  // Open file for writing
  BackupFile = SD.open("Backup.txt", FILE_WRITE);

  // If the file is open-write
  if (BackupFile)
  {
    BackupFile.print("Time\tMeasurement\tTemperature");
    BackupFile.println();
  }
  else {
    Serial.println("ERROR: File not found");
  }
  BackupFile.close();
} // SD_init end


// WRITES CONTENT OF SG TO SD CARD
void SDwrite(float SG, float temp) {

  String time_str;

  // Open file for writing
  BackupFile = SD.open("Backup.txt", FILE_WRITE);

  // If the file is open-write
  if (BackupFile)
  {
    // Write time
    BackupFile.print(millis());
    
    BackupFile.print("\t");
    // Write Measurement value
    BackupFile.print(SG);
    BackupFile.print("\t");
    BackupFile.println(temp);
  }
  else {
    Serial.println("ERROR: File not found");
  }
  BackupFile.close();
} // Write to sd end

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
  return  val;
} // loadCellRead end

///////////////////////////////// Temperature function ////////////////////////////////////////////
float tempRead() {
  uint16_t rtd = maxx.readRTD();

  float ratio = rtd;
  ratio /= 32768;
  
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
  return maxx.temperature(RNOMINAL, RREF);
}// end tempRead

////////////////////////////// End functions //////////////////////////////////////////////////////

////////////////////////////////////
//          SETUP                 //
///////////////////////////////////

void setup() {

  Serial.begin(115200);
  delay(10);

  // Starts the MAX31865 with a 3-wired connection, for 2 or 4 wire connection change to 2WIRE respectly 4Wire
  maxx.begin(MAX31865_3WIRE);

  SDinit(SD_pin);

   // Initialize reading the load cell
  loadCellInit();

} // end Setup

////////////////////////////////////
//          MAIN                  //
///////////////////////////////////

void loop() {

  unsigned long timeMillis = millis();
  
   //Reads the temperature of the PT100or PT1000 sensor
  float temp = tempRead();

   //read value from load cell
  float val = loadCellRead();

  if ((timeMillis - previousMillis) >= interval){
      Serial.print("Writing to SD-card"); Serial.println();
      Serial.print("Temperature = ");  Serial.println(temp);
      Serial.print("Load = ");  Serial.println(val);
      Serial.println();
      previousMillis = timeMillis;
      SDwrite(val,temp);
    }
  
}
