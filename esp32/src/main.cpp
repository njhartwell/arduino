#include <Arduino.h>

const int SPEAKER_PIN = 2;

extern void initWiFiAndNTP();
extern String getTime();

void setup() {
  // Initilize hardware:
  pinMode(SPEAKER_PIN, OUTPUT);
  initWiFiAndNTP();
  Serial.begin(9600);
}

void loop() {
    Serial.println(getTime());
    delay(10000);
    digitalWrite(SPEAKER_PIN, HIGH);
    delay(100);
    digitalWrite(SPEAKER_PIN, LOW);
}
