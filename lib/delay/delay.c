#include <util/delay.h>
#include "delay.h"

void delay_ms(unsigned long ms) {
    while (ms) {
        _delay_ms(1);
        ms--;
    }
}


