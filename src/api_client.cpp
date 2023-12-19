#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

#include "config.hpp"
#include "oled.hpp"

WiFiClient client;
HTTPClient http;

int powerToGrid = 0;

void api_client_setup()
{
    Serial.println("api_client_setup done");
}

void api_client_loop()
{
    WiFiClient client;
    HTTPClient http;

    // Send request
    http.useHTTP10(true);
    http.begin(client, FRONIUS_API_URL);
    int http_code = http.GET();
    snprintf(OLED_HTTP_STATUS, OLED_STATUS_LENGTH, "%d", http_code);

    // Parse response
    DynamicJsonDocument doc(2048);
    deserializeJson(doc, http.getStream());

    // Read values
    int powerFromGrid = doc["Body"]["Data"]["Site"]["P_Grid"].as<int>();
    powerToGrid = -powerFromGrid;
    snprintf(OLED_PTG_STATUS, OLED_STATUS_LENGTH, "%d W", powerToGrid);

    // Disconnect
    http.end();

    Serial.println("api_client_loop done");
}