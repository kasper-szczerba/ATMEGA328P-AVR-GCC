#include "../Inc/hardware.h"

void Set_Pin_Mode(volatile unsigned char *dataDirectionRegister, unsigned char pin, unsigned char mode)
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

void Digital_Write(volatile unsigned char *portRegister, unsigned char pin, unsigned char state)
{
    if (state == HIGH)
    {
        // Set pin high
        *portRegister |= (ONE << pin);
    }
    else if (state == LOW)
    {
        // Set pin low
        *portRegister &= ~(ONE << pin);
    }
}

unsigned char Digital_Read(volatile unsigned char *portRegister, unsigned char pin)
{
    // Read pin state
    return (*portRegister & (ONE << pin)) != ZERO;
}

void ADC_Init() {
    // Set reference voltage (AVCC) and left-adjust result
    ADMUX = (ONE << SIXTH_BIT) | (ONE << FIFTH_BIT);

    // Enable ADC and set prescaler (128)
    ADCSRA = (ONE << SEVENTH_BIT) | (ONE << SECOND_BIT) | (ONE << FIRST_BIT) | (ONE << ZERO);
}

unsigned int ADC_Read(unsigned char channel) {
    // Clear the channel bits from the ADMUX register
    ADMUX &= 0xF0;
    // Set the new channel
    ADMUX |= (channel & 0x0F);

    // Start conversion
    ADCSRA |= (ONE << SIXTH_BIT);

    // Wait for conversion to complete
    while (ADCSRA & (ONE << SIXTH_BIT));

    // Return ADC result
    return ADCL;
}