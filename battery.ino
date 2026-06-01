// float mapfloat(float x, float in_min, float in_max, float out_min, float out_max) {
//     return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
// }

// boolean bat_percent() {
//     int batteryValue = analogRead(batteryPin);  // Read the analog value from the battery pin
//     float batteryVoltage = (batteryValue * 5.0) / 1024.0;

//   // Get mapped percentage and constrain it to 0-100
//     int batteryPercentage = (int)mapfloat(batteryVoltage, 3.3, 4.2, 0, 100);
//     batteryPercentage = constrain(batteryPercentage, 0, 100); 

//     Serial.print("Battery Voltage: ");
//     Serial.print(batteryVoltage, 2);
//     Serial.print("V, ");
//     Serial.print("Battery Percentage: ");
//     Serial.print(batteryPercentage);
//     Serial.println("%");

//   if (batteryPercentage > 75) {
//     Serial.println("Battery is over 75%. Playing audio for 75%+.");
//    mp3_play(9919); 
//     delay(3500);
     
//   }
//    else if (batteryPercentage > 50 && batteryPercentage <= 75) {
//     Serial.println("Battery is 50–75%. Playing audio for 50%+.");
//    mp3_play(9920); 
//     delay(3000); 
//   }
//    else if (batteryPercentage > 25 && batteryPercentage <= 50) {
//     Serial.println("Battery is low. Playing audio for 25%+.");
//    mp3_play(9921);  
//     delay(2500); 
  
//   } else {
//     Serial.println("Battery is very low. Playing very low battery warning.");
//    mp3_play(9922);
//     delay(2500);
//   }
//     return false;
// }
//     delay(1000);
//     return true;
// }

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

boolean bat_percent() {
  int batteryValue = analogRead(batteryPin);  // Read the analog value from the battery pin
  float batteryVoltage = (batteryValue * 5.0) / 1024.0;

  // Get mapped percentage and constrain it to 0-100
  int batteryPercentage = (int)mapfloat(batteryVoltage, 3.3, 4.2, 0, 100);
  batteryPercentage = constrain(batteryPercentage, 0, 100); 

  Serial.print("Battery Voltage: ");
  Serial.print(batteryVoltage, 2);
  Serial.print("V, ");
  Serial.print("Battery Percentage: ");
  Serial.print(batteryPercentage);
  Serial.println("%");

  if (batteryPercentage > 75) {
    Serial.println("Battery is over 75%. Playing audio for 75%+.");
   mp3_play(7004); 
    delay(5000);
  } else if (batteryPercentage > 50 && batteryPercentage <= 75) {
    Serial.println("Battery is 50–75%. Playing audio for 50%+.");
   mp3_play(7005); 
    delay(4000);
   
  } else if (batteryPercentage > 25 && batteryPercentage <= 50) {
    Serial.println("Battery is low. Playing audio for 25%+.");
   mp3_play(7006);  
    delay(3000);

  } else {
    Serial.println("Battery is very low. Playing very low battery warning.");
   mp3_play(7007);
    delay(3000);
    
    return false;
  }

  delay(1000);
  return true;
}
