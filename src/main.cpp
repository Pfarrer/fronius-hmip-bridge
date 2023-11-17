#include <Arduino.h>
#include <SPI.h>
#include <ESP8266WiFi.h>

char ssid[] = "";
char pass[] = "";

void setup()
{
    Serial.begin(115200);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pass);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.print("Waiting for WLAN connection...");
    }
}

void loop()
{
    Serial.print("Ready...");
    delay(1000);
}
