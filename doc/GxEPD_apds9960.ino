#include <GxEPD.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
#include "SPI.h"
#include <Button2.h>
#include <Ticker.h>

#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>
#include <Fonts/FreeSans9pt7b.h>

#include "Adafruit_APDS9960.h"
Adafruit_APDS9960 apds;

const unsigned char gImage_1[1280] = { /* 0X81,0X01,0X80,0X00,0X50,0X00, */
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X00, 0X0F, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFE, 0X80, 0X17, 0XFF, 0XFF, 0XFF, 0XFF, 0X80, 0X03, 0XFF,
    0XFE, 0X40, 0X27, 0XFF, 0XFF, 0XFF, 0XFF, 0XA0, 0X38, 0XFF, 0XFE, 0X10, 0X87, 0XFF, 0XFF, 0XFF,
    0XFF, 0XA0, 0X3A, 0XFF, 0XFE, 0X09, 0X07, 0XFF, 0XFF, 0XFF, 0XFF, 0XA0, 0X3A, 0XFF, 0XFE, 0X26,
    0X47, 0XFF, 0XFF, 0XFF, 0XFF, 0XA0, 0X3A, 0XFF, 0XFE, 0X40, 0X27, 0XFF, 0XFF, 0XFF, 0XFF, 0XA0,
    0X38, 0XFF, 0XFE, 0X80, 0X17, 0XFF, 0XFF, 0XFF, 0XFF, 0X80, 0X03, 0XFF, 0XFF, 0X00, 0X0F, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF1, 0XFF, 0X01, 0XFF, 0XFF, 0XF1, 0XFC,
    0X07, 0XFF, 0XFF, 0XF1, 0XFE, 0X00, 0XFF, 0XFF, 0XE1, 0XF8, 0X03, 0XFF, 0XFF, 0XC1, 0XFC, 0X00,
    0X7F, 0XFF, 0XC1, 0XF0, 0X01, 0XFF, 0XFF, 0X81, 0XFC, 0X38, 0X7F, 0XFF, 0XC1, 0XF0, 0XE1, 0XFF,
    0XFE, 0X01, 0XF8, 0X7C, 0X3F, 0XFF, 0X81, 0XE1, 0XF0, 0XFF, 0XFE, 0X01, 0XF8, 0XFE, 0X38, 0XFF,
    0X01, 0XE3, 0XF8, 0XFF, 0XFE, 0X11, 0XF8, 0XFE, 0X38, 0XFF, 0X01, 0XE3, 0XF8, 0XFF, 0XFF, 0XF1,
    0XF8, 0XFE, 0X38, 0XFE, 0X11, 0XE3, 0XF8, 0XFF, 0XFF, 0XF1, 0XF8, 0XFE, 0X3F, 0XFC, 0X31, 0XE3,
    0XF8, 0XFF, 0XFF, 0XF1, 0XF8, 0XFE, 0X3F, 0XFC, 0X31, 0XE3, 0XF8, 0XFF, 0XFF, 0XF1, 0XF8, 0XFE,
    0X3F, 0XF8, 0X71, 0XE3, 0XF8, 0XFF, 0XFF, 0XF1, 0XF8, 0XFE, 0X3F, 0XF0, 0XF1, 0XE3, 0XF8, 0XFF,
    0XFF, 0XF1, 0XF8, 0XFE, 0X3F, 0XF0, 0X00, 0X63, 0XF8, 0XFF, 0XFF, 0XF1, 0XF8, 0XFE, 0X3F, 0XF0,
    0X00, 0X63, 0XF8, 0XFF, 0XFF, 0XF1, 0XF8, 0X7C, 0X3F, 0XF0, 0X00, 0X61, 0XF0, 0XFF, 0XFF, 0XF1,
    0XFC, 0X38, 0X7F, 0XFF, 0XF1, 0XF0, 0XE1, 0XFF, 0XFF, 0XF1, 0XFC, 0X00, 0X78, 0XFF, 0XF1, 0XF0,
    0X01, 0XFF, 0XFF, 0XF1, 0XFE, 0X00, 0XF8, 0XFF, 0XF1, 0XF8, 0X03, 0XFF, 0XFF, 0XF1, 0XFF, 0X01,
    0XF8, 0XFF, 0XF1, 0XFC, 0X07, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X39, 0XCF, 0X9F, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFE, 0X79, 0X8F, 0X1F, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFE,
    0X73, 0X0E, 0X1F, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFC, 0XF3, 0XCF, 0X9F, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFC, 0XF3, 0XCF, 0X9F, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF9, 0XE7, 0XCF,
    0X9F, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF9, 0XE7, 0XCF, 0X9F, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF7, 0XBD, 0XFF, 0XBF, 0XFF, 0XFF, 0XBF, 0XFF, 0XFF,
    0XFF, 0XF7, 0X5D, 0XFF, 0XBF, 0XFF, 0XFF, 0XBF, 0XFF, 0XFF, 0XFF, 0XFB, 0X5B, 0X1C, 0XA1, 0XC7,
    0X1C, 0XB1, 0XBB, 0XFF, 0XFF, 0XFB, 0X5A, 0XEB, 0X2E, 0XBA, 0XEB, 0X2E, 0XBB, 0XFF, 0XFF, 0XFA,
    0XEA, 0X0B, 0XAE, 0X83, 0X3B, 0XB0, 0XD7, 0XFF, 0XFF, 0XFA, 0XEA, 0XFB, 0XAE, 0XBF, 0XDB, 0XAE,
    0XD7, 0XFF, 0XFF, 0XFD, 0XF6, 0XEB, 0X2E, 0XBA, 0XEB, 0X2C, 0XEF, 0XFF, 0XFF, 0XFD, 0XF7, 0X1C,
    0XAE, 0XC7, 0X1C, 0XB2, 0XEF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XEF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XDF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF7, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF7, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFE,
    0X7F, 0X3F, 0XFC, 0X3F, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X63, 0X7F, 0XF9, 0X9F, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XC1, 0XFF, 0XF9, 0XF9, 0X30, 0XE1, 0X99, 0XFF, 0XFF, 0XFC, 0X80, 0X9F,
    0XFC, 0X39, 0X32, 0X64, 0XDB, 0XFF, 0XFF, 0XFF, 0X80, 0XFF, 0XFF, 0X99, 0X32, 0X64, 0XD3, 0XFF,
    0XFF, 0XFF, 0XC1, 0XFF, 0XF9, 0X99, 0X32, 0X64, 0XC7, 0XFF, 0XFF, 0XFF, 0XE3, 0XFF, 0XFC, 0X3C,
    0X32, 0X64, 0XE7, 0XFF, 0XFF, 0XFF, 0X7F, 0X7F, 0XFF, 0XFF, 0XFF, 0XFF, 0XEF, 0XFF, 0XFF, 0XFE,
    0X77, 0X3F, 0XFF, 0XFF, 0XFF, 0XFF, 0XCF, 0XFF, 0XFF, 0XFF, 0XF7, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
    0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
};
#define SPI_MOSI 23
#define SPI_MISO -1
#define SPI_CLK 18

