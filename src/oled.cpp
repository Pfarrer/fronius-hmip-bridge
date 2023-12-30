#include <U8g2lib.h>
#include <Wire.h>

#include "oled.hpp"

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/12, /* data=*/14, /* reset=*/U8X8_PIN_NONE);

char OLED_WIFI_STATUS[OLED_STATUS_LENGTH];
char OLED_HTTP_STATUS[OLED_STATUS_LENGTH];
char OLED_BATT_STATUS[OLED_STATUS_LENGTH];
char OLED_GPIO_STATUS[OLED_STATUS_LENGTH];

void oled_setup(void)
{
    u8g2.begin();

    Serial.println("oled_setup done");
}

void oled_loop(int loop_counter)
{
    char str[40];

    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_7x14B_tr);

    snprintf(str, 40, "WIFI: %s", OLED_WIFI_STATUS);
    u8g2.drawStr(0, 15, str);

    snprintf(str, 40, "HTTP: %s", OLED_HTTP_STATUS);
    u8g2.drawStr(0, 31, str);

    snprintf(str, 40, "BATT: %s", OLED_BATT_STATUS);
    u8g2.drawStr(0, 47, str);

    snprintf(str, 40, "GPIO: %s", OLED_GPIO_STATUS);
    u8g2.drawStr(0, 63, str);

    snprintf(str, 40, "%d", loop_counter);
    u8g2.drawStr(100, 63, str);

    u8g2.sendBuffer();
    
    Serial.println("oled_loop done");
}

void oled_wait_for_hmip_boot()
{
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_7x14B_tr);

    u8g2.drawStr(0, 15, "Warte auf HMIP...");
    u8g2.sendBuffer();
    delay(1000);

    Serial.println("oled_wait_for_hmip_boot done");
}