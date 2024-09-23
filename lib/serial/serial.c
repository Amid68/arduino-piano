#include <avr/io.h>
#include <stdlib.h>
#include "serial.h"

void serial_init(unsigned long baudrate) {
    unsigned int ubrr = F_CPU / 16 / baudrate - 1;
    UBRR0H = (unsigned char)(ubrr >> 8);
    UBRR0L = (unsigned char)(ubrr);
    UCSR0B = (1 << TXEN0);  // enable transmitter
    UCSR0C = (3 << UCSZ00); // 8 data bits, 1 stop bit
}

void serial_transmit(char data) {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = data;
}

void serial_print(const char *str) {
    while (*str) {
        serial_transmit(*str++);
    }
}

void serial_println(const char *str) {
    serial_print(str);
    serial_transmit('\r');
    serial_transmit('\n');
}

void serial_print_int(int value) {
    char buffer[10];
    itoa(value, buffer, 10);
    serial_print(buffer);
}