#define ELINK_SS    5
#define ELINK_BUSY  4
#define ELINK_RESET 12
#define ELINK_DC    19
#define BTN         36
#define I2C_SDA     21
#define I2C_SCL     22

Button2 btn(BTN);
Ticker btnTicker;
// #define BUTTON_PIN_BITMASK 0x1000000000‬

#include <GxGDEW0102I4F/GxGDEW0102I4F.h>
GxIO_Class io(SPI, ELINK_SS, ELINK_DC, ELINK_RESET);
GxEPD_Class display(io, ELINK_RESET, ELINK_BUSY);
//width:50,height:47
const unsigned char col[] U8X8_PROGMEM = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x9f, 0xe0, 0x00, 0x00, 0x00, 0x08, 0x63, 0x07, 0xf0, 0x00, 0x00, 0x00, 0x18, 0x42, 0x03, 0xf0, 0x00, 0x00, 0x00, 0x10, 0xc0, 0x03, 0xf0, 0x00, 0x00, 0x00, 0x30, 0x80, 0x03, 0xf0, 0x00, 0x00, 0x00, 0x28, 0x80, 0x03, 0xf0, 0x00, 0x00, 0x00, 0x2f, 0x80, 0x03, 0xf0, 0x00, 0x00, 0x00, 0x6f, 0x80, 0x03, 0xf0, 0x00, 0x00, 0x00, 0x61, 0x00, 0x03, 0xff, 0x80, 0x00, 0x00, 0x49, 0x5a, 0x9e, 0x07, 0xc0, 0x00, 0x00, 0x4b, 0x5e, 0xac, 0x03, 0xe0, 0x00, 0x00, 0xca, 0x55, 0xa8, 0x03, 0xf0, 0x00, 0x00, 0xdb, 0xd7, 0xb0, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x31, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x33, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x63, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x62, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x0f, 0xfe, 0x00, 0x1f, 0xf0, 0x00, 0x00, 0x00, 0x3f, 0xf0, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};


