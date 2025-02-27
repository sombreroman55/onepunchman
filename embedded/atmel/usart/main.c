#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define BAUD 9600
#define UBRR F_CPU/16/BAUD-1

static uint8_t txbuf[] = "abcdefghijklmnopqrstuvwxyz\r\n";
static size_t sz = sizeof(txbuf);
static int txi = 0;

ISR(USART_UDRE_vect) {
    if (txi >= sz) {
        UCSR0B &= ~(1 << UDRIE0);
        return;
    }
    UDR0 = txbuf[txi++];
}

void my_print(void)
{
    UCSR0B |= (1 << UDRIE0);
}

void usart_init(void)
{
    // UCSR0C default state is what we want already

    // Set the baud rate to 9600
    UBRR0 = UBRR;

    // Enable tx only for now
    UCSR0B = (1 << TXEN0);

    // Use interrupts this time
    SREG |= (1 << SREG_I);
}

int main()
{
    usart_init();
    my_print();
    for(;;) {_delay_ms(1);}
    return 0;
}
