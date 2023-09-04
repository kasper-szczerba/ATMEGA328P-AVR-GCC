#ifndef HARDWARE_H
#define HARDWARE_H

#include "basic.h"

// Register definitions for the ATmega328P

// Port definitions for the ATmega328P
#define PORTB *((volatile uint8_t *)0x25)
#define PORTC *((volatile uint8_t *)0x28)
#define PORTD *((volatile uint8_t *)0x2B)

// Data Direction Registers
#define DDRB *((volatile uint8_t *)0x24)
#define DDRC *((volatile uint8_t *)0x27)
#define DDRD *((volatile uint8_t *)0x2A)

// Pin Input Registers
#define PINB *((volatile uint8_t *)0x23)
#define PINC *((volatile uint8_t *)0x26)
#define PIND *((volatile uint8_t *)0x29)

// ADC Registers
#define ADMUX *((volatile uint8_t *)0x7C)
#define ADCSRA *((volatile uint8_t *)0x7A)
#define ADCL *((volatile uint8_t *)0x78)

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
void Set_Pin_Mode(volatile uint8_t *dataDirectionRegister, uint8_t pin, uint8_t mode);
void Digital_Write(volatile uint8_t *portRegister, uint8_t pin, uint8_t state);
uint8_t Digital_Read(volatile uint8_t *portRegister, uint8_t pin);
void ADC_Init();
unsigned int ADC_Read(uint8_t channel);

#endif // HARDWARE_H