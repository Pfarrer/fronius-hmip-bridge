#include <ESP8266WiFi.h>

#include "config.hpp"

void wifi_setup()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    Serial.print("Waiting for WLAN connection");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("done");
}

void wifi_loop()
{
}
