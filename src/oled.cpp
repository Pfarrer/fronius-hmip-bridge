#include <U8g2lib.h>
#include <Wire.h>

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/14, /* data=*/12, /* reset=*/U8X8_PIN_NONE);
// U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* clock=*/14, /* data=*/12, /* reset=*/U8X8_PIN_NONE);

void oled_setup(void)
{
    u8g2.begin();

    Serial.println("OLED done");
    delay(1000);
}

void oled_loop(void)
{
     u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_7x14B_tr);
    u8g2.drawStr(0, 24, "Hello World!");
    u8g2.sendBuffer();
    
    Serial.println("OLED send");
    delay(1000);
}