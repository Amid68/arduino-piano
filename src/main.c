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
        uint8_t tone_played = 0;

        for (uint8_t i = 0; i < NUM_BUTTONS; i++) {
            if (button_pressed(i)) {
                play_tone(frequencies[i]);
                serial_print("Button on pin ");
                serial_print_int(button_pins[i]);
                serial_print(" pressed. Playing note ");
                serial_println(note_names[i]);
                tone_played = 1;
                unsigned long start_time = millis();
                
                while (millis() - start_time < TONE_DURATION_MS) { 
                    // wait for the tone duration
                }

                stop_tone();
                break;
            }
        }

        if (!tone_played) {
            stop_tone();
        }

        delay_ms(DELAY_MS);
    }

    return 0;
}









