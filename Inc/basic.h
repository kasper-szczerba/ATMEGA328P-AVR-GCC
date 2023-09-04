#ifndef BASIC_H
#define BASIC_H

#define ZERO 0
#define ONE 1

#define OSC_FREQ 16000
#define OSC_PRESCALER 64

// Boolean type
typedef enum {
    false,
    true
} bool;

// Integer types
typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;

// Function prototypes
void Delay_Ms(unsigned long ms);

#endif