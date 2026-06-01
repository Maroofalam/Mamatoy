
void handleRFID() {
  if (!mfrc522.PICC_IsNewCardPresent()) {
    if (firstScan) {
      Serial.println("No RFID card detected.");
      firstScan = false;
    }
    delay(1000);
    return;
  }

  if (!mfrc522.PICC_ReadCardSerial()) {
    Serial.println("Error reading RFID card.");
    delay(1000);
    return;
  }

  firstScan = false;
  cardUID = getCardUID();
  Serial.println("\nRFID card detected.");
  Serial.print("Card UID: ");
  Serial.println(cardUID);

  String rfidData = readRFIDDataTillDOB();
  Serial.print("RFID Data till DOB: ");
  Serial.println(rfidData);

  totalFields = parseRFIDDataTillDOB(rfidData, childData);
  if (totalFields == 5) {
    printChildData();          

  } else {
    Serial.println("Error: RFID data incomplete or in wrong format");
    Serial.print("🔍 Raw string parsed: ");
    Serial.println(rfidData);      

  }

  newCardScanned = true;
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
  delay(2000);
}

String getCardUID() {
  
    String uidString = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] < 0x10) uidString += "0";
    uidString += String(mfrc522.uid.uidByte[i], HEX);
    if (i < mfrc522.uid.size - 1) uidString += ":";
  }
    uidString.toUpperCase();
    return uidString;
}

String readRFIDDataTillDOB() {
    String tagData = "";
    byte buffer[18];
    byte bufferSize = sizeof(buffer);
    bool dobReached = false;

    for (byte block = 1; block < 31; block++) {
  if (block % 4 == 3) continue; // Skip sector trailers

    MFRC522::StatusCode status = mfrc522.PCD_Authenticate(
    MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) continue;

    status = mfrc522.MIFARE_Read(block, buffer, &bufferSize);
  if (status != MFRC522::STATUS_OK) continue;

    for (uint8_t i = 0; i < 16; i++) {
    char c = buffer[i];
  if (c >= 32 && c <= 126) {
    tagData += c;
  if (tagData.length() >= 10) {
    String lastTen = tagData.substring(tagData.length() - 10);
  if (lastTen.charAt(2) == '/' && lastTen.charAt(5) == '/') {
  //edit
    tagData += "&"; //edit
    dobReached = true;
     break;//edit
          }
        }
      }
    }
    if (dobReached) break;
  }
  tagData.replace("CH~", "");
  tagData.replace("ch~", "");
  
    return tagData.isEmpty() ? "No Data Found" : tagData;
}

int parseRFIDDataTillDOB(String data, String childData[]) {
    int fieldIndex = 0;
  while (data.length() > 0 && fieldIndex < 5) {
    int delimiterIndex = data.indexOf('_');
    String segment;

  if (delimiterIndex == -1) {
    segment = data;
    data = "";
    } else {
    segment = data.substring(0, delimiterIndex);
    data = data.substring(delimiterIndex + 1);
    }

  if (fieldIndex != 4 && segment.endsWith("&")) {
    segment.remove(segment.length() - 1);
    }
 if (fieldIndex == 1 && (segment.startsWith("CH~") || segment.startsWith("ch~"))) {
      segment = segment.substring(3);
    }
    childData[fieldIndex] = segment;
    fieldIndex++;
  }
    return fieldIndex;
}

void printChildData() {
    Serial.println("\n===== Child Data Array (Till DOB Only) =====");
   for (int i = 0; i < totalFields; i++) {
  if (childData[i].length() > 0) {
    Serial.print("ChildData[");
    Serial.print(i);
    Serial.print("]: ");
    Serial.println(childData[i]);
    }
  }
    Serial.println("===========================================\n");
}



// void handleRFID() {
//   // Case 1: No card present
//   if (!mfrc522.PICC_IsNewCardPresent()) {
//     if (waitingForRemoval) {
//       waitingForRemoval = false;
//       Serial.println("📤 Card removed. Ready for next scan.");
//     }
//     delay(200);
//     return;
//   }

//   // Case 2: Card is present, but already scanned
//   if (waitingForRemoval) {
//    // delay(200);
//     return;
//   }

//   // Case 3: New card present
//   if (!mfrc522.PICC_ReadCardSerial()) {
//     Serial.println("❌ Error reading card serial.");
//     delay(200);
//     return;
//   }

//   // ==== Process Card ====
//   cardUID = getCardUID();
//   Serial.println("\n✅ RFID card detected.");
//   Serial.print("🔐 Card UID: ");
//   Serial.println(cardUID);

//   String rfidData = readRFIDDataTillDOB();
//   Serial.print("📄 RFID Data till DOB: ");
//   Serial.println(rfidData);

