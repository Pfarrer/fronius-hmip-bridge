#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

#include "config.hpp"
#include "oled.hpp"

WiFiClient client;
HTTPClient http;

int batteryChargePower = 0;
int gridInfeedPower = 0;
int soc = 0;

int lastSuccessfulResponse = 0;

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

    if (http_code == 200)
    {
        lastSuccessfulResponse = 0;

        // Parse response
        DynamicJsonDocument doc(2048);
        deserializeJson(doc, http.getStream());

        // Read values
        batteryChargePower = -1 * doc["Body"]["Data"]["Site"]["P_Akku"].as<int>();
        gridInfeedPower = -1 * doc["Body"]["Data"]["Site"]["P_Grid"].as<int>();
        soc = doc["Body"]["Data"]["Inverters"]["1"]["SOC"].as<int>();
        
        snprintf(OLED_BATT_STATUS, OLED_STATUS_LENGTH, "%d%% & %+dW", soc, batteryChargePower + gridInfeedPower);
    }
    else if (lastSuccessfulResponse == 10)
    {
        soc = 0;
        batteryChargePower = 0;
        gridInfeedPower = 0;
    }
    else
    {
        lastSuccessfulResponse++;
    }

    // Disconnect
    http.end();

    Serial.println("api_client_loop done");
}