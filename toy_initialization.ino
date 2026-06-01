// ===================== Fetch Toy ID from Server API =====================
String getToyIDFromServer(String manufactureID) {
    if (WiFi.status() == WL_CONNECTED) {
        WiFiClient client;//Initializes WiFiClient and HTTPClient to communicate with the server.
        HTTPClient http;
        http.begin(client, serverURL);//start a connection with the specified server URL.
        http.addHeader("Content-Type", "application/json");// to specify that the request body will be in JSON format.

        // API Request with Manufacture ID
        StaticJsonDocument<256> doc;//used to store and manipulate JSON data for serialization (sending) or deserialization (receiving and parsing).
        doc["toyid"] = manufactureID;// assigns the value of manufactureID to the "toyid" key in the doc JSON object.
        String requestData;//Converts the JSON document (doc) into a string format (requestData) 
        serializeJson(doc, requestData);//serializes a JSON object into a human-readable string.

        int httpCode = http.POST(requestData);
//Yeh line ESP8266 ka HTTPClient library ka function POST() use karti hai, jo ek HTTP POST request server ko bhejta hai.
//Iska response status code (int) me milta hai, jo httpCode variable me store hota hai.
        if (httpCode > 0) {//ESP8266 successfully received a response from the server.
            String response = http.getString();//http.getString() extracts the response body (the actual data sent by the server) 
            Serial.println("Server Response: " + response);

            StaticJsonDocument<256> doc;
            DeserializationError error = deserializeJson(doc, response);
            if (error) {
                Serial.println("JSON Parsing Failed!");
                return "0";
            }

            String toyID = doc["toy_id"] | "0";//doc["toy_id"] extracts the value of "toy_id" from the JSON.
            return toyID;
        } else {
            Serial.println("Failed to get Toy ID from server.");
            return "0";
        }
    } else {
        Serial.println("WiFi Not Connected!");
        return "0";
    }
}

// Play Toy ID using DFPlayer Mini
// void playToyID(String toyID) {
//     if (toyID == "0" || toyID.isEmpty()) {
//         Serial.println("Invalid or empty Toy ID. Cannot play.");
//         return;
//     }

//     Serial.println("Playing Toy ID: " + toyID);
  
// }

// // Read Toy ID from SPIFFS
// String readToyID() {
//     File file = SPIFFS.open("/toyID.txt", "r");
//     if (!file) {
//         Serial.println("Toy ID file not found.");
//         return "0";
//     }
//     String data = file.readString();//Reads the entire file content into the data string.
//     file.close();
//     StaticJsonDocument<256> doc;
//     deserializeJson(doc, data);
//     return doc["toy_id"] | "0";
// }

// // Save Toy ID to SPIFFS
// void saveToyID(String toyID) {
//     File file = SPIFFS.open("/toyID.txt", "w");
//     if (!file) {
//         Serial.println("Failed to save Toy ID.");
//         return;
//     }
//     StaticJsonDocument<256> doc;
//     doc["toy_id"] = toyID;
//     serializeJson(doc, file);
//       file.println(toyID);
//     file.close();
//     Serial.println("Toy ID saved: " + toyID);
// }
  

String readToyID()
{
  String findToyID;
  using namespace std;
  SPIFFS.begin();
  //
  File findToyIDFile = SPIFFS.open("/toyID.txt", "r");
  vector<String> v;
  while (findToyIDFile.available()) {
    v.push_back(findToyIDFile.readStringUntil('\n'));
  }

  for (String s : v) {

    findToyID += s;
  }
  ////Serial.println();
  //  //Serial.print("Toy ID Read from File : ");////Serial.println(findToyID);
  //  //Serial.print("File size: ");////Serial.println(findToyIDFile.size());
  boolean sendStatus = false;
  StaticJsonDocument <256> docs;
  deserializeJson(docs, findToyID);


  String status = docs["status"];
  String toy_id = docs["toy_id"];


  //  //Serial.print("status ="); ////Serial.println(status);
  //  //Serial.print("toy_id ="); ////Serial.println(toy_id);

  ToyID = toy_id;
  //Serial.print(F("ToyID =")); ////Serial.println(ToyID);
  findToyIDFile.close();
  if (ToyID != "" && toy_id != "null")
  {
    return toy_id;
  }
  else
  {
    return "0";
  }
}

