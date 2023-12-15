#pragma once

#define OLED_STATUS_LENGTH 10

extern char OLED_WIFI_STATUS[OLED_STATUS_LENGTH];
extern char OLED_HTTP_STATUS[OLED_STATUS_LENGTH];
extern char OLED_PTG_STATUS[OLED_STATUS_LENGTH]; // Power to Grid

void oled_setup();
void oled_loop();