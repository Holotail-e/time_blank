//2020.2.19由天空之城编辑
#define WiFi_Logo_width  32
#define WiFi_Logo_height  32
#define drawposition  90
const uint8_t WiFi_Logo_bits[] PROGMEM = {
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x80,0x00,0x00,0x00,0x00,0xFC,0x3F,
0x00,0x80,0x01,0x00,0x00,0x80,0x1F,0x00,
0x00,0x80,0x03,0x00,0x00,0xE0,0x07,0x00,
0x00,0x00,0x07,0x00,0x00,0xF0,0x01,0x00,
0x00,0x00,0x06,0x00,0x00,0xF8,0x00,0x00,
0x00,0x00,0x1C,0x00,0x00,0x7E,0x00,0x00,
0x00,0x00,0x20,0x00,0x00,0x06,0x00,0x00,
0x00,0x00,0xC0,0x00,0x80,0x03,0x00,0x00,
0x00,0x00,0x80,0xFF,0xFF,0x03,0x00,0x00,
0x00,0x00,0x80,0xC7,0xFF,0x07,0x00,0x00,
0x00,0x00,0x80,0xFF,0xFF,0x0F,0x00,0x00,
0x00,0x00,0xE0,0xFC,0xFF,0x07,0x00,0x00,
0x00,0x00,0xF0,0xFE,0xFF,0x71,0x00,0x00,
0x00,0x00,0xFC,0xFE,0xFF,0xF8,0x00,0x00,
0x00,0x00,0xFE,0xFF,0x7F,0xFE,0x01,0x00,
0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x03,0x00,
0x00,0x00,0xFF,0xFF,0xCF,0xFF,0x07,0x00,
0x00,0xF0,0xFF,0xFF,0xE7,0xFF,0x0F,0x00,
0x00,0xF0,0xFF,0xFF,0xFF,0xFF,0x0F,0x00,
0x00,0xF0,0xFF,0xFF,0xFF,0xFF,0x0F,0x00,
0x00,0xE0,0xFF,0xFF,0xFF,0xFF,0x0F,0x00,
0x00,0xE0,0xFF,0xFF,0xFF,0xFF,0x0F,0x00,
0x00,0xF0,0xFF,0xFF,0xFF,0xFF,0x1F,0x00,
0x00,0xF0,0xFF,0xFF,0xFF,0xFF,0x1F,0x00,
0x00,0xF0,0xFF,0xFF,0xFF,0xFF,0x0F,0x00,
0x00,0xC0,0xFF,0x1F,0xFF,0xFF,0x0F,0x00,
0x00,0xC0,0xFF,0x1F,0xFE,0xFF,0x0F,0x00,
0x00,0xC0,0xFF,0x0F,0xFE,0xFF,0x0F,0x00,
0x00,0xD0,0xFF,0x1F,0xFE,0xFF,0x07,0x00,
0x00,0xF0,0xFF,0x3F,0xFF,0xFF,0x07,0x00,
0x00,0xE0,0xFF,0xFF,0xFF,0xFF,0x03,0x00,
0x00,0xE0,0xFD,0xFF,0xFF,0xFF,0x03,0x00,
0x00,0xC0,0x98,0xFF,0xFF,0xFF,0x01,0x00,
0x00,0xC0,0x99,0xFF,0xFF,0xFF,0x01,0x00,
0x00,0x80,0xFF,0xFF,0xFF,0xFF,0x03,0x00,
0x00,0x00,0xFE,0xFF,0xFF,0xC7,0x03,0x00,
0x00,0x00,0xFE,0xFF,0xFF,0xC3,0x07,0x00,
0x00,0x00,0xF8,0xFF,0xFF,0x01,0x04,0x00,
0x00,0x00,0xF0,0xFF,0xFF,0x01,0x00,0x00,
0x00,0x00,0xE0,0xFF,0xFF,0x00,0x00,0x00,
0x00,0x00,0xC0,0x3C,0x78,0x00,0x00,0x00,
0x00,0x00,0xC0,0x00,0x78,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00  };


const uint8_t qingtian[] PROGMEM = {
  //晴天
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x80,0x10,0x00,0x00,0x88,0x18,0x00,
0x80,0x98,0x08,0x01,0x80,0xF1,0x8F,0x01,
0x00,0xFB,0x9F,0x00,0x00,0xFE,0x7F,0x08,
0x20,0xFE,0x7F,0x0C,0x60,0xFE,0x7F,0x03,
0xC0,0xFF,0xFF,0x01,0x00,0xFF,0xFF,0x00,
0xF0,0xFF,0xFF,0x0F,0x00,0xFF,0xFF,0x00,
0x00,0xFF,0xFF,0x00,0x80,0xFF,0x7F,0x00,
0x60,0xFE,0xFF,0x03,0x00,0xFC,0x3F,0x0C,
0x00,0xFE,0x3F,0x00,0x80,0xF3,0x67,0x00,
0x80,0x91,0xC4,0x00,0x00,0x90,0x84,0x00,
0x00,0x98,0x0C,0x00,0x00,0x88,0x08,0x00,
0x00,0x80,0x18,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
  };
