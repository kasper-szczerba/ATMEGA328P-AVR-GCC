#ifndef BASIC_H
#define BASIC_H

#define ZERO 0
#define ONE 1

#define OSC_FREQ 16000
#define OSC_PRESCALER 64

typedef enum {
    false,
    true
} bool;

// Function prototypes
void delayMs(unsigned long ms);

#endif