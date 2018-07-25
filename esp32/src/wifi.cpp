#include <WiFi.h>
#include <NTPClient.h>
#include "wifi_conf.h"

// WiFi network name and password:
const char * networkName = NETWORK_NAME;
const char * networkPswd = NETWORK_PSWD;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

void connectToWiFi(const char * ssid, const char * pwd)
{
  int ledState = 0;

  Serial.println("Connecting to WiFi network: " + String(ssid));

  WiFi.begin(ssid, pwd);

  while (WiFi.status() != WL_CONNECTED) 
  {
    // Blink LED while we're connecting:
    // digitalWrite(LED_PIN, ledState);
    ledState = (ledState + 1) % 2; // Flip ledState
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void initWiFiAndNTP() {
  connectToWiFi(networkName, networkPswd);
  timeClient.begin();
}

String getTime() {
    timeClient.update();
    return timeClient.getFormattedTime();
}