const uint8_t zhongyu[] PROGMEM =
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x00,
0x00,0x00,0xFF,0x03,0x00,0x8F,0xFF,0x07,
0x80,0xCF,0xFF,0x07,0xC0,0xFF,0xFF,0x07,
0xE0,0xFF,0xFF,0x0F,0xE0,0xFF,0xFF,0x0F,
0xE0,0xFF,0xFF,0x0F,0xF0,0xFF,0xFF,0x0F,
0xFC,0xFF,0xFF,0x1F,0xFC,0xFF,0xFF,0x3F,
0xFC,0xFF,0xFF,0x3F,0xFC,0xFF,0xFF,0x3F,
0xFC,0xFF,0xFF,0x3F,0xFC,0xFF,0xFF,0x1F,
0xF8,0xFF,0xFF,0x0F,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x20,0x06,0x00,0x00,0x70,0x06,0x00,
0x00,0x70,0x06,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};


const uint8_t dayu[] PROGMEM =
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x00,
0x00,0x80,0x7F,0x00,0x00,0xC3,0xFF,0x01,
0xE0,0xEF,0xFF,0x03,0xE0,0xFF,0xFF,0x03,
0xF0,0xFF,0xFF,0x03,0xF0,0xFF,0xFF,0x07,
0xF0,0xFF,0xFF,0x07,0xF0,0xFF,0xFF,0x07,
0xFC,0xFF,0xFF,0x0F,0xFC,0xFF,0xFF,0x0F,
0xFC,0xFF,0xFF,0x0F,0xFC,0xFF,0xFF,0x0F,
0xFC,0xFF,0xFF,0x0F,0xFC,0xFF,0xFF,0x0F,
0xF0,0xFF,0xFF,0x03,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x08,0x0C,0x00,
0x00,0x1C,0x0C,0x00,0x00,0x1C,0x0C,0x00,
0x00,0x4C,0x0C,0x00,0x00,0xE0,0x00,0x00,
0x00,0xE0,0x00,0x00,0x00,0x40,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

const uint8_t duoyun[] PROGMEM =
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x00,
0x00,0x00,0xFE,0x03,0x00,0x0E,0xFF,0x07,
0x00,0x1F,0xFF,0x07,0x80,0xBF,0xFF,0x0F,
0xC0,0xFF,0xFF,0x0F,0xC0,0xFF,0xFF,0x0F,
0xE0,0xFF,0xFF,0x0F,0xE0,0xFF,0xFF,0x0F,
0xE0,0xFF,0xFF,0x0F,0xF0,0xFF,0xFF,0x1F,
0xF0,0xFF,0xFF,0x3F,0xF8,0xFF,0xFF,0x3F,
0xF8,0xFF,0xFF,0x3F,0xFC,0xFF,0xFF,0x3F,
0xF8,0xFF,0xFF,0x1F,0xF8,0xFF,0xFF,0x1F,
0xF8,0xFF,0xFF,0x0F,0xE0,0xFF,0xFF,0x0F,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};


const uint8_t xiaoyu[] PROGMEM =
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,
0x00,0x80,0xFF,0x03,0x80,0xDF,0xFF,0x07,
0xC0,0xDF,0xFF,0x07,0xC0,0xFF,0xFF,0x07,
0xE0,0xFF,0xFF,0x0F,0xE0,0xFF,0xFF,0x0F,
0xE0,0xFF,0xFF,0x0F,0xF8,0xFF,0xFF,0x0F,
0xF8,0xFF,0xFF,0x1F,0xFC,0xFF,0xFF,0x1F,
0xFC,0xFF,0xFF,0x1F,0xFC,0xFF,0xFF,0x1F,
0xFC,0xFF,0xFF,0x1F,0xF8,0xFF,0xFF,0x1F,
0xF0,0xFF,0xFF,0x0F,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x80,0x00,0x00,0x00,0xC0,0x01,0x00,
0x00,0xC0,0x03,0x00,0x00,0xC0,0x03,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
//2020.2.19由天空之城编辑
const uint8_t icon_clear[] PROGMEM =
{
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
};