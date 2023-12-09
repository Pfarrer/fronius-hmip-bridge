#pragma once

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

#include "config.hpp"

WiFiClient client;
HTTPClient http;

String host = "192.168.0.215";
uint16_t port = 8080;
String uri = "/solar_api/v1/GetPowerFlowRealtimeData.fcgi";

void api_client_setup()
{
}

float api_client_perform_request()
{
    WiFiClient client;
    HTTPClient http;

    // Send request
    http.useHTTP10(true);
    http.begin(client, FRONIUS_API_URL);
    http.GET();

    // Parse response
    DynamicJsonDocument doc(2048);
    deserializeJson(doc, http.getStream());

    // Read values
    float powerFromGrid = doc["Body"]["Data"]["Site"]["P_Grid"].as<float>();

    // Disconnect
    http.end();

    return powerFromGrid;
}