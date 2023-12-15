#include <ESP8266WiFi.h>

#include "config.hpp"
#include "oled.hpp"

char const *wifi_status_name()
{
    switch (WiFi.status())
    {
    case WL_CONNECTED:
        return "OK";
    case WL_NO_SSID_AVAIL:
        return "Kein Empfang";
    case WL_CONNECT_FAILED:
        return "Fehler Verbindung";
    case WL_WRONG_PASSWORD:
        return "Passw. falsch";
    case WL_IDLE_STATUS:
        return "Wartend";
    case WL_DISCONNECTED:
        return "Getrennt";
    default:
        return "Unbekannt";
    }
}

void wifi_setup()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    Serial.println("wifi_setup done");
}

void wifi_loop()
{
    snprintf(OLED_WIFI_STATUS, OLED_STATUS_LENGTH, "%s", wifi_status_name());

    Serial.println("wifi_loop done");
}
