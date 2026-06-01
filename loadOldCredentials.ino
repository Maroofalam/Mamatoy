// Function to Load Old ESP8266 WiFi Credentials from SPIFFS
void loadOldAPCredentials() {
  if (!SPIFFS.exists("/old_ap_wifi.txt")) {
    Serial.println("No old ESP8266 WiFi credentials found in SPIFFS.");
    return;
  }

  File file = SPIFFS.open("/old_ap_wifi.txt", "r");
  if (!file) {
    Serial.println("Failed to open file for reading old AP credentials.");
    return;
  }

  ap_ssid = file.readStringUntil('\n');
  ap_password = file.readStringUntil('\n');
  file.close();

  ap_ssid.trim();
  ap_password.trim();

  Serial.println("Loaded Old ESP8266 WiFi Credentials:");
  Serial.println("ESP8266 WiFi SSID: " + ap_ssid);
  Serial.println("ESP8266 WiFi PASSWORD: " + ap_password);
}

// Function to Save Old ESP8266 WiFi Credentials in SPIFFS
void saveOldAPCredentials(const String &ssid, const String &password) {
  File file = SPIFFS.open("/old_ap_wifi.txt", "w");
  if (!file) {
    Serial.println("Failed to open file for writing old AP credentials!");
    return;
  }
  file.println(ssid);
  file.println(password);
  
  file.close();
  Serial.println("Old ESP8266 WiFi Credentials Saved Successfully!");
}