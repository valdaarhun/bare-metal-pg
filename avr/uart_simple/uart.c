#define F_CPU 16000000U
#define BAUD 9600
#define UBRR_VAL ((F_CPU / 16 / BAUD) - 1) // Tabel 19-1 ATmega328P

#include <avr/sfr_defs.h>
#include <avr/io.h>

/* 
 * async USART by default (UMSELn <- 0)
 * Parity bit disabled (UPMn <- 0)
 * 1 stop bit (USBSn <- 0)
 * *-bit character (UCSZ0 <- 3'b011)
 */
static void init_uart() {
    UBRR0L = (unsigned char)UBRR_VAL;
    UBRR0H = (unsigned char)((UBRR_VAL >> 8) & 0xf);
    UCSR0B = _BV(TXEN0); // Enable transmitter
}

static void putc_uart(char c) {
    while (!(UCSR0A & _BV(UDRE0)));

    // Buffer is empty and can receive data for transmission
    UDR0 = c;
}

static void puts_uart(char *str, unsigned int len) {
    for (unsigned int i = 0; i < len; i++) {
        putc_uart(str[i]);
    }
}

int main() {
    char str[] = "hello\r\n";

    init_uart();
    puts_uart(str, sizeof(str));

    while(1);
}
