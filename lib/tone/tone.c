#include <avr/io.h>
#include <avr/interrupt.h>
#include "tone.h"
#include "../../include/definitions.h"

void play_tone(unsigned int frequency) {
    unsigned int ocr;

    ocr = (F_CPU / (2UL * 64 * frequency)) - 1;

    // set CTC mode
    TCCR2A = (1 << WGM21);

    // set output compare register
    OCR2A = (uint8_t)ocr;

    // enable output compare match A interrupt
    TIMSK2 |= (1 << OCIE2A);

    // start timer2 with prescaler 64
    TCCR2B = (1 << CS22);

    // set speaker pin as output
    DDRD |= (1 << SPEAKER_PIN);
}

void stop_tone(void) {
    // stop timer2
    TCCR2B = 0;

    // disable output compare match A interrupt
    TIMSK2 &= ~(1 << OCIE2A);

    // clear speaker pin
    PORTD &= ~(1 << SPEAKER_PIN);
}

ISR(TIMER2_COMPA_vect) {
    // toggle speaker pin
    PORTD ^= (1 << SPEAKER_PIN);
}


