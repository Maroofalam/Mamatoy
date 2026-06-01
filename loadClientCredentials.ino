// Function to Load Client WiFi Credentials from SPIFFS
bool loadClientCredentials() {//reads WiFi SSID and password from SPIFFS.
  if (!SPIFFS.exists("/wifi.txt")) return false;

  File file = SPIFFS.open("/wifi.txt", "r");//File object is created to handle the file.
  if (!file) {
    Serial.println("Failed to open file for reading client credentials.");
    return false;
  }

  clientSSID = file.readStringUntil('\n');//Reads the first line of the file and stores it in clientSSID.
  clientPassword = file.readStringUntil('\n');
  //readStringUntil('\n') function reads text until a newline (\n) is encountered.
  file.close();
  clientSSID.trim();
  clientPassword.trim();

  //Serial.println("Loaded Client WiFi Credentials:");
  //Serial.println("Client SSID: " + clientSSID);
  //Serial.println("Client PASS: " + clientPassword);
  return true;
}

// Function to Save Client WiFi Credentials in SPIFFS
void saveClientCredentials() {
  File file = SPIFFS.open("/wifi.txt", "w");//If the file already exists, it will be overwritten with new credentials.
  //Serial.println(file);
  if (!file) {
    Serial.println("Failed to open file for writing client credentials!");
    return;
  }
  file.println(clientSSID);//Writes clientSSID and clientPassword into the file, each on a separate line.
  file.println(clientPassword);
  file.close();//Closes the file after writing to save changes and free up memory.
  Serial.println("New WiFi Credentials Saved Successfully!");
  WiFi.begin(clientSSID, clientPassword);
}

