#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

static volatile unsigned long milliseconds = 0;

void timer0_init(void) {
    // set timer0 to CTC mode
    TCCR0A = (1 << WGM01);

    // prescaler of 64
    TCCR0B = (1 << CS01) | (1 << CS00);

    // compare match every 1 ms
    OCR0A = (F_CPU / 64 / 1000) - 1;

    // enable output compare match A interrupt
    TIMSK0 |= (1 << OCIE0A);

    // enable global interupts
    sei();
}

ISR(TIMER0_COMPA_vect) {
    milliseconds++;
}

unsigned long millis(void) {
    unsigned long ms;

    // disable interrupts to prevent data corruption
    cli();
    ms = milliseconds;
    sei();
    return ms;
}


