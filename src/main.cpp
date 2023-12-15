#include <Arduino.h>
#include <SPI.h>

#include "oled.hpp"
#include "wifi.hpp"
#include "api_client.hpp"
#include "gpio.hpp"

int loop_counter = 0;

void setup()
{
    Serial.begin(9600);
    Serial.print("Booting...\n");
    delay(100);

    oled_setup();
    wifi_setup();
    api_client_setup();
}

void loop()
{
    if (loop_counter++ % 10 == 0) {
        wifi_loop();
        api_client_loop();
    }

    oled_loop();
    delay(100);
}
