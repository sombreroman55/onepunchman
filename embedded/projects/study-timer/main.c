/* main.c
 *
 * Main entry point
 */

#include "lcd1602.h"

#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <util/delay.h>

#define BAUD_RATE 9600
#define UBRR_VAL F_CPU / 16 / BAUD_RATE - 1

typedef enum {
    ts_init,
    ts_time_adjust,
    ts_running,
    ts_paused,
} TimerState;

typedef enum {
    te_none,
    te_cw,
    te_ccw,
    te_press
} TimerEvent;

static TimerEvent ev = te_none;
static uint32_t time_s = 0;
static uint32_t adj_time_s = 0;

void rotary_init()
{
    PORTD |= (1 << PD5);
    PORTD |= (1 << PD4);
    PORTD |= (1 << PD3);
    asm("nop");
    asm("nop");
}

void led_buzzer_init(void)
{
    DDRD |= (1 << DDD6);
}

void usart_init(uint16_t ubrr)
{
    UBRR0H = (ubrr >> 8) & 0xFF;
    UBRR0L = ubrr & 0xFF;
    UCSR0B |= (1 << TXEN0);
}

void usart_putchar(char c)
{
    while (!(UCSR0A & (1 << UDRE0))) {
        ; // wait for ready
    }
    UDR0 = c;
}

void usart_debug(char* msg)
{
    size_t len = strlen(msg);
    for (int i = 0; i < len; i++) {
        usart_putchar(msg[i]);
    }
}

void handle_event(TimerEvent te)
{
    static TimerState state = ts_init;
    switch (state) {
    case ts_init:
        break;
    case ts_time_adjust:
        break;
    case ts_running:
        break;
    case ts_paused:
        break;
    }
}

int main()
{
    rotary_init();
    lcd1602_init();
    led_buzzer_init();
    usart_init(UBRR_VAL);

    char debug[64] = { 0 };

    usart_debug("Hello world!\r\n");
    for (;;) {
        bool press = (PIND & (1 << PIND3)) == 0;
        if (press) {
            _delay_ms(80);
            bool debounce = (PIND & (1 << PIND3)) == 0;
            if (debounce) {
            }
        }
        _delay_ms(1);
    }

    return 0;
}
