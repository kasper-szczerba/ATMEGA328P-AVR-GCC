#include "../Inc/hardware.h"

void Set_Pin_Mode(volatile uint8_t *dataDirectionRegister, uint8_t pin, uint8_t mode)
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

void Digital_Write(volatile uint8_t *portRegister, uint8_t pin, uint8_t state)
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

uint8_t Digital_Read(volatile uint8_t *portRegister, uint8_t pin)
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

uint16_t ADC_Read(uint8_t channel) {
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