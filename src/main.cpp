#include <WiFi.h>
#include <Arduino.h>
#include <TFT_eSPI.h>

const char* ssid = "Cleverest.tech";
const char* password = "d96328a2ecc99b9caad75219067b6b02f3e3dd99";
const char* serverIP = "192.168.0.104";
const int serverPort = 1234;  // Port to connect

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    if (client.connect(serverIP, serverPort)) {
      for (int i = 1; i <= 5; i++) {
        client.write((uint8_t*)&i, sizeof(i));
        Serial.print("Sent integer: ");
        Serial.println(i);
        delay(10000);  // Wait 5 seconds between each integer
      }
      client.stop();
    } else {
      Serial.println("Failed to connect to the server");
    }
  } else {
    Serial.println("WiFi Disconnected");
  }
  
  delay(10000);  // Wait for 5 seconds
}
