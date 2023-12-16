#include <Arduino.h>

#include "config.hpp"
#include "api_client.hpp"
#include "oled.hpp"

#define GPIO_PIN 14 // "D5"

bool currentPinValue = false;

void gpio_setup()
{
    pinMode(GPIO_PIN, OUTPUT); 
    Serial.println("gpio_setup done");
}

void gpio_loop()
{
    if (currentPinValue && powerToGrid < 0) {
        currentPinValue = false;
    } else if (!currentPinValue && powerToGrid > EXCESS_POWER_THRESHOLD) {
        currentPinValue = true;
    }

    digitalWrite(GPIO_PIN, currentPinValue);
    snprintf(OLED_GPIO_STATUS, OLED_STATUS_LENGTH, "%s", currentPinValue ? "AN" : "AUS");

    Serial.println("gpio_loop done");
}