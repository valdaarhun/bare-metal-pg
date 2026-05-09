#define F_CPU 16000000U

#include <avr/io.h>
#include <util/delay.h>

int main() {
    DDRB = DDRB | (1 << DDB5);

    while(1) {
        PORTB |= (1 << PORTB5);
        _delay_ms(150);
        PORTB &= ~(1 << PORTB5);
        _delay_ms(1000);
    }
}