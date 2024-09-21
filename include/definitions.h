#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__

#include <stdint.h>

#define NUM_BUTTONS 4
#define TONE_DURATION_MS 100
#define DELAY_MS 10

extern const uint8_t button_pins[NUM_BUTTONS];
extern const unsigned int frequencies[NUM_BUTTONS];
extern const char *note_names[NUM_BUTTONS];

#define SPEAKER_PIN 2

#endif
