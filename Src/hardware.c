#include "../Inc/hardware.h"

void setPinMode(volatile unsigned char *dataDirectionRegister, unsigned char pin, unsigned char mode)
{
    if (mode == OUTPUT)
    {
        // Set pin as output
        *dataDirectionRegister |= (1 << pin);
    }
    else if (mode == INPUT)
    {
        // Set pin as input
        *dataDirectionRegister &= ~(1 << pin);
    }
}

void digitalWrite(volatile unsigned char *portRegister, unsigned char pin, unsigned char state)
{
    if (state == HIGH)
    {
        // Set pin high
        *portRegister |= (1 << pin);
    }
    else if (state == LOW)
    {
        // Set pin low
        *portRegister &= ~(1 << pin);
    }
}

unsigned char digitalRead(volatile unsigned char *portRegister, unsigned char pin)
{
    // Read pin state
    return (*portRegister & (1 << pin)) != 0;
}