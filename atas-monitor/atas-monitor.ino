
// atas-monitor
// https://github.com/tczerwonka/atas-controller
// board I'm using is a pro/pro mini

//this code uses an INA219 current monitor to monitor the current
//sent from a simple momentary DPDT switch sending either 8V or 12V
//to a Yaesu ATAS antenna.  The display shows raise/lower status and
//current, also indicating STALL if the current exceeds an arbitrary
//300mA.  A red LED also illuminates in a stall condition.

#include <LiquidCrystal.h>
#include <Wire.h>
//https://github.com/flav1972/ArduinoINA219
#include <INA219.h>
INA219 monitor;

// Create an LCD object. Parameters: (RS, E, D4, D5, D6, D7):
LiquidCrystal lcd = LiquidCrystal(4, 5, 6, 7, 8, 9);

//current at which we're stalled
float stall_current = 300;

void setup() {
  //had a 16x1 mounted in something in the junkbox
  //is really an 8x2 on a single line
  lcd.begin(8, 2);

  //Serial.begin(9600);
  monitor.begin();

  pinMode(3,OUTPUT);
}

void loop() {
  if (monitor.busVoltage() < 7) {
    lcd.setCursor(0, 0);
    lcd.print("idle  ");
    lcd.setCursor(0, 1);
    lcd.print("        ");
    digitalWrite(3,LOW);
  }
  if ((monitor.busVoltage() < 11) && (monitor.busVoltage() > 7)) {
    lcd.setCursor(0, 0);
    lcd.print("lower  ");
    if (((monitor.shuntCurrent() * 1000) > stall_current)) {
      lcd.setCursor(0, 0);
      lcd.print("STALL!");
      digitalWrite(3,HIGH);
    }
    lcd.setCursor(5, 1);
    lcd.print("mA");
    lcd.setCursor(0, 1);
    lcd.print(monitor.shuntCurrent() * 1000, 0);
  }
  if (monitor.busVoltage() > 11) {
    lcd.setCursor(0, 0);
    lcd.print("raise ");
    if (((monitor.shuntCurrent() * 1000) > stall_current)) {
      lcd.setCursor(0, 0);
      lcd.print("STALL!");
      digitalWrite(3,HIGH);
    }
    lcd.setCursor(5, 1);
    lcd.print("mA");
    lcd.setCursor(0, 1);
    lcd.print(monitor.shuntCurrent() * 1000, 0);
  }


  //lcd.print("two");
  delay(500);

  //Serial.print("raw shunt voltage: ");
  //Serial.println(monitor.shuntVoltageRaw());

  //Serial.print("raw bus voltage:   ");
  //Serial.println(monitor.busVoltageRaw());

  //Serial.println("--");

  //Serial.print("shunt voltage: ");
  //Serial.print(monitor.shuntVoltage() * 1000, 4);
  //Serial.println(" mV");

  //Serial.print("shunt current: ");
  //Serial.print(monitor.shuntCurrent() * 1000, 4);
  //Serial.println(" mA");

  //Serial.print("bus voltage:   ");
  //Serial.print(monitor.busVoltage(), 4);
  //Serial.println(" V");

  //Serial.print("bus power:     ");
  //Serial.print(monitor.busPower() * 1000, 4);
  //Serial.println(" mW");

}
