#include "Arduino.h"

int byteIn;

void setup() {
  Serial.begin(9600);
}

void writeVoltage(int pin) {
    int sensorValue = analogRead(pin);
    float voltage = sensorValue * (5.0/1023.0);
    Serial.print(pin);
    Serial.print(" ");
    Serial.print(voltage);
    Serial.print("\r\n");
    delay(1000);
}

void loop() {
    writeVoltage(A0);
    writeVoltage(A1);
}

