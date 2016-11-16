#include "Arduino.h"
#include "LiquidCrystal.h"
#include "Ultrasonic.h"

int byteIn;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Ultrasonic ultrasonic(8,9);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

float tempFromVolts(float v) {
    float milliamps = (v / 250.0) * 1000.0;
    return 6.25 * milliamps - 25.0;
}

float cToF(float c) {
    return c * 1.8 + 32.0;
}

float writeTemp(int pin) {
    int sensorValue = analogRead(pin);
    float voltage = sensorValue * (5.0/1023.0);
    float temp = tempFromVolts(voltage);
    Serial.print(pin);
    Serial.print(" ");
    Serial.print(voltage);
    Serial.print(" ");
    Serial.print(temp);
    Serial.print("\r\n");
    return temp;
}

void loop() {
    float temp;
    temp = writeTemp(A0);
    lcd.setCursor(0, 0);
    lcd.print("A0: ");
    lcd.print(temp);
    lcd.print(" ");
    lcd.print(cToF(temp));
    lcd.setCursor(0,1);
    temp = writeTemp(A1);
    /*lcd.print("A1: ");
    lcd.print(temp);
    lcd.print(" ");
    lcd.print(cToF(temp));
    */
    lcd.print(ultrasonic.Ranging(CM));
    delay(1000);
}

