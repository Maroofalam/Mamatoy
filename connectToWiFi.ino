// Function to Connect to WiFi in Client Mode
bool connectToWiFi() {
  WiFi.begin(clientSSID.c_str(), clientPassword.c_str());
//clientSSID.c_str() and clientPassword.c_str() convert the String type into a char* (C-style string), which is required by WiFi.begin().
  unsigned long startTime = millis();//milis stored in startTime to track the connection timeout (maximum wait time).
  while (WiFi.status() != WL_CONNECTED  && millis()-startTime <10000) {
    delay(500);
    Serial.print(".");
    if(WiFi.status()==WL_CONNECTED){
        Serial.println("WifiCONNECTED");
    }
    return false;
  }
 mp3_play(7013);  // 🔊 "Trying to connect to WiFi"
  delay(6000);
  Serial.println("\nConnected to WiFi!");
 mp3_play(7011);  // 🔊 Play "WiFi connected" audio
  delay(3000); 
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());//mob ip

  return true;
}