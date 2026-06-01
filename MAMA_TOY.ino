#include "Wire.h"
#include "RTClib.h"
#include "SoftwareSerial.h"
// #include "DFPlayerMini_Fast.h"
 #include<DFPlayer_Mini_Mp3.h>
 #define PIN_MP3_TX 16
#define PIN_MP3_RX 2
 SoftwareSerial mp3Serial(2, 16);
#include <FS.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESPAsyncWebServer.h>
#include <SPI.h>
#include <MFRC522.h>
#include <WiFiClientSecure.h>  

RTC_DS3231 rtc;
#define RST_PIN 0
#define SS_PIN 15
// #define PIN_MP3_TX 16
// #define PIN_MP3_RX 2
//SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);
//DFPlayerMini_Fast player;
bool shortPressDetected = false;

String ap_ssid = "ESP8266-AP";
String ap_password = "123456789";
bool sendOfflineAfterThis = false;  // 🔧 THIS was missing
const char*   serverURL = "http://connect2mfi.org/deviotapps/index.php/toyinitilization";
const int batteryPin = A0;
const int buttonPin = 2;
long buttonTimer = 0;
long longPressTime = 3000;
long timeoutDuration = 5000;
long startMillis = 0;
boolean buttonActive = false;
boolean longPressActive = false;
boolean timeoutOccurred = false;
bool batteryPlayed = false;
String manufacture_id = "ZMQ_TOY_015"; 
String clientSSID = "";
String clientPassword = "";
bool hasSaved = false;
String ToyID = "";  
AsyncWebServer server(80);
MFRC522 mfrc522(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;
String parsedData[49];  // Make sure this is filled from RFID
const char* offlineFilePath = "/offline_data.txt";  // File to store offline data
const char* allUploadsPath = "/last_uploads.txt";
int week = 0;
bool firstScan = true;
String childData[10];
int totalFields = 0;
String cardUID = "";
bool toyIdPlayed = false;
bool cardDetected = false;
bool newCardScanned = false;  // Flag to indicate a new RFID card was scanned
bool rfidReady = false;       // Flag to control RFID scan timing
// === Toy ID Related Function Prototypes ===
String getToyIDFromServer(String manufactureID);
String getToyID(String manufactureID);
String readToyID();
boolean saveToyID(String receivedID);
boolean bat_percent();
void readButtonState();
void handleRFID();
void ageCal();
void startAccessPoint();
String getCardUID();
int parseRFIDDataTillDOB(String data, String outputArray[]);
void printChildData();
String readRFIDDataTillDOB();  



void initializeRFID() {
  SPI.begin();
  mfrc522.PCD_Init();
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;
  Serial.println("RFID Reader Ready. Bring a card close to scan...");
}
   
    
void setup() {
  randomSeed(analogRead(A0));

   Serial.begin(115200);
   mp3Serial.begin(9600);
   mp3_set_serial(mp3Serial);
   mp3_set_volume(25);
   delay(2000);
  //softwareSerial.begin(9600);
  Wire.begin();
  pinMode(buttonPin, INPUT_PULLUP);
  startMillis = millis();

 if (!SPIFFS.begin()) {
  Serial.println("SPIFFS Mount Failed!");
  return;
  }

  Serial.println("Initializing DFPlayer Mini...");
 if (!mp3Serial) {
  delay(2000);
  Serial.println("Error: DFPlayer Mini not found. Check wiring & SD card.");
  while (true);
  }
  Serial.println("DFPlayer Mini Ready!");
 // player.volume(20);
 // delay(1000);
  Serial.println("Initializing RTC...");
 if (!rtc.begin()) {
  Serial.println("RTC not found. Playing error...");
 mp3_play(7064);
  delay(4000);
  while (1);
  }
  //  if (SPIFFS.exists(offlineFilePath)) {
  //   File file = SPIFFS.open(offlineFilePath, "r");
  //   while (file.available()) {
  //     Serial.println(file.readStringUntil('\n'));
  //   }
  //   file.close();
  // }

  // // Try sending any saved offline data on boot
  // connectToWiFi();
  // if (WiFi.status() == WL_CONNECTED) {
  //   sendLastOfflineDataToServer();
  // }
 if (rtc.lostPower()) {
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  Serial.println("RTC Initialized.");
  delay(1000);

 mp3_play(7000);//welcm msg
  delay(4000);
 mp3_play(7001);//ye  aapko aapke bche ke tika.......
  delay(6000);

  boolean batStatus = bat_percent();
 if (!batStatus)
  {
 // return;
  }

  //for new board server se toy id fetch ke lye  
  Serial.println("Connecting to WiFi...");
  Serial.println(readClientSSID());
  Serial.println(readClientPassword());
  if(readClientSSID() != "" &&readClientPassword() != ""){
    mp3_play(7013);
    delay(6000);
  WiFi.begin(readClientSSID(), readClientPassword());
  int newStartTime = millis();
 while (WiFi.status() != WL_CONNECTED  && millis()-newStartTime <10000) {
  delay(500);
  Serial.print(".");
 if(WiFi.status()==WL_CONNECTED){
    mp3_play(7011);
    delay(3000);
  Serial.println("Wifi CONNECTED");      
    }
    }
 if(WiFi.status()!=WL_CONNECTED){
    mp3_play(7012);
    delay(4000);
  Serial.println("NOT CONNECTED");
    }
  } 
 else {
  Serial.println("NOT CONNECTED");
  }
     
  String ToyID = readToyID();  // Try to read existing Toy ID
  Serial.print(F("Toy ID read from File: ")); Serial.println(ToyID);

  while (ToyID == "0" || ToyID == "") {
  String res = getToyID(manufacture_id);  // Call API (will fail if no WiFi)
  Serial.print(F("Response: ")); Serial.println(res);
  bool saveStatus = saveToyID(res);
 if (saveStatus) {
  Serial.println(F("Toy ID saved into file successfully."));
  break;
    }
  ToyID = readToyID();  // Retry reading after saving
  break; // prevent infinite loop if WiFi isn't available
  }

  Serial.println("PLAYING MP3 TOYID");
  ToyID = readToyID();
  int id = ToyID.toInt();
 mp3_play(7002); // "Meri manufacturing ID"
  delay(5000);
 mp3_play(id); // Toy ID (e.g. 46)
  delay(2000);
 mp3_play(7003); // "Hai"
  delay(2000);
 mp3_play(7008); // short/long press instruction
  delay(11000);
  
// Wait for button press up to 10 seconds
  unsigned long waitStart = millis();
  bool btnDetected = false;

 while (millis() - waitStart < 5000) {
  readButtonState(); // This will update flags or handle short/long press
 if (buttonActive || longPressActive) {
  btnDetected = true;
  break;
  }
  delay(100);
}

 if (!btnDetected) {
   mp3_play(7009); // "Please scan card"
  delay(4000);
  initializeRFID();
  rfidReady = true;
  readRFIDDataTillDOB();
}
 
 
}

void loop() {
  readButtonState();
  ageCal();
  handleRFID();
}


String readClientSSID() {
  File file = SPIFFS.open("/wifi.txt", "r"); // Open file for reading
  if (!file) {
  Serial.println(" Failed to open file for reading WiFi credentials!");
  return "";
  }

  String ssid = file.readStringUntil('\n');
  ssid.trim(); // Remove newline or spaces
  String password = file.readStringUntil('\n');
  password.trim();
  file.close();
  return ssid;
}          

String readClientPassword() {
  File file = SPIFFS.open("/wifi.txt", "r"); // Open file for reading
  if (!file) {
  Serial.println(" Failed to open file for reading WiFi credentials!");
  return "";
  }

  String ssid = file.readStringUntil('\n');
  ssid.trim(); // Remove newline or spaces
  String password = file.readStringUntil('\n');
  password.trim();
  file.close();
  return password;
}
 
