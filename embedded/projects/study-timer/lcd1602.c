#include "lcd1602.h"

void lcd1602_init(void) { }

void lcd1602_enable(bool enable)
{
}

void lcd1602_writeLine(uint8_t line, char* buf, size_t bufSize) { }

void lcd1602_writeChar(uint8_t line, uint8_t pos, char c) { }

void lcd1602_writeLineRaw(uint8_t line, LcdChar* buf, size_t bufSize) { }

void lcd1602_writeRaw(uint8_t line, uint8_t pos, LcdChar c) { }
