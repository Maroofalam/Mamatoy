
// void sendDataToServer(String mp3audios, int weeks) {
//   connectToWiFi();

//   if (mp3audios.length() == 0) {
//     mp3audios = "no audio";
//   }
//   mp3audios.replace("\"", "\\\"");

//   DateTime now = rtc.now();
//   String visitDateTime = String(now.year()) + "/" + String(now.month()) + "/" + String(now.day()) + " " +
//                          String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second());

//   String jsonPayload = "{";
//   jsonPayload += "\"toy_id\":\"" + childData[0] + "\",";
//   jsonPayload += "\"mother_id\":\"" + childData[1] + "\",";
//   jsonPayload += "\"token_id\":\"" + childData[2] + "\",";
//   jsonPayload += "\"visit_date_time\":\"" + visitDateTime + "\",";
//   jsonPayload += "\"week_number\":\"" + String(weeks) + "\",";
//   jsonPayload += "\"communication\":\"" + mp3audios + "\"";
//   jsonPayload += "}";

//   Serial.println("📦 Prepared JSON:");
//   Serial.println(jsonPayload);

//   if (WiFi.status() == WL_CONNECTED) {
//     dataSending(jsonPayload);
//   } else if (readClientSSID() != "" && readClientPassword() != "") {
//     Serial.print("Credentials: " + readClientSSID() + " " + readClientPassword());
//     WiFi.begin(readClientSSID(), readClientPassword());

//     int newStartTime = millis();
//     while (WiFi.status() != WL_CONNECTED && millis() - newStartTime < 30000) {
//       delay(500);
//       Serial.print(".");
//     }

//     if (WiFi.status() == WL_CONNECTED) {
//       dataSending(jsonPayload);
//     }
//   }

//   if (WiFi.status() != WL_CONNECTED) {
//     Serial.println("❌ WIFI NOT CONNECTED");
//     Serial.println("💾 Saving to offline...");
//     mp3_play(8809);  // 🔊 wifi not connected
//     delay(6000);
//     saveOffline(jsonPayload);
//   }
// }

// void dataSending(String jsonPayload) {
//   WiFiClient client;
//   HTTPClient http;

//   http.begin(client, "https://connect2mfi.org/deviotapps/iotinteractionformother");
//   http.addHeader("Content-Type", "application/json");

//   int code = http.POST(jsonPayload);

//   Serial.printf("📡 HTTP Response Code: %d\n", code);
//   String response = http.getString();
//   Serial.println("🖥️ Server Response:");
//   Serial.println(response);

//   if (code > 0 && code == 200) {
//     mp3_play(8814);  // 🔊 Data sent successfully
//     delay(5000);
//   } else {
//     Serial.printf("❌ Failed to send data. Error: %s\n", http.errorToString(code).c_str());
//     mp3_play(8817);  // 🔊 Error sending data
//     delay(5000);
//     saveOffline(jsonPayload);
//   }

//   http.end();
// }

// void saveOffline(String jsonString) {
//   File file = SPIFFS.open(offlineFilePath, "a");
//   if (file) {
//     file.println(jsonString);
//     file.close();
//     Serial.println("💾 Saved to offline file");
//     mp3_play(8818);  // 🔊 Data saved to SPIFFS
//     delay(4000);
//   } else {
//     Serial.println("❌ Failed to save offline");
//   }
// }

// void sendLastOfflineDataToServer() {
//   if (!SPIFFS.exists(offlineFilePath)) {
//     Serial.println("ℹ️ No offline data found.");
//     return;
//   }

//   File file = SPIFFS.open(offlineFilePath, "r");
//   if (!file) {
//     Serial.println("❌ Failed to open offline file.");
//     return;
//   }

//   std::vector<String> remaining;

//   while (file.available()) {
//     String line = file.readStringUntil('\n');
//     if (line.length() < 10) continue;

//     Serial.println("📤 Sending offline entry:");
//     Serial.println(line);

//     WiFiClient client;
//     HTTPClient http;
//     http.begin(client, "https://connect2mfi.org/deviotapps/iotinteractionformother");
//     http.addHeader("Content-Type", "application/json");

//     int code = http.POST(line);
//     if (code > 0 && code == 200) {
//       Serial.printf("✅ OFFLINE entry sent. HTTP %d\n", code);
//       Serial.println(http.getString());
//     } else {
//       Serial.printf("❌ Failed to send offline entry: %s\n", http.errorToString(code).c_str());
//       remaining.push_back(line);
//     }
//     http.end();
//     delay(1000);
//   }
//   file.close();

//   File outFile = SPIFFS.open(offlineFilePath, "w");
//   if (outFile) {
//     for (String& entry : remaining) {
//       outFile.println(entry);
//     }
//     outFile.close();
//     Serial.printf("🧹 Retained %d unsent entries.\n", remaining.size());

//     if (remaining.size() == 0) {
//       mp3_play(8812);  // 🔊 All offline data sent
//       delay(3000);
//     }
//   } else {
//     Serial.println("❌ Could not rewrite offline file.");
//   }
// }





