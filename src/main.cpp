#include <Arduino.h>
#include <SPI.h>

extern "C" {
  #include "user_interface.h"
}

#include "config.hpp"
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

    oled_wait_for_hmip_boot();

    api_client_setup();
    gpio_setup();
}

void loop()
{
    wifi_loop();

    if (loop_counter++ >= UPDATE_INTERVAL_SEC) {
        api_client_loop();
        gpio_loop();

        loop_counter = 0;
    }

    oled_loop(loop_counter);
    delay(1000);
}
