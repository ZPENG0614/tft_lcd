#ifndef display_hpp
#define display_hpp
#include <Arduino.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_GFX.h>
#include <SPI.h>

#define TFT_CS   12
#define TFT_DC   14
#define TFT_RST  27
#define TFT_SCK  25
#define TFT_SDA  26

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC,TFT_SDA,TFT_SCK,TFT_RST);//创建显示屏对象并初始化

// 创建缓冲区（适配屏幕分辨率）
uint16_t buffer[128 * 160];  // 128x160的ST7735

//初始化显示屏
void initDisplay(){
    tft.initR(INITR_BLACKTAB); // 使用适当的初始化参数
    tft.setRotation(1); // 设置显示方向，1表示顺时针旋转90度
    tft.fillScreen(ST7735_BLACK);//设置背景颜色
    tft.setTextColor(ST7735_WHITE);//设置文字颜色
    tft.setTextSize(2);//设置字体大小，字体的原始像素大小为6*8，放大之后字体的大小是12*16
}

void display(int x, int y, String str) {
    tft.setCursor(x, y); // 设置起始位置
    for (int i = 0; i < str.length(); i++) {
        tft.print(str[i]); // 逐个字符打印
        int charWidth = 5 * 2; // 字符宽度 = 基础宽度 * 字体大小
        tft.setCursor(x + (i + 1) * charWidth, y); // 调整光标位置
    }
}

void display_clear(){
    tft.fillScreen(ST7735_BLACK);
}



#endif