void show(char *txt)
{
    int x = display.width() / 2;
    int y = display.height() / 2 ;
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(x, y);
    display.println(txt);
    display.update();
}
void setup()
{
    Serial.begin(115200);
    Serial.println();
    Serial.println("setup");
    SPI.begin(SPI_CLK, SPI_MISO, SPI_MOSI, -1);
    display.init(115200); // enable diagnostic output on Serial
    display.setRotation(1);
    // display.invertDisplay(1);
    display.setTextColor(GxEPD_BLACK);
    display.setFont(&FreeMonoBold9pt7b);
    Serial.println("setup done");

    display.fillScreen(GxEPD_WHITE);
    display.update();

    Wire.begin(I2C_SDA, I2C_SCL);
    if (!apds.begin()) {
        Serial.println("failed to initialize device! Please check your wiring.");
        show("apds9960 fail");
        while (1);
    }
    show("apds9960 PASS");
    delay(1000);

    apds.enableProximity(true);
    apds.enableGesture(true);

    btn.setLongClickHandler([](Button2 & b) {
        esp_sleep_enable_ext1_wakeup(68719476736, ESP_EXT1_WAKEUP_ALL_LOW);
        Serial.println("Going to sleep now");
        esp_deep_sleep_start();
        Serial.println("This will never be printed");
    });

    btnTicker.attach_ms(30, [] {
        btn.loop();
    });

    for (;;) {
        uint8_t gesture = apds.readGesture();
        if (gesture == APDS9960_DOWN) {
            show("Down");
            Serial.println("v");
        }
        if (gesture == APDS9960_UP) {
            show("Up");
            Serial.println("^");
        }
        if (gesture == APDS9960_LEFT) {
            show("Left");
            Serial.println("<");
        }
        if (gesture == APDS9960_RIGHT) {
            show("Right");
            Serial.println(">");
        }
    }
}

int i = 0;
void loop()
{
    i = i + 1 > 3 ? 0 : 1 + i;
    display.setRotation(i);
    showFont("", &FreeMonoBold9pt7b);
    display.update();
    delay(5000);
}

void showFont(const char name[], const GFXfont *f)
{
    display.fillScreen(GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);
    display.setFont(f);
    display.setCursor(0, 0);
    display.println(" !\"#$%&'()*+,-./");
    display.println("0123456789:;<=>?");
    display.println("@ABCDEFGHIJKLMNO");
    display.println("PQRSTUVWXYZ[\\]^_");
    display.println("`abcdefghijklmno");
    display.println("pqrstuvwxyz{|}~ ");
}
