#include "../Inc/basic.h"

void Delay_Ms(unsigned long ms) {
    unsigned long cycles = ms * OSC_FREQ / OSC_PRESCALER;

    for (volatile unsigned long i = ZERO; i < cycles; i++) {
        // Do nothing
    }
}