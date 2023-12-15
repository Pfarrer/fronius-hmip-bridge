#include <U8g2lib.h>
#include <Wire.h>

#include "oled.hpp"

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/12, /* data=*/14, /* reset=*/U8X8_PIN_NONE);

char OLED_WIFI_STATUS[OLED_STATUS_LENGTH];
char OLED_HTTP_STATUS[OLED_STATUS_LENGTH];
char OLED_PTG_STATUS[OLED_STATUS_LENGTH]; // Power to Grid

int progressbar_width = 0;

// void reset_status()
// {
//     strcpy("?", OLED_WIFI_STATUS);
//     strcpy("?", OLED_HTTP_STATUS);
//     strcpy("?", OLED_PTG_STATUS);
// }

void oled_setup(void)
{
    // reset_status();
    u8g2.begin();

    Serial.println("oled_setup done");
}

void oled_loop(void)
{
    char str[40];

    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_7x14B_tr);

    snprintf(str, 40, "WIFI: %s", OLED_WIFI_STATUS);
    u8g2.drawStr(0, 15, str);

    snprintf(str, 40, "HTTP: %s", OLED_HTTP_STATUS);
    u8g2.drawStr(0, 31, str);

    snprintf(str, 40, "PTG : %s", OLED_PTG_STATUS);
    u8g2.drawStr(0, 47, str);

    u8g2.drawBox(0, 55, 2*progressbar_width, 15);
    if (++progressbar_width > 64) {
        progressbar_width = 0;
    }

    u8g2.sendBuffer();
    
    Serial.println("oled_loop done");
}
