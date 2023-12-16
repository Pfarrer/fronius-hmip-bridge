#include <Arduino.h>
#include <SPI.h>

extern "C" {
  #include "user_interface.h"
}

#include "oled.hpp"
#include "wifi.hpp"
#include "api_client.hpp"
#include "gpio.hpp"

int loop_counter = 0;

void setup()
{
    Serial.begin(9600);
    Serial.println("Booting...");

    wifi_set_sleep_type(LIGHT_SLEEP_T);
    delay(100);

    oled_setup();
    wifi_setup();
    api_client_setup();
    gpio_setup();
}

void loop()
{
    if (loop_counter++ % 4 == 0) {
        wifi_loop();
        api_client_loop();
        gpio_loop();
    }

    oled_loop();
    delay(500);
}
