#ifndef HARDWARE_H
#define HARDWARE_H

// Register definitions for the ATmega328P

// Port definitions for the ATmega328P
#define PORTB *((volatile unsigned char *)0x25)
#define PORTC *((volatile unsigned char *)0x28)
#define PORTD *((volatile unsigned char *)0x2B)

// Data Direction Registers
#define DDRB *((volatile unsigned char *)0x24)
#define DDRC *((volatile unsigned char *)0x27)
#define DDRD *((volatile unsigned char *)0x2A)

// Pin Input Registers
#define PINB *((volatile unsigned char *)0x23)
#define PINC *((volatile unsigned char *)0x26)
#define PIND *((volatile unsigned char *)0x29)

// Bit definitions
#define FIRST_BIT (1)
#define SECOND_BIT (2)
#define THIRD_BIT (3)
#define FOURTH_BIT (4)
#define FIFTH_BIT (5)
#define SIXTH_BIT (6)
#define SEVENTH_BIT (7)
#define EIGHTH_BIT (8)

// Pin states
#define LOW 0
#define HIGH 1

// Pin modes
#define INPUT 0
#define OUTPUT 1

// Function prototypes
void setPinMode(volatile unsigned char *dataDirectionRegister, unsigned char pin, unsigned char mode);
void digitalWrite(volatile unsigned char *portRegister, unsigned char pin, unsigned char state);
unsigned char digitalRead(volatile unsigned char *portRegister, unsigned char pin);

#endif // HARDWARE_H