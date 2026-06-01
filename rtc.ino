void ageCal(){
 if (rfidReady) {
    handleRFID();
    if (newCardScanned) {
      newCardScanned = false;
      mp3_play(7015); // 🔊 card detected
      delay(4000); 
     
      cardDetected = true;
      if (totalFields < 5) {
        mp3_play(7014); // 🔊 card data is wrong
        delay(3000);
        return;
      }
      //  Check if card has no valid data
      if (childData[0] == "No Data Found") {
        mp3_play(7014); // 🔊 card data is wrong
        delay(3000); 
        
        return;
      }

      //  Check DOB field
      String dobString = childData[4]; // Format: "dd/mm/yyyy"
      dobString.replace("&", ""); 
      int d1 = dobString.indexOf('/');
      int d2 = dobString.indexOf('/', d1 + 1);

      if (dobString.length() < 8 || d1 == -1 || d2 == -1) {
        mp3_play(7014); // 🔊 card data is wrong
        delay(3000); 
        
      }

      int birthDay = dobString.substring(0, d1).toInt();
      int birthMonth = dobString.substring(d1 + 1, d2).toInt();
      int birthYear = dobString.substring(d2 + 1).toInt();

      if (birthDay <= 0 || birthDay > 31 ||
          birthMonth <= 0 || birthMonth > 12 ||
          birthYear < 2000 || birthYear > 2030) {
        mp3_play(7014); // 🔊 card data is wrong
        delay(3000); 
        
        return;
      }

      // ✅ All good, proceed
      DateTime now = rtc.now();
      DateTime dob(birthYear, birthMonth, birthDay);

      TimeSpan age = now - dob;
      int totalDays = age.days();

      if (totalDays < 0) {
        mp3_play(7014); // 🔊 card data is wrong
        delay(3000); 
        
        return;
      }

      int weeks = totalDays / 7;
      int days = totalDays % 7;

      Serial.print("DOB from card: ");
      Serial.println(dobString);

      Serial.print("Today: ");
      Serial.print(now.day()); Serial.print("/");
      Serial.print(now.month()); Serial.print("/");
      Serial.println(now.year());

      Serial.print(" Correct Age: ");
      Serial.print(weeks);
      Serial.print(" weeks, ");
      Serial.print(days); 
      Serial.println(" days");

      // 🎉 Play congratulatory message first
      mp3_play(7016);  // "Mubarak ho..."
      delay(4000); 
 
      if (weeks > 0) {
        mp3_play(weeks); delay(1500); 
        mp3_play(7017);  // "weeks"
        delay(1500); 
      
  }
      

      if (days > 0) {
        mp3_play(days); delay(1500); 
        mp3_play(7018); // "days"
        delay(1500); 
       
  }
      
     
     // int currentWeek = (days > 0) ? (weeks + 1) : weeks;
      int currentWeek = (weeks == 0 && days > 0) ? 1 : (days > 0 ? weeks + 1 : weeks);
      immunization(currentWeek);
    }
  }
}


// void ageCal() {
//   if (rfidReady) {
//     handleRFID();

//     if (newCardScanned) {
//       newCardScanned = false;
//       mp3_play(8819); // 🔊 card detected
//       delay(3000); 
//       cardDetected = true;

//       // ❌ Check if RFID data is incomplete
//       if (totalFields < 5) {
//         Serial.println(" Skipping age calculation.");
//         mp3_play(8826); // 🔊 card data is wrong
//         delay(3000);
//         return;
//       }

//       // Check if card has no valid data
//       if (childData[0] == "No Data Found") {
//         mp3_play(8826); // 🔊 card data is wrong
//         delay(3000); 
//         return;
//       }

//       // ✅ Check DOB field
//       String dobString = childData[4]; // Format: "dd/mm/yyyy"
//       dobString.replace("&", ""); 
//       int d1 = dobString.indexOf('/');
//       int d2 = dobString.indexOf('/', d1 + 1);

//       if (dobString.length() < 8 || d1 == -1 || d2 == -1) {
//         mp3_play(8826); // 🔊 card data is wrong
//         delay(3000); 
//         return;
//       }

//       int birthDay = dobString.substring(0, d1).toInt();
//       int birthMonth = dobString.substring(d1 + 1, d2).toInt();
//       int birthYear = dobString.substring(d2 + 1).toInt();

//       if (birthDay <= 0 || birthDay > 31 ||
//           birthMonth <= 0 || birthMonth > 12 ||
//           birthYear < 2000 || birthYear > 2030) {
//         mp3_play(8826); // 🔊 card data is wrong
//         delay(3000); 
//         return;
//       }

//       // ✅ All good, calculate age
//       DateTime now = rtc.now();
//       DateTime dob(birthYear, birthMonth, birthDay);
//       TimeSpan age = now - dob;
//       int totalDays = age.days();

//       if (totalDays < 0) {
//         mp3_play(8826); // 🔊 card data is wrong
//         delay(3000); 
//         return;
//       }

//       int weeks = totalDays / 7;
//       int days = totalDays % 7;

//       Serial.print("DOB from card: ");
//       Serial.println(dobString);

//       Serial.print("Today: ");
//       Serial.print(now.day()); Serial.print("/");
//       Serial.print(now.month()); Serial.print("/");
//       Serial.println(now.year());

//       Serial.print(" Correct Age: ");
//       Serial.print(weeks);
//       Serial.print(" weeks, ");
//       Serial.print(days); 
//       Serial.println(" days");

//       // 🎉 Play congratulatory message first
//       mp3_play(4346);  // "Mubarak ho..."
//       delay(5000); 
 
//       if (weeks > 0) {
//         mp3_play(weeks); delay(1500); 
//         mp3_play(4338);  // "weeks"
//         delay(2000); 
//       }

//       if (days > 0) {
//         mp3_play(days); delay(1500); 
//         mp3_play(1117); // "days"
//         delay(1500); 
//       }

//       int currentWeek = (weeks == 0 && days > 0) ? 1 : (days > 0 ? weeks + 1 : weeks);
//       immunization(currentWeek);
//     }
//   }
// }
