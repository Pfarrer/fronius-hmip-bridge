#include <Arduino.h>
#include <SPI.h>

#include "oled.hpp"
#include "wifi.hpp"
#include "api_client.hpp"
#include "gpio.hpp"

void setup()
{
    Serial.begin(9600);
    Serial.print("Booting...\n");

    // oled_setup();
    wifi_setup();
    api_client_setup();
}

void loop()
{
    // oled_loop();
    wifi_loop();

    api_client_perform_request();

    delay(1000);
}
