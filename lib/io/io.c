#include <avr/io.h>
#inlcude "io.h"
#include "../../include/definitions.h"

void io_init(void) {
    // set speaker pin as output
    DDRD |= (1 << SPEAKER_PIN);

    // set button pins as input
    for (uint8_t i = 0; i < NUM_BUTTONS; i++) {
        DDRD &= ~(1 << button_pins[i]); // set as input
        // do not enable pull-up resistor
    }
}

uint8_t button_pressed(uint8_t button_index) {
    // read the button pin
    if (PIND & (1 << button_pins[button_index]))
        return 1;
    else
        return 0;
}