void sendDataToServer(String mp3audios, int weeks) {
  connectToWiFi();

  if (mp3audios.length() == 0) {
    mp3audios = "no audio";
  }
  mp3audios.replace("\"", "\\\"");

  DateTime now = rtc.now();
  String visitDateTime = String(now.year()) + "/" + String(now.month()) + "/" + String(now.day()) + " " +
                         String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second());
  String uuid = generateUUID();       
  String jsonPayload = "{";
  jsonPayload += "\"toy_id\":\"" + childData[0] + "\",";
  jsonPayload += "\"mother_id\":\"" + childData[1] + "\",";
  jsonPayload += "\"token_id\":\"" + childData[2] + "\",";
  jsonPayload += "\"visit_date_time\":\"" + visitDateTime + "\",";
  jsonPayload += "\"week_number\":\"" + String(weeks) + "\",";
  jsonPayload += "\"communication\":\"" + mp3audios + "\",";
  jsonPayload += "\"rec_uid\":\"" + uuid + "\"";
  jsonPayload += "}";
  Serial.println("Prepared JSON:");
  Serial.println(jsonPayload);
  bool wifiConnected = false;

  if (WiFi.status() == WL_CONNECTED) {
    dataSending(jsonPayload);
    wifiConnected = true;
  } else if (readClientSSID() != "" && readClientPassword() != "") {
    Serial.print("Credentials: " + readClientSSID() + " " + readClientPassword());
  
     mp3_play(7013);
     delay(6000);
   
     WiFi.begin(readClientSSID(), readClientPassword());

    int newStartTime = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - newStartTime < 7000) {
      delay(500);
      Serial.print(".");
    }

    if (WiFi.status() == WL_CONNECTED) {
      mp3_play(7011);  // 🔊 WiFi connected
      delay(3000);
      
      dataSending(jsonPayload);
      wifiConnected = true;
    }
  }

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("❌ WIFI NOT CONNECTED");
    Serial.println("💾 Saving to offline...");
    mp3_play(7012);  // 🔊 wifi not connected
    delay(4000);
    saveOffline(jsonPayload);
  }
  if (!shortPressDetected && wifiConnected) {
    Serial.println("📤 Sending previously saved offline data...");
    sendLastOfflineDataToServer();
  }

}

void dataSending(String jsonPayload) {
  WiFiClientSecure client;
  client.setInsecure();  
  HTTPClient http;
  http.begin(client,"https://connect2mfi.org/deviotapps/iotinteractionformother");
  http.addHeader("Content-Type", "application/json");

  int code = http.POST(jsonPayload);

  Serial.printf(" HTTP Response Code: %d\n", code);
  String response = http.getString();
  Serial.println("🖥️ Server Response:");
  Serial.println(response);

  if (code > 0 && code == 200) {
    mp3_play(7019);  // 🔊 Data sent successfully
    delay(5000);
   
  } else {
    Serial.printf("❌ Failed to send data. Error: %s\n", http.errorToString(code).c_str());
    mp3_play(7020);  // 🔊 Error sending data
    delay(4000);
   
    saveOffline(jsonPayload);
  }

  http.end();
}
 

void saveOffline(String jsonString) {
  File file = SPIFFS.open(offlineFilePath, "a");
  if (file) {
    file.println(jsonString);
    file.close();
    Serial.println("💾 Saved to offline file");
    mp3_play(7021);  // 🔊 Data saved to SPIFFS
    delay(5000);
   
  } else {
    Serial.println("❌ Failed to save offline");
  }
}

void sendLastOfflineDataToServer() {
  if (!SPIFFS.exists(offlineFilePath)) {
    Serial.println("ℹ️ No offline data found.");
    return;
  }

  File file = SPIFFS.open(offlineFilePath, "r");
  if (!file) {
    Serial.println("❌ Failed to open offline file.");
    return;
  }

  std::vector<String> remaining;

  while (file.available()) {
    String line = file.readStringUntil('\n');
    if (line.length() < 10) continue;

    Serial.println("📤 Sending offline entry:");
    Serial.println(line);
   
    WiFiClientSecure client;
    client.setInsecure();  // Use only if you cannot verify server cert

    HTTPClient http;
    http.begin(client, "https://connect2mfi.org/deviotapps/iotinteractionformother");
    http.addHeader("Content-Type", "application/json");

    int code = http.POST(line);
    if (code > 0 && code == 200) {
      Serial.printf("✅ OFFLINE entry sent. HTTP %d\n", code);
      Serial.println(http.getString());
      mp3_play(7019);  // 🔊 Only play AFTER response
      delay(5000);
     
    } else {
      Serial.printf("❌ Failed to send offline entry: %s\n", http.errorToString(code).c_str());
      remaining.push_back(line);
      delay(300);
      mp3_play(7020);  // 🔊 Failed to send to server
      delay(4000);
    }
    http.end();
    delay(1000);
  }
  file.close();

  File outFile = SPIFFS.open(offlineFilePath, "w");
  if (outFile) {
    for (String& entry : remaining) {
      outFile.println(entry);
    }
    outFile.close();
    Serial.printf("🧹 Retained %d unsent entries.\n", remaining.size());

    if (remaining.size() == 0) {
      mp3_play(7022);  // 🔊 All offline data sent
      delay(5000);
    }
  } else {
    Serial.println("❌ Could not rewrite offline file.");
  }
}
