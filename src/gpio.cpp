#include <Arduino.h>

#include "config.hpp"
#include "api_client.hpp"
#include "oled.hpp"

#define GPIO_ALL_OFF      16 // "D0" --> IN1 (HMIP)
#define GPIO_CONSUMER_1    5 // "D1" --> IN2 (HMIP)
#define GPIO_CONSUMER_2    4 // "D2" --> IN3 (HMIP)

/* Number of activated consumers, max. 2 at the moment. */
int state = 0;

void enableConsumer(int consumerNumber);
void disableConsumers();

void gpio_setup()
{
    pinMode(GPIO_ALL_OFF, OUTPUT);
    pinMode(GPIO_CONSUMER_1, OUTPUT);
    pinMode(GPIO_CONSUMER_2, OUTPUT); 

    disableConsumers();

    Serial.println("gpio_setup done");
}

void gpio_loop()
{
    if (soc >= TURN_ON_SOC_GTE
        && (batteryChargePower + gridInfeedPower) > EXCESS_POWER_THRESHOLD_GT
        && state < 2)
    {
        // Criterias are fullfiled to active one more consumer
        state++;
        enableConsumer(state);
    }

    if (soc < TURN_OFF_SOC_LT && state > 0)
    {
        // Reset state to no active consumers
        state = 0;
        disableConsumers();
    }

    // digitalWrite(GPIO_PIN, currentPinValue);
    snprintf(OLED_GPIO_STATUS, OLED_STATUS_LENGTH, "%d AN", state);

    Serial.println("gpio_loop done");
}

void enableConsumer(int consumerNumber)
{
    int pin = GPIO_CONSUMER_1;
    if (consumerNumber == 2)
    {
        pin = GPIO_CONSUMER_2;
    }

    digitalWrite(pin, true);
    delay(200);
    digitalWrite(pin, false);
}

void disableConsumers()
{
    digitalWrite(GPIO_ALL_OFF, true);
    delay(200);
    digitalWrite(GPIO_ALL_OFF, false);
}