void readButtonState() {
    static bool systemLocked = false; // Lock system after timeout
    static bool buttonActive = false;//Tracks if the button is currently being pressed to avoid multiple detections.
    static bool longPressActive = false;
    static unsigned long buttonTimer = 0;//Records the time when the button is first pressed.
    static unsigned long startMillis = millis(); // Stores when function starts, used for timeout detection.
    static bool timeoutOccurred = false;//Tracks if the timeout event has already happened,
    static bool buttonEverPressed = false; //Tracks if the button has been pressed at least once (prevents timeout execution if button is used).

  if (systemLocked) {
    return; 
  }

  if (digitalRead(buttonPin) == HIGH) {
    if (!buttonActive) {
    buttonActive = true;
    buttonTimer = millis();//Stores the time when the button was pressed.,measure the duration of the press 
    buttonEverPressed = true; // Mark that button was pressed at least once
    }

  if ((millis() - buttonTimer > longPressTime) && !longPressActive) {
    longPressActive = true;//millis() - buttonTimer calculates how long the button has been held.
//!longPressActive:once a long press is detected, it won't repeatedly trigger while the button remains held.
    Serial.println("Long Pressed");
     //added client 
    bool hasOldClientCredentials = loadClientCredentials();
    startAccessPoint();  // Start AP if WiFi connection failed
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/html", formPage());
      });

    server.on("/submit", HTTP_POST, [](AsyncWebServerRequest *request) {
  if (request->hasParam("ssid", true) && request->hasParam("password", true)) {
    String newSSID = request->getParam("ssid", true)->value();
    String newPassword = request->getParam("password", true)->value();

    newSSID.trim();
    newPassword.trim();

  if (newSSID.length() == 0 || newPassword.length() == 0) {
    request->send(400, "text/plain", "SSID or Password cannot be empty!");
    return;
          }

  if (!hasSaved) {  // Save credentials only once
    clientSSID = newSSID;
    clientPassword = newPassword;

    Serial.println("New WiFi SSID: " + clientSSID);
    Serial.println("New WiFi PASSWORD: " + clientPassword);
    saveClientCredentials();
    hasSaved = true;
          }

    request->send(200, "text/html", successPage(clientSSID, clientPassword));
        } else {
    request->send(400, "text/plain", "Missing SSID or Password");
        }
      });

    server.begin();
   mp3_play(7010);//btn db chuka
    delay(3000);
 
    }
  } 
 else {
    if (buttonActive) {
      if (longPressActive) {
    longPressActive = false;
      } 
      else {
    Serial.println("Short Pressed");
   mp3_play(7010);//btn pressed
    delay(3000); 
       
    bool wasConnected = (WiFi.status() == WL_CONNECTED);
  if (connectToWiFi()) {
        if (!wasConnected) {
   mp3_play(7011);  // 🔊 WiFi connected (only if it was not already)
    delay(3000); 
  }
  
    sendLastOfflineDataToServer();  // Try sending offline data
  } else {
   mp3_play(7012);  // "WiFi connection failed"
    delay(4000);    
        
  }
      } 
    buttonActive = false;
     
}
}
  
  // Check for timeout only if NO button was ever pressed
  if ((millis() - startMillis > timeoutDuration) && !timeoutOccurred && !buttonEverPressed) {
    Serial.println("No button press detected. Proceeding to next step...");
    timeoutOccurred = true; // Ensure timeout message appears only once
    systemLocked = true; // Lock system after timeout
  }
    delay(10); // Small delay for debounce
}
