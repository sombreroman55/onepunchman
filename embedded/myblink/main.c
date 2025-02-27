/* myblinky
 *
 * A completely bare-metal implementation of a simple
 * Arduino Uno blink program of the on-board LED.
 * No non-standard libraries, no external headers,
 * just the datasheet
 */

#include <stdint.h>

#define REG(r) (*(volatile uint8_t*)(r))
#define REG16(r) (*(volatile uint16_t*)(r))

int main() { return 0; }
