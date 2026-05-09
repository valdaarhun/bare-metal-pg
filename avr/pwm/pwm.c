#define F_CPU 16000000U

#include <avr/io.h>
#include <avr/sfr_defs.h>

int main() {
    /*
     * Pins 5 and 6 can be used for PWN with Timer0.
     * See Fig.1-1 of ATmega328P's data sheet and
     * Arduino UNO3 pinout schematic.
     */
    // Configure Timer0
    TCCR0A |= _BV(COM0A1) | _BV(WGM01) | _BV(WGM00); // Set fast-PWM and set pin 6 to low on compare match
    TCCR0B |= _BV(CS02); // Prescalar = 256
    OCR0A = 32; // Compare value set to 63 (approx. 12.5% duty cycle)

    // Set up pin 6
    DDRD |= _BV(DDD6); // Pin 6 is OC0A
    PORTD |= _BV(PORTD6);

    // Control
    DDRB |= _BV(DDB0); // Pin 8
    PORTB |= _BV(PORTB0);

    while(1) {
        ;
    }
}