//   totalFields = parseRFIDDataTillDOB(rfidData, childData);
//   if (totalFields == 5) {
//     printChildData();
//   } else {
//     Serial.println("⚠️ Error: RFID data incomplete or wrong format.");
//     Serial.print("🔍 Raw parsed: ");
//     Serial.println(rfidData);
//   }

//   // Halt card and mark that we are waiting for removal
//   mfrc522.PICC_HaltA();
//   mfrc522.PCD_StopCrypto1();
//   waitingForRemoval = true;
// }


// void handleRFID() {
//   if (!mfrc522.PICC_IsNewCardPresent()) {
//     if (firstScan) {
//       Serial.println("No RFID card detected.");
//       firstScan = false;
//     }
//     delay(500);
//     return;
//   }

//   if (!mfrc522.PICC_ReadCardSerial()) {
//     Serial.println("Error reading RFID card.");
//     delay(500);
//     return;
//   }

//   firstScan = false;
//   cardUID = getCardUID();
//   Serial.println("\nRFID card detected.");
//   Serial.print("Card UID: ");
//   Serial.println(cardUID);

//   String rfidData = readRFIDDataTillDOB();
//   Serial.print("RFID Data till DOB: ");
//   Serial.println(rfidData);

//   totalFields = parseRFIDDataTillDOB(rfidData, childData);
//   if (totalFields == 5) {
//     printChildData();
//   } else {
//     Serial.println("Error: RFID data incomplete or in wrong format");
//     Serial.print("🔍 Raw string parsed: ");
//     Serial.println(rfidData);
//   }

//   newCardScanned = true;
//   mfrc522.PICC_HaltA();
//   mfrc522.PCD_StopCrypto1();
//   delay(1000);
// }

// void handleRFID() {
//   if (!mfrc522.PICC_IsNewCardPresent()) {
//     if (waitingForRemoval) {
//       waitingForRemoval = false;
//       Serial.println(" Card removed. Ready for next scan.");
//     }
//     delay(200);
//     return;
//   }

//   if (waitingForRemoval) return;

//   if (!mfrc522.PICC_ReadCardSerial()) {
//     Serial.println("❌ Error reading card serial.");
//     delay(200);
//     return;
//   }

//   // Process new card
//   cardUID = getCardUID();
//   Serial.println("\n✅ RFID card detected.");
//   Serial.print("🔐 Card UID: ");
//   Serial.println(cardUID);

//   String rfidData = readRFIDDataTillDOB();
//   Serial.print("📄 RFID Data till DOB: ");
//   Serial.println(rfidData);

//   totalFields = parseRFIDDataTillDOB(rfidData, childData);
//   if (totalFields == 5) {
//     printChildData();
//   } else {
//     Serial.println("⚠️ Error: RFID data incomplete or wrong format.");
//     Serial.print("🔍 Raw parsed: ");
//     Serial.println(rfidData);
//   }

//   // Mark that card was scanned
//   newCardScanned = true;
//   waitingForRemoval = true;

//   mfrc522.PICC_HaltA();
//   mfrc522.PCD_StopCrypto1();
// // }

// void handleRFID() {
//   // No new card
//   if (!mfrc522.PICC_IsNewCardPresent()) {
//     if (waitingForRemoval) {
//       waitingForRemoval = false;
//       Serial.println("🔄 Card removed. Ready for next scan.");
//     }
//     return;
//   }

//   // Prevent reading same card again
//   if (waitingForRemoval) return;

//   // Failed to read serial
//   if (!mfrc522.PICC_ReadCardSerial()) {
//     Serial.println("❌ Error reading card serial.");
//     return;
//   }

//   // Get UID
//   cardUID = getCardUID();
//   Serial.println("\n✅ RFID card detected.");
//   Serial.print("🔐 UID: ");
//   Serial.println(cardUID);
  
//   // Read card data till DOB
//   String rfidData = readRFIDDataTillDOB();
//   Serial.print("📄 Raw Data till DOB: ");
//   Serial.println(rfidData);

//   totalFields = parseRFIDDataTillDOB(rfidData, childData);
//   Serial.print("🧮 Parsed fields: ");
//   Serial.println(totalFields);

//   if (totalFields == 5) {
//     printChildData();         // ✅ You can process child data here
//     newCardScanned = true;    // 🔑 VERY important — tells loop that scan completed
//   } else {
//     Serial.println("⚠️ Invalid or incomplete RFID data.");
//     newCardScanned = false;
//     player.playFromMP3Folder(8826); // 🔊 card data is wrong
//     delay(3000);

//   }

//   // Halt communication
//   mfrc522.PICC_HaltA();
//   mfrc522.PCD_StopCrypto1();

//   // Block until card is removed
//   waitingForRemoval = true;
// }
// void handleRFID() {
//   static unsigned long lastCheck = 0;
//   if (millis() - lastCheck < 200) return;  // Limit scan checks to 5 per second
//   lastCheck = millis();

