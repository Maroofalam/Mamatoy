String generateUUID() {
  String uuid = "";
  for (int i = 0; i < 36; i++) {
    if (i == 8 || i == 13 || i == 18 || i == 23) {
      uuid += "-";
    } else {
      int r = random(16);
      uuid += String(r, HEX);
    }
  }
  return uuid;
}


