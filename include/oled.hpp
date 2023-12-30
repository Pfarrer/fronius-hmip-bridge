#pragma once

#define OLED_STATUS_LENGTH 10

extern char OLED_WIFI_STATUS[OLED_STATUS_LENGTH];
extern char OLED_HTTP_STATUS[OLED_STATUS_LENGTH];
extern char OLED_BATT_STATUS[OLED_STATUS_LENGTH]; // Power to Grid
extern char OLED_GPIO_STATUS[OLED_STATUS_LENGTH];

void oled_setup();
void oled_loop(int loop_counter);

void oled_wait_for_hmip_boot();