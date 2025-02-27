#ifndef atmega328p_h
#define atmega328p_h

#include <stdint.h>

#define REG(r) (*(volatile uint8_t*)(r))
#define REG16(r) (*(volatile uint16_t*)(r))

#define PINB REG(0x03)

#endif
