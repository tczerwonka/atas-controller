
// atas-monitor
// https://github.com/tczerwonka/atas-controller

#include <LiquidCrystal.h>

// Create an LCD object. Parameters: (RS, E, D4, D5, D6, D7):
LiquidCrystal lcd = LiquidCrystal(2, 3, 4, 5, 6, 7);

void setup() {
  //had a 16x1 mounted in something in the junkbox
  lcd.begin(16, 1);
}

void loop() {
  // c, r
  lcd.setCursor(0, 0);
  // Print the string 'Hello World!':
  lcd.print("boo");
}
