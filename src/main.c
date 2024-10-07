#include <avr/io.h>
#include "../include/definitions.h"
#include "../lib/serial/serial.h"
#include "../lib/io/io.h"
#include "../lib/tone/tone.h"
#include "../lib/delay/delay.h"
#include "../lib/timer/timer.h"

int main(void) {
    // initialize serial communication
    serial_init(9600);

    // initialize I/O
    io_init();

    //initialize timer0 for millis()
    timer0_init();

    while(1) {
        uint8_t button_pressed_index = NUM_BUTTONS;  // No button is pressed initially

        // Check if any button is pressed
        for (uint8_t i = 0; i < NUM_BUTTONS; i++) {
            if (button_pressed(i)) {
                button_pressed_index = i;  // Record the pressed button index
                break;
            }
        }

        // If a button is pressed, play the corresponding tone
        if (button_pressed_index < NUM_BUTTONS) {
            play_tone(frequencies[button_pressed_index]);
            serial_print("Button on pin ");
            serial_print_int(button_pins[button_pressed_index]);
            serial_print(" pressed. Playing note ");
            serial_println(note_names[button_pressed_index]);
        } else {
            // If no button is pressed, stop the tone
            stop_tone();
        }

        delay_ms(DELAY_MS);
    }

    return 0;
}