//   // Check card presence
//   if (!mfrc522.PICC_IsNewCardPresent()) {
//     if (waitingForRemoval) {
//       waitingForRemoval = false;
//       Serial.println("🔄 Card removed. Ready for next scan.");
//     }
//     return;
//   }

//   if (waitingForRemoval) return;

//   // Try reading UID up to 5 times
//   bool success = false;
//   for (int i = 0; i < 20; i++) {
//     if (mfrc522.PICC_ReadCardSerial()) {
//       success = true;
//       break;
//     }
//     delay(20);  // Retry delay
//   }

//   if (!success) {
//     Serial.println("❌ Failed to read card after retries.");
//     mfrc522.PCD_StopCrypto1();  // Clean-up if partial read
//     return;
//   }

//   cardUID = getCardUID();
//   Serial.println("\n✅ RFID card detected.");
//   Serial.print("🔐 UID: ");
//   Serial.println(cardUID);

//   // Read and parse card data
//   String rfidData = readRFIDDataTillDOB();
//   Serial.print("📄 Raw Data till DOB: ");
//   Serial.println(rfidData);

//   totalFields = parseRFIDDataTillDOB(rfidData, childData);
//   Serial.print("🧮 Parsed fields: ");
//   Serial.println(totalFields);

//   if (totalFields == 5) {
//     printChildData();
//     newCardScanned = true;
//   } else {
//     Serial.println("⚠️ Invalid or incomplete RFID data.");
//     newCardScanned = false;
//     player.playFromMP3Folder(8826);  // Play invalid card audio
//     delay(2000);
//   }

//   // Cleanup and mark card as read
//   mfrc522.PICC_HaltA();
//   mfrc522.PCD_StopCrypto1();
//   waitingForRemoval = true;   

// }


// // ========================= Read UID =========================
// String getCardUID() {
//   String uidString = "";
//   for (byte i = 0; i < mfrc522.uid.size; i++) {
//     if (mfrc522.uid.uidByte[i] < 0x10) uidString += "0";
//     uidString += String(mfrc522.uid.uidByte[i], HEX);
//     if (i < mfrc522.uid.size - 1) uidString += ":";
//   }
//   uidString.toUpperCase();
//   return uidString;
// }

// String readRFIDDataTillDOB() {
//   String tagData = "";
//   byte buffer[18];
//   byte bufferSize = sizeof(buffer);
//   bool dobReached = false;

//   for (byte block = 1; block < 31; block++) {
//     if (block % 4 == 3) continue;

//     MFRC522::StatusCode status = mfrc522.PCD_Authenticate(
//       MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(mfrc522.uid));
//     if (status != MFRC522::STATUS_OK) continue;

//     status = mfrc522.MIFARE_Read(block, buffer, &bufferSize);
//     if (status != MFRC522::STATUS_OK) continue;

//     for (uint8_t i = 0; i < 16; i++) {
//       char c = buffer[i];
//       if (c >= 32 && c <= 126) {
//         tagData += c;
//         if (tagData.length() >= 10) {
//           String lastTen = tagData.substring(tagData.length() - 10);
//           if (lastTen.charAt(2) == '/' && lastTen.charAt(5) == '/') {
//             tagData += "&";
//             dobReached = true;
//             break;
//           }
//         }
//       }
//     }

//     if (dobReached) break;
//   }

//   tagData.replace("CH~", "");
//   tagData.replace("ch~", "");
//   return tagData.isEmpty() ? "No Data Found" : tagData;
// }

// int parseRFIDDataTillDOB(String data, String childData[]) {
//   int fieldIndex = 0;
//   while (data.length() > 0 && fieldIndex < 5) {
//     int delimiterIndex = data.indexOf('_');
//     String segment;

//     if (delimiterIndex == -1) {
//       segment = data;
//       data = "";
//     } else {
//       segment = data.substring(0, delimiterIndex);
//       data = data.substring(delimiterIndex + 1);
//     }

//     if (fieldIndex != 4 && segment.endsWith("&")) {
//       segment.remove(segment.length() - 1);
//     }

//     if (fieldIndex == 1 && (segment.startsWith("CH~") || segment.startsWith("ch~"))) {
//       segment = segment.substring(3);
//     }

//     childData[fieldIndex] = segment;
//     fieldIndex++;
//   }
//   return fieldIndex;
// }

// // ========================= Print Data =========================
// void printChildData() {
//   Serial.println("\n===== Child Data Array (Till DOB Only) =====");
//   for (int i = 0; i < totalFields; i++) {
//     Serial.print("ChildData[");
//     Serial.print(i);
//     Serial.print("]: ");
//     Serial.println(childData[i]);
//   }
//   Serial.println("===========================================\n");
// }
