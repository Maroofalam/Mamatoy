// Function to Start Access Point (AP Mode)
void startAccessPoint() {
  Serial.println("Starting Access Point Mode...");
  WiFi.softAP(ap_ssid.c_str(), ap_password.c_str());
  Serial.print("AP IP Address: ");
  Serial.println(WiFi.softAPIP());//esp8266 ip
}


// HTML Form for WiFi Setup
String formPage() {
  String htmlResponse = "<html><head>";
  htmlResponse += "<style>";
  htmlResponse += "body { display: flex; justify-content: center; align-items: center; height: 100vh; margin: 0; font-size: 40px; }";  // Flexbox to center and larger font
  htmlResponse += "form { text-align: center; width: 100%; max-width: 300px; font-size: 36px; }";  // Larger font for the form
  htmlResponse += "h1 { font-size: 42px; }";  // Larger font for heading "Enter Wi-Fi Credentials"
  htmlResponse += "input[type='text'], input[type='password'] { font-size: 40px; padding: 8px; width: 100%; margin-bottom: 20px; }";  // Increase input field font size
  htmlResponse += "input[type='submit'] { font-size: 40px; padding: 10px 20px; margin-top: 10px; }";  // Increase submit button size
  htmlResponse += "</style></head><body>";
  htmlResponse += "<div>";
  htmlResponse += "<h1>Enter Wi-Fi Credentials</h1>";
  htmlResponse += "<form action='/submit' method='POST'>";
  htmlResponse += "SSID: <input type='text' name='ssid' value=''><br><br>";  // Empty value for SSID with increased font size
  htmlResponse += "Password: <input type='password' name='password' value=''><br><br>";  // Empty value for Password with increased font size
  htmlResponse += "<input type='submit' value='Submit'>";  // Submit button with larger font
  htmlResponse += "</form>";
  htmlResponse += "</div></body></html>";
  return htmlResponse;
}

String successPage(String newSSID, String newPassword) {
  String htmlResponse = "<html><head>";
  htmlResponse += "<style>";
  htmlResponse += "body { display: flex; justify-content: center; align-items: center; height: 100vh; margin: 0; font-size: 40px; }";  // Flexbox to center and larger font
  htmlResponse += "div { text-align: center; width: 100%; max-width: 300px; }";  // Limit content width
  htmlResponse += "h2 { font-size: 48px; color: green; }";  // Larger font and green color for success message
  htmlResponse += "p { font-size: 45px; }";  // Larger font for SSID and Password display
  htmlResponse += "</style></head><body>";
  htmlResponse += "<div>";
  htmlResponse += "<h2>Data Submitted Successfully!</h2>";  // Success message with increased font size and green color
  htmlResponse += "<p>SSID: " + newSSID + "</p>";
  htmlResponse += "<p>Password: " + newPassword + "</p>";  // Show password for confirmation with larger font
  htmlResponse += "</div></body></html>";
  return htmlResponse;
}