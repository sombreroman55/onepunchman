#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>


void pwm_init(void)
{
    DDRD |= (1 << DDD6);
    TCCR0A |= (1 << COM0A1);
    TCCR0A |= (1 << WGM01);
    TCCR0A |= (1 << WGM00);
    TCCR0B |= (1 << CS00);
}

void pwm_update(uint8_t val)
{
    OCR0A = val;
}

void adc_init(void)
{
    ADCSRA |= (1 << ADEN);
    ADMUX  |= (1 << REFS0);
    ADMUX |= (1 << ADLAR);
}

uint8_t adc_read(uint8_t channel)
{
    ADMUX  |= (channel & 0x0F);
    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1 << ADSC)) {
        ; // wait for conversion
    }
    uint8_t v = ADCH;
    return v;
}

int main(int argc, char* argv[])
{
    pwm_init();
    adc_init();
    pwm_update(0);
    for (;;) {
        _delay_ms(1);
        uint8_t reading = adc_read(0);
        pwm_update(reading);
    }
    return 0;
}
