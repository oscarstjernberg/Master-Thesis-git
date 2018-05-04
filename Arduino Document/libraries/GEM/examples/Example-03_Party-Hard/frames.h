/*
  Party Hard menu example using GEM library.

  Sprites of the animation frames used in the example.
  
  Additional info (including the breadboard view) available on GitHub:
  https://github.com/Spirik/GEM
  
  This example code is in the public domain.
*/

static const uint8_t partyFrame1 [] PROGMEM = {
0x80, 0x40, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x0F, 0x00, 0xC0, 0x7F,
0x40, 0x40, 0x7F, 0x41, 0xF8, 0x0E, 0x03, 0x06, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x80, 0x40, 0xC0, 0x00, 0x00, 0x00, 0xE0, 0x30, 0xC0, 0x00, 0x80, 0xE0, 0x30,
0xF0, 0xFC, 0xBF, 0xDB, 0xBF, 0xF0, 0x98, 0x88, 0x8C, 0x84, 0xCC, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4,
0xCC, 0x84, 0xC4, 0x8C, 0x88, 0x88, 0x88, 0x18, 0x08, 0x18, 0x10, 0x10, 0x20, 0x40, 0x40, 0xE0,
0xFC, 0x18, 0xF0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x80, 0x00, 0x00, 0x00,
0xFC, 0x0C, 0x06, 0x02, 0x03, 0x00, 0x00, 0x80, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x60, 0xD8, 0x06, 0x01, 0x00, 0x03, 0x1C, 0x10, 0x36, 0x49, 0x70, 0x01, 0x03, 0x04, 0x04, 0x0C,
0x0F, 0x0F, 0x0F, 0x1D, 0x0E, 0x1F, 0x0F, 0x0D, 0x0B, 0x0E, 0x05, 0x0E, 0x0F, 0x0C, 0x0F, 0x0A,
0x0D, 0x1F, 0x0F, 0x1D, 0x1F, 0x33, 0x3F, 0x37, 0x6B, 0x56, 0xDE, 0xBC, 0xFC, 0xBE, 0xF7, 0xDD,
0xEF, 0xFF, 0xDF, 0x83, 0x02, 0x04, 0x04, 0x1C, 0x30, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x06, 0x0C, 0xF8,
0x00, 0x00, 0x00, 0x38, 0xE8, 0x0C, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x01, 0x0F, 0x38, 0xE0, 0x10, 0x20, 0x40, 0x40, 0xC0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xC0, 0xC0, 0x40, 0x40, 0x40,
0x20, 0x10, 0x10, 0x18, 0x0C, 0x02, 0x07, 0x38, 0x40, 0x80, 0x00, 0x00, 0x01, 0x02, 0x03, 0x06,
0x0F, 0x1F, 0x3F, 0x77, 0xDE, 0x3C, 0xF8, 0xE0, 0x00, 0x00, 0x03, 0x2C, 0xD8, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
0x00, 0x00, 0x00, 0x00, 0x7F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0xF0, 0x30, 0x0F, 0x86, 0xD6, 0x64, 0x6C, 0x3F, 0x91, 0x60, 0x41, 0xC3, 0x83, 0x87, 0xC5,
0x65, 0x6C, 0x25, 0x31, 0x11, 0x30, 0x40, 0x00, 0x00, 0x06, 0x4C, 0xD8, 0x98, 0x0C, 0x18, 0x08,
0x1C, 0x08, 0x0C, 0x0C, 0x06, 0x04, 0x86, 0x81, 0xC1, 0xC3, 0x24, 0x0C, 0x18, 0x10, 0x90, 0x50,
0x30, 0x10, 0x30, 0xD0, 0xF0, 0x60, 0xD8, 0xF9, 0xED, 0x07, 0x00, 0x00, 0x01, 0x6E, 0x98, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0,
0xF0, 0x3F, 0xFE, 0xFB, 0xFD, 0xFE, 0x3E, 0x1C, 0x00, 0x02, 0x02, 0x81, 0xE0, 0x96, 0xFB, 0x08,
0x0C, 0x04, 0xFC, 0x02, 0x06, 0x04, 0x0C, 0xF8, 0x30, 0xE0, 0x04, 0x04, 0x07, 0x03, 0x33, 0x1E,
0x07, 0x82, 0xE6, 0xFF, 0xE1, 0xC1, 0x81, 0xE0, 0xF0, 0xF0, 0xF0, 0xE0, 0x00, 0x00, 0x05, 0x0A,
0x18, 0xE8, 0x3E, 0x13, 0xF3, 0x0E, 0x07, 0xFF, 0x18, 0x30, 0xE0, 0x00, 0x00, 0x00, 0xFF, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F,
0xF9, 0xC0, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x01, 0x03, 0x00, 0x01, 0x0B,
0x06, 0x02, 0x01, 0x03, 0x0E, 0x02, 0x02, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x1F, 0x0F, 0x07, 0x03, 0x01, 0x00, 0xE0, 0x30, 0x10,
0xFF, 0x01, 0x00, 0xF0, 0x0F, 0x00, 0xE0, 0x1F, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x60, 0x9F, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x3F, 0x20, 0x60, 0x40, 0x40, 0x40, 0xC0, 0xC0, 0x80, 0xC0,
0x60, 0x5F, 0x06, 0x0C, 0x18, 0x30, 0x60, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xC0, 0xC0, 0x60, 0x20, 0xF8, 0x1F, 0x00, 0x00,
0x7F, 0x00, 0x00, 0x87, 0x86, 0xC4, 0x27, 0x06, 0x04, 0x00, 0xFF, 0x00, 0x00, 0x40, 0xBF, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
0x06, 0x06, 0x0C, 0x0C, 0x18, 0x18, 0x10, 0x30, 0x60, 0x60, 0xC0, 0xC0, 0x80, 0x80, 0x81, 0x03,
0x03, 0x04, 0x06, 0x04, 0x0C, 0x08, 0x08, 0x18, 0x10, 0x31, 0x21, 0x31, 0x43, 0xC2, 0x82, 0x06,
0x86, 0x84, 0xE4, 0x24, 0x3C, 0x0C, 0x0C, 0x04, 0x0C, 0xC4, 0xE4, 0x3C, 0x0C, 0x06, 0x06, 0x02,
0x02, 0x03, 0x03, 0x03, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1C, 0x30, 0x60,
0x40, 0xC0, 0x8C, 0x9F, 0x00, 0x80, 0x40, 0xE0, 0x30, 0x1C, 0x03, 0x00, 0x00, 0x00, 0x3B, 0xC4,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const uint8_t partyFrame2 [] PROGMEM = {
0x80, 0x40, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xF8, 0xF0, 0xE0, 0x00, 0x00, 0x80, 0x80, 0x80, 0xC0, 0x40,
0xC0, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0xC0, 0x80, 0x80, 0x80, 0x80, 0x80,
0x80, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0,
0x18, 0x08, 0xFF, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x40, 0x20, 0xA0, 0xC0, 0x00, 0xF0, 0x08, 0x08,
0x04, 0x7C, 0x88, 0xC8, 0xFF, 0xFF, 0xDA, 0xE7, 0xFF, 0xFF, 0xF9, 0xB9, 0xEC, 0xDC, 0x7C, 0xEC,
0xFC, 0xEC, 0xDC, 0xDC, 0xFC, 0xEC, 0xBC, 0xEC, 0xBC, 0xD8, 0xB8, 0xF8, 0x30, 0xF0, 0xB0, 0xE0,
0xE1, 0x71, 0xF9, 0xBF, 0x57, 0xED, 0xFF, 0x3E, 0x08, 0x10, 0x20, 0x60, 0x80, 0x00, 0xF8, 0x1F,
0x00, 0x00, 0x3F, 0x00, 0x02, 0xC3, 0xC3, 0x22, 0x23, 0x06, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0x60,
0xF8, 0x0C, 0x04, 0xFC, 0x78, 0x4E, 0xC3, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x02, 0x03, 0x02,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0xC1, 0x41, 0x21, 0xC3, 0x03, 0x03, 0x06, 0x07,
0x0F, 0x0F, 0x1E, 0x3F, 0x6F, 0xFF, 0xDD, 0xB8, 0x70, 0xE0, 0xC0, 0x00, 0x00, 0x01, 0x07, 0x18,
0x30, 0x20, 0x20, 0xE0, 0xC6, 0x8F, 0x00, 0x80, 0xC0, 0xF0, 0x1C, 0x07, 0x01, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x7F, 0x03, 0x00, 0xFF,
0x01, 0x00, 0xFE, 0x1F, 0xC0, 0xF0, 0x3F, 0xA3, 0xE6, 0xC4, 0x44, 0x88, 0x88, 0xFC, 0x18, 0x18,
0x30, 0x30, 0x70, 0x40, 0x70, 0x40, 0xD0, 0x50, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0xC8, 0xC8,
0x88, 0x84, 0xC4, 0x82, 0xC2, 0xC3, 0xC1, 0x40, 0x60, 0x60, 0x20, 0x31, 0x16, 0x18, 0x30, 0x20,
0x40, 0x80, 0x80, 0x80, 0x00, 0x80, 0x81, 0x81, 0x83, 0x82, 0x43, 0xE7, 0xE4, 0x18, 0x08, 0x00,
0x00, 0x06, 0x3F, 0xFF, 0x31, 0x21, 0x2D, 0x2C, 0x21, 0xFF, 0x1F, 0x0C, 0x04, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x06, 0x03,
0xC2, 0x62, 0x33, 0x13, 0x1F, 0x18, 0xFE, 0xE7, 0x30, 0xD0, 0xCA, 0xCC, 0x83, 0x01, 0x1A, 0x24,
0x3C, 0x18, 0x58, 0x38, 0x8C, 0x8C, 0x42, 0xC4, 0x42, 0x43, 0xC6, 0x80, 0x80, 0x00, 0x00, 0x44,
0x4C, 0x38, 0x31, 0x30, 0xF0, 0x30, 0x30, 0x30, 0xF0, 0x10, 0x18, 0x08, 0x0C, 0x8C, 0x82, 0x81,
0x00, 0x00, 0x00, 0x3C, 0xC7, 0xC0, 0x60, 0x20, 0x3F, 0x1F, 0x19, 0x3F, 0x7F, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1C, 0x30, 0xE0, 0x00,
0x07, 0x00, 0x00, 0xC0, 0x60, 0xFF, 0x07, 0x1F, 0x3F, 0x1F, 0x0F, 0x07, 0x03, 0x00, 0x00, 0x40,
0x60, 0x3C, 0x17, 0x3D, 0x60, 0xE0, 0x20, 0x33, 0x3C, 0x60, 0x60, 0x20, 0x1F, 0x13, 0x1E, 0x00,
0x00, 0x00, 0x00, 0x03, 0x01, 0x00, 0x0C, 0x1F, 0x3F, 0x7F, 0xFE, 0xFC, 0xFF, 0x7F, 0x3F, 0x1F,
0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x17, 0x11, 0x01, 0x02, 0x80, 0xFF, 0x3F, 0x00,
0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00,
0x00, 0x00, 0x00, 0x1F, 0xF0, 0x07, 0x1E, 0xF0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x80, 0xC0, 0x60, 0x30, 0x1C, 0x0C, 0x08, 0x0C, 0x0C, 0x04, 0x07, 0x01, 0x00, 0x00, 0x00,
0x00, 0x00, 0x80, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00,
0x00, 0x00, 0x00, 0x00, 0x7F, 0xF8, 0x00, 0x00, 0x01, 0x07, 0x3E, 0xEC, 0x0C, 0x08, 0x18, 0x30,
0x30, 0x20, 0x20, 0x60, 0x60, 0x40, 0x40, 0x40, 0x40, 0x40, 0xC0, 0x40, 0xC0, 0x40, 0x40, 0xC0,
0xC0, 0x40, 0x60, 0x60, 0x60, 0x20, 0x60, 0xF0, 0x30, 0x10, 0x18, 0x18, 0x0C, 0x0C, 0x04, 0x06,
0x03, 0x01, 0x80, 0x80, 0x40, 0x40, 0x60, 0x20, 0x30, 0x10, 0x18, 0x08, 0x0C, 0x04, 0x06, 0x02,
0x83, 0x81, 0xC1, 0x40, 0x60, 0x20, 0x30, 0x10, 0x18, 0x0F, 0x77, 0xC0, 0x80, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const uint8_t partyFrame3 [] PROGMEM = {
0x80, 0x40, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x80, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8,
0x0C, 0x04, 0xFF, 0x00, 0x00, 0xFF, 0x80, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0xC0, 0x20, 0x20, 0x10, 0xF0, 0x20,
0x20, 0xFC, 0xFF, 0x6B, 0x9F, 0xFF, 0xFC, 0xE4, 0xE6, 0xB2, 0x72, 0xF3, 0xB1, 0xF3, 0xB1, 0x71,
0x71, 0xF1, 0xB1, 0xF1, 0xB1, 0xF1, 0x61, 0xE3, 0xE2, 0xC2, 0xC2, 0xC2, 0x82, 0x86, 0xC4, 0xE4,
0xFC, 0x5F, 0xB7, 0xFE, 0xF8, 0x20, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x0F,
0x00, 0x00, 0x1F, 0x00, 0x01, 0xE1, 0x61, 0x11, 0x11, 0x03, 0x00, 0x80, 0xFF, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x80, 0xE0, 0x38, 0x0C, 0x03, 0x01, 0x00, 0x02, 0x07, 0x0C, 0x0B, 0x0C, 0x08, 0x00, 0x01, 0x02,
0x03, 0x03, 0x03, 0x03, 0x07, 0x03, 0x07, 0x03, 0x02, 0x03, 0x03, 0x01, 0x03, 0x03, 0x03, 0x03,
0x03, 0x03, 0x03, 0x02, 0x07, 0x06, 0x07, 0x86, 0x0F, 0x0C, 0x0F, 0x1A, 0x1F, 0x3F, 0x3D, 0x7B,
0xFE, 0xBD, 0xFF, 0x77, 0xE0, 0xC0, 0x80, 0x00, 0x01, 0x02, 0x04, 0x18, 0x20, 0xC0, 0x03, 0x0C,
0x18, 0x10, 0x90, 0xF0, 0xE3, 0xC7, 0x80, 0x40, 0xE0, 0xF8, 0x8E, 0x03, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3E, 0x03, 0xF1,
0x3F, 0x01, 0xE1, 0xFF, 0x8C, 0x98, 0x10, 0x10, 0x20, 0x20, 0xF0, 0x60, 0x60, 0xC0, 0xC0, 0xC0,
0x00, 0xC0, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10,
0x08, 0x08, 0x0C, 0x04, 0x02, 0x83, 0x81, 0x80, 0xC7, 0x58, 0x60, 0xC0, 0x80, 0x00, 0x00, 0x00,
0x00, 0x01, 0x03, 0x07, 0x06, 0x0D, 0x0B, 0x0F, 0x9C, 0x90, 0x60, 0x20, 0x00, 0x01, 0x07, 0xF8,
0x00, 0x03, 0x1F, 0xFF, 0x18, 0x10, 0x16, 0x16, 0x10, 0xFF, 0x8F, 0x06, 0x02, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x03, 0x00, 0x0C, 0x07,
0x04, 0xC4, 0x63, 0xF8, 0x9E, 0xC3, 0x43, 0x29, 0x32, 0x0E, 0x07, 0x68, 0x90, 0xF0, 0x60, 0x61,
0xE1, 0x31, 0x31, 0x0B, 0x11, 0x08, 0x0C, 0x18, 0x00, 0x00, 0x00, 0x03, 0x13, 0x32, 0xE2, 0xC7,
0xC2, 0xC3, 0xC3, 0xC3, 0xC1, 0xC1, 0x41, 0x60, 0x20, 0x30, 0x30, 0x08, 0x04, 0x01, 0x02, 0x02,
0xF2, 0x1C, 0x02, 0x82, 0x82, 0xFE, 0x7E, 0x65, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xF8, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x38, 0x60, 0xC0, 0x00,
0x0F, 0x01, 0xFC, 0x1F, 0x7F, 0xFC, 0x7F, 0x3F, 0x1F, 0x0E, 0x00, 0x00, 0x00, 0x80, 0xF0, 0x5D,
0xF4, 0x82, 0x82, 0x81, 0xCF, 0xF1, 0x81, 0x83, 0x82, 0x7E, 0x4C, 0x78, 0x01, 0x01, 0x00, 0x00,
0x0C, 0x07, 0x00, 0x30, 0x7C, 0xFF, 0xFC, 0xF8, 0xF0, 0xFC, 0xFE, 0xFE, 0x7E, 0x3C, 0x00, 0x00,
0x00, 0x03, 0x03, 0x01, 0x50, 0x5C, 0x44, 0x04, 0x08, 0x01, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0x00,
0x83, 0x7C, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00,
0x00, 0x00, 0x1F, 0x78, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00,
0x00, 0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x80, 0xC0, 0x70, 0x30, 0x20, 0x30, 0x30, 0x10, 0x1C, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0xF8,
0x87, 0x80, 0xC0, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00,
0x00, 0x00, 0x00, 0x00, 0x7F, 0xC7, 0x1E, 0xF8, 0xB0, 0x30, 0x20, 0x60, 0xC0, 0xC0, 0x80, 0x80,
0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
0x80, 0x80, 0x80, 0x80, 0xC0, 0xC0, 0x40, 0x60, 0x60, 0x30, 0x30, 0x10, 0x18, 0x0C, 0x06, 0x03,
0x81, 0x80, 0x40, 0x40, 0x60, 0x20, 0x30, 0x10, 0x18, 0x08, 0x0C, 0x04, 0x06, 0x02, 0x83, 0x81,
0xC1, 0x40, 0x60, 0x20, 0x30, 0x10, 0x18, 0x08, 0x0C, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const uint8_t partyFrame4 [] PROGMEM = {
0x80, 0x40, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0xC0, 0xF0, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80,
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0,
0x60, 0x20, 0xFE, 0x03, 0x00, 0xFF, 0x01, 0x00, 0xFF, 0x01, 0x00, 0x01, 0xFF, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0x00, 0x00, 0x00, 0xE0, 0x30, 0x10, 0x60, 0xE0, 0xA0,
0xB0, 0x90, 0xFE, 0xFF, 0xB5, 0xCF, 0xFF, 0xFE, 0xF2, 0x73, 0xD9, 0xB9, 0xF9, 0xD8, 0xF9, 0xD8,
0xB8, 0xB8, 0xF8, 0xD8, 0x78, 0xD8, 0x78, 0xB0, 0x71, 0xF1, 0x61, 0xE1, 0x61, 0xC1, 0xC3, 0xE2,
0xF2, 0x7E, 0xAF, 0xDB, 0xFF, 0x7C, 0x10, 0x20, 0x40, 0xC0, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x7F,
0x00, 0x00, 0xFF, 0x00, 0x08, 0x0F, 0x0C, 0x88, 0x8F, 0x18, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x78, 0x0C, 0xE6,
0x3F, 0x03, 0xFE, 0xB8, 0x87, 0x01, 0x00, 0x03, 0x06, 0x0C, 0x0B, 0x0C, 0x08, 0x00, 0x00, 0x00,
0x00, 0x01, 0x01, 0x01, 0x01, 0x03, 0x01, 0x03, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x83, 0x83, 0x43, 0x87, 0x06, 0x07, 0x0D, 0x0F, 0x1F, 0x1E,
0x3D, 0x7F, 0xDE, 0xFF, 0xBB, 0x70, 0xE0, 0xC0, 0x80, 0x00, 0x01, 0x02, 0x3C, 0xC0, 0x1F, 0x60,
0xC0, 0x80, 0x80, 0x80, 0x18, 0x3F, 0x03, 0x00, 0x00, 0xC0, 0x70, 0x1C, 0x07, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x0F, 0x00, 0x60, 0x3F,
0x20, 0x20, 0x3E, 0x23, 0x7F, 0x46, 0xCC, 0x88, 0x88, 0x10, 0x10, 0xF8, 0x30, 0x30, 0x60, 0x60,
0xE0, 0x80, 0xE0, 0x80, 0xA0, 0xA0, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x90, 0x90, 0x10, 0x08,
0x88, 0x04, 0x84, 0x86, 0x82, 0x81, 0xC1, 0xC0, 0x40, 0x63, 0x2C, 0x30, 0x60, 0x80, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x06, 0x0D, 0x1F, 0x16, 0xE0, 0x20, 0x00, 0x01, 0x07, 0xF8,
0x00, 0x18, 0xFC, 0xFF, 0xC7, 0x86, 0xB4, 0xB2, 0x87, 0xFF, 0x7C, 0x30, 0x10, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xC0, 0x00, 0x00, 0x00,
0x7C, 0x86, 0x03, 0x31, 0xFC, 0xCF, 0x61, 0xA1, 0x94, 0x99, 0x07, 0x03, 0x34, 0x48, 0x78, 0x30,
0xB0, 0x70, 0x18, 0x18, 0x85, 0x88, 0x84, 0x86, 0x8C, 0x00, 0x00, 0x00, 0x01, 0x89, 0x99, 0x71,
0x63, 0x61, 0xE1, 0x61, 0x61, 0x60, 0xE0, 0x20, 0x30, 0x10, 0x18, 0x18, 0x04, 0x01, 0x02, 0x02,
0x02, 0x7C, 0x82, 0x82, 0xC2, 0x42, 0x7E, 0x3F, 0x33, 0x7F, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x0F,
0xF8, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0x00, 0x00,
0x00, 0x01, 0x00, 0xFE, 0x0F, 0x3F, 0x7E, 0x3F, 0x1F, 0x0F, 0x07, 0x00, 0x00, 0x80, 0xC0, 0x78,
0x2E, 0x7A, 0xC1, 0xC1, 0x40, 0x67, 0x78, 0xC0, 0xC1, 0x41, 0x3F, 0x26, 0x3C, 0x00, 0x00, 0x00,
0x00, 0x06, 0x03, 0x00, 0x18, 0x3E, 0x7F, 0xFE, 0xFC, 0xF8, 0xFE, 0xFF, 0x7F, 0x3F, 0x1E, 0x00,
0x00, 0x00, 0x01, 0x01, 0x00, 0x28, 0x2E, 0x22, 0x02, 0x04, 0x00, 0xFF, 0x7E, 0x00, 0x00, 0x00,
0x83, 0x7C, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
0x00, 0x00, 0x00, 0xFF, 0x3C, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x80, 0xC0, 0x60, 0x38, 0x18, 0x10, 0x18, 0x18, 0x08, 0x0E, 0x03, 0x01, 0x00, 0x00, 0x00, 0xF8,
0x07, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0xFF, 0x01, 0x03, 0x0F, 0x7C, 0xD8, 0x18, 0x10, 0x30, 0x60, 0x60, 0x40,
0x40, 0xC0, 0xC0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
0xC0, 0xC0, 0xC0, 0x40, 0xC0, 0xE0, 0x60, 0x20, 0x30, 0x30, 0x18, 0x18, 0x08, 0x0C, 0x06, 0x03,
0x01, 0x80, 0x80, 0x80, 0xC0, 0x40, 0x40, 0x60, 0x20, 0x30, 0x10, 0x08, 0x08, 0x0C, 0x04, 0x07,
0x82, 0x82, 0x81, 0x81, 0x40, 0x40, 0x20, 0x20, 0x10, 0x0C, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const uint8_t partyFrame5 [] PROGMEM = {
0x80, 0x40, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x0F, 0x00, 0xC0, 0x7F,
0x40, 0x40, 0x7F, 0x41, 0xF8, 0x0E, 0x03, 0x06, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xC0, 0xF0, 0xFC, 0x6C,
0xFC, 0xC0, 0x60, 0x20, 0x30, 0x10, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x30, 0x10, 0x10, 0x30,
0x20, 0x20, 0x20, 0x60, 0x20, 0x60, 0x40, 0x40, 0x80, 0x00, 0x00, 0x80, 0xF0, 0x60, 0xC0, 0x80,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x80, 0x00, 0x00, 0x00,
0xFC, 0x0C, 0x06, 0x02, 0x03, 0x00, 0x00, 0x80, 0x7F, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18, 0x06,
0x01, 0x0F, 0x70, 0x40, 0xD8, 0x27, 0xC0, 0x07, 0x0C, 0x12, 0x13, 0x30, 0x3F, 0x3F, 0x3E, 0x77,
0x3A, 0x7F, 0x3E, 0x36, 0x2E, 0x3A, 0x17, 0x3B, 0x3F, 0x33, 0x3F, 0x2B, 0x37, 0x7E, 0x3F, 0x76,
0x7E, 0xCE, 0xFE, 0xDC, 0xAC, 0x58, 0x78, 0xF0, 0xF0, 0xF9, 0xDD, 0x77, 0xBF, 0xFC, 0x7F, 0x0F,
0x08, 0x10, 0x10, 0x70, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x06, 0x0C, 0xF8,
0x00, 0x00, 0x00, 0x38, 0xE8, 0x0C, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x3C, 0xE0,
0x80, 0x40, 0x80, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x60,
0x30, 0x08, 0x1C, 0xE0, 0x01, 0x01, 0x03, 0x02, 0x07, 0x0A, 0x0F, 0x1B, 0x3F, 0x7F, 0xFF, 0xDE,
0x78, 0xF0, 0xE0, 0x80, 0x00, 0x03, 0x0E, 0xB0, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
0x00, 0x00, 0x00, 0x00, 0x7F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0x3C,
0x1B, 0x58, 0x90, 0xB1, 0xFD, 0x47, 0x82, 0x06, 0x0E, 0x0C, 0x1C, 0x14, 0x96, 0xB2, 0x96, 0xC4,
0x46, 0xC2, 0x02, 0x02, 0x02, 0x1A, 0x32, 0x63, 0x63, 0x31, 0x61, 0x21, 0x70, 0x20, 0x30, 0x30,
0x18, 0x10, 0x18, 0x04, 0x05, 0x0E, 0x90, 0x30, 0x60, 0x40, 0x40, 0x40, 0xC0, 0x40, 0xC0, 0x41,
0xC3, 0x80, 0x63, 0xE7, 0xB4, 0x1C, 0x00, 0x00, 0x07, 0xB8, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0xF8, 0xEC,
0xF6, 0xFB, 0xF9, 0x71, 0x00, 0x0A, 0x09, 0x05, 0x83, 0x5A, 0xEE, 0x23, 0x31, 0x11, 0xF0, 0x08,
0x18, 0x10, 0x31, 0xE0, 0xC0, 0x80, 0x11, 0x13, 0x1E, 0x0C, 0xCC, 0x78, 0x1C, 0x08, 0x98, 0xFC,
0x84, 0x04, 0x06, 0x82, 0xC3, 0xC3, 0xC0, 0x80, 0x00, 0x00, 0x16, 0x29, 0x60, 0x20, 0x38, 0x0F,
0x0F, 0xE9, 0x3F, 0x1F, 0xF3, 0x0C, 0x04, 0xFC, 0x18, 0x31, 0xEE, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xE7, 0x00, 0x03, 0x07,
0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x18, 0x06, 0x0F, 0x02, 0x07, 0x2C, 0x18, 0x08, 0x07, 0x0C,
0x38, 0x08, 0x08, 0x07, 0x04, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x0F, 0x1F,
0x3F, 0x7F, 0xFE, 0x7F, 0x3F, 0x1F, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x30, 0x10,
0xFF, 0x01, 0x00, 0xF0, 0x0F, 0x00, 0xE0, 0x1F, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x3F, 0x20, 0x60, 0x40, 0x40, 0x40, 0xC3, 0xCF, 0x98, 0xF0,
0x60, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x60, 0x30, 0x10, 0x0C, 0xFA, 0x1F, 0x00, 0x00,
0x7F, 0x00, 0x00, 0x87, 0x86, 0xC4, 0x27, 0x06, 0x04, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
0x06, 0x06, 0x0C, 0x0C, 0x18, 0x18, 0x10, 0x30, 0x60, 0x60, 0xC0, 0xC0, 0x80, 0x80, 0x81, 0x03,
0x03, 0x04, 0x06, 0x05, 0x0F, 0x0A, 0x0C, 0x1C, 0x14, 0x38, 0x28, 0x38, 0x58, 0xD0, 0x90, 0x10,
0xF0, 0x30, 0x30, 0x10, 0x30, 0x10, 0x90, 0xF0, 0x30, 0x18, 0x18, 0x08, 0x08, 0x0C, 0x0C, 0x0C,
0x04, 0x02, 0x02, 0x02, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1C, 0x30, 0x60,
0x40, 0xC0, 0x8C, 0x9F, 0x00, 0x80, 0x40, 0xE0, 0x30, 0x1C, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void *frames[] = {partyFrame1, partyFrame2, partyFrame3, partyFrame4, partyFrame5};