//String toy_Initialization()
//{
//  String toyID;
//  String payload;
//  boolean wifi_conn = wiFi_Connection();
//
//
//  if (WiFi.status() == WL_CONNECTED) { //Check the current connection status
//
//    WiFiClient client;
//    HTTPClient http;
//    //Serial.print("[HTTP] begin...\n");
//    http.begin(client, "http://connect2mfi.org/IOTapps/index.php/gettoyid");
//    http.addHeader("Content-Type", "application/json");
//    //Serial.print("[HTTP] GET...\n");
//
//    int httpCode = http.GET();
//    if (httpCode > 0) {
//
//      if (httpCode == 200) {
//        //Serial.printf("Data Posted Successfully...");
//
//      }
//      else if (httpCode == 500) {
//        //Serial.printf("ToyId: %d, Already Posted. Please Try With Different ToyId");
//      }
//      else {
//        //Serial.printf("[HTTP] GET... code: %d\n", httpCode);
//      }
//
//      if (httpCode == HTTP_CODE_OK) {
//        const String& payload = http.getString();
//        ////Serial.println("received payload:\n<<");
//        ////Serial.println(payload);
//        ////Serial.println(">>");
//        toyID = payload;
//
//      }
//    }
//    else {
//      //Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
//    }
//    http.end();
//  }
//  else
//  {
//    ////Serial.println("WiFi not available ");
//  }
//
//  delay(100);
//
//
//  return toyID;
//}

//Get Toy ID By using Manufacture ID
//***********************************

String getToyID(String manufactureID)
{


  boolean wifi_conn =  connectToWiFi() ;
  String toyID;

  String data;
  StaticJsonDocument <256> docs;

  docs["toyid"] = manufactureID;


  serializeJsonPretty(docs, data);

  // data = "[" + data + "]";
  ////Serial.println(data);
  if ((WiFi.status() == WL_CONNECTED)) {

    WiFiClient client;
    HTTPClient http;

    //Serial.print(F("[HTTP] begin...\n"));

    // configure traged server and url
    
    http.begin(client, "http://connect2mfi.org/deviotapps/index.php/toyinitilization");
    http.addHeader("Content-Type", "application/json");

    //Serial.print(F("[HTTP] POST...\n"));



    int httpCode = http.POST(data);

    if (httpCode > 0) {


      if (httpCode == 200) {
        ////Serial.printf("Data Insert Successfully...");


      }
      else if (httpCode == 500) {
        //Serial.printf("Error from server side : "+httpCode);
      }
      else {
        //Serial.printf("[HTTP] POST... code: %d\n", httpCode);
      }

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        const String& payload = http.getString();
        ////Serial.println(F("received payload:\n<<"));
        ////Serial.println(payload);
        ////Serial.println(F(">>"));
        toyID = payload;
        StaticJsonDocument <256> docs;
        deserializeJson(docs, toyID);
        int status = docs["status"];
        String toy_id = docs["toy_id"];
        //Serial.print(F("Status Received from server : ")); ////Serial.println(status);
        //Serial.print(F("Toy ID received from server =")); ////Serial.println(toy_id);

        if(status == 1)
        {
          ////Serial.println(F("Data Insert Successfully "));
          //Serial.print(F("ID assigned to this toy is : "));////Serial.println(toy_id);
        }
        else if(status == 2)
        {
          ////Serial.println(F("This Manufacture ID Toy already assigned this ID : "));////Serial.println(toy_id);
        }
        else if(status == 3)
        {
          ////Serial.println(F("Toy ID cannot be null "));
        }
        else if(status == 0)
        {
          ////Serial.println(F("Failed "));
        }

      }
    } else {
      //Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }
  else
  {
    ////Serial.println(F("WiFi not available "));
  }

  return toyID;
}


boolean saveToyID(String receivedID)
{
  if (SPIFFS.begin())
  {
    ////Serial.println(F("SPIFFS got Initialized successfully"));
  }
  else
  {
    ////Serial.println(F("SPIFFS Initialization is failed"));
  }
  const char* toyFile = "/toyID.txt";
  File  fileID = SPIFFS.open(toyFile, "w");
  if (!fileID)
  {
    ////Serial.println(F("file open failed"));
    return false;
  }
  else
  {
    ////Serial.println(F("====== Writing toy ID to SPIFFS file ========="));
    fileID.print(receivedID);
    fileID.close();
    return true;
  }
}


