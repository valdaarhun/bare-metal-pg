#define F_CPU 16000000U

#include <avr/io.h>
#include <util/delay.h>

int main() {
    DDRB |= (1 << DDB4); // Arduino UNO's pin 12 is our output pin
    DDRB &= ~(1 << DDB0); // Arduino UNO's pin 8 is our input pin
    PORTB |= (1 << PORTB0); // Enable internal pull-up resistor

    while(1) {
        if (PINB & (1 << PINB0)) {
            PORTB |= (1 << PORTB4);
        } else {
            PORTB &= ~(1 << PORTB4);
        }
        _delay_ms(100);
    }
}
