
// atas-monitor
// https://github.com/tczerwonka/atas-controller
// board I'm using is a pro/pro mini

#include <LiquidCrystal.h>
#include <Wire.h>
//https://github.com/flav1972/ArduinoINA219
#include <INA219.h>
INA219 monitor;

// Create an LCD object. Parameters: (RS, E, D4, D5, D6, D7):
LiquidCrystal lcd = LiquidCrystal(4, 5, 6, 7, 8, 9);

void setup() {
  //had a 16x1 mounted in something in the junkbox
  //is really an 8x2 on a single line
  lcd.begin(8, 2);

  Serial.begin(9600);
  monitor.begin();
}

void loop() {
  // c, r
  lcd.setCursor(0, 0);
  lcd.print("one");
  lcd.setCursor(0, 1);
  lcd.print("two");

  //Serial.print("raw shunt voltage: ");
  //Serial.println(monitor.shuntVoltageRaw());
  
  //Serial.print("raw bus voltage:   ");
  //Serial.println(monitor.busVoltageRaw());
  
  Serial.println("--");
  
  Serial.print("shunt voltage: ");
  Serial.print(monitor.shuntVoltage() * 1000, 4);
  Serial.println(" mV");
  
  Serial.print("shunt current: ");
  Serial.print(monitor.shuntCurrent() * 1000, 4);
  Serial.println(" mA");
  
  Serial.print("bus voltage:   ");
  Serial.print(monitor.busVoltage(), 4);
  Serial.println(" V");
  
  Serial.print("bus power:     ");
  Serial.print(monitor.busPower() * 1000, 4);
  Serial.println(" mW");
  
}
