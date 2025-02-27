/* lcd1602.h
 *
 * lcd1602 interface
 */

#ifndef lcd1602_h
#define lcd1602_h

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint8_t LcdChar;

typedef enum
{
    lcdChar_cgram0,  // custom character 0
    lcdChar_cgram1,  // custom character 1
    lcdChar_cgram2,  // custom character 2
    lcdChar_cgram3,  // custom character 3
    lcdChar_cgram4,  // custom character 4
    lcdChar_cgram5,  // custom character 5
    lcdChar_cgram6,  // custom character 6
    lcdChar_cgram7,  // custom character 7
    lcdChar_cgram8,  // custom character 8
    lcdChar_cgram9,  // custom character 9
    lcdChar_cgramA,  // custom character A
    lcdChar_cgramB,  // custom character B
    lcdChar_cgramC,  // custom character C
    lcdChar_cgramD,  // custom character D
    lcdChar_cgramE,  // custom character E
    lcdChar_cgramF,  // custom character F

    lcdChar_space,   // ' '
} LcdCharType;

void lcd1602_init(void);

void lcd1602_enable(bool enable);

void lcd1602_writeLine(uint8_t line, char* buf, size_t bufSize);

void lcd1602_writeChar(uint8_t line, uint8_t pos, char c);

void lcd1602_writeLineRaw(uint8_t line, LcdChar* buf, size_t bufSize);

void lcd1602_writeRaw(uint8_t line, uint8_t pos, LcdChar c);

#endif // !lcd1602_h
