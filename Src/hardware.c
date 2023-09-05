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
    ADMUX = (ONE << SIXTH_BIT) | (ONE << FIFTH_BIT); // 0110 0000

    // Enable ADC and set prescaler (4)
    ADCSRA = (ONE << SEVENTH_BIT) | (ONE << FIRST_BIT); // 1000 0100
}

uint16_t ADC_Read(uint8_t channel) {
    // Clear the channel bits from the ADMUX register
    ADMUX &= 0xF0; //1111 0000 set to 0

    // Set the new channel
    ADMUX |= (channel & 0x0F); // 0000 1111 set to 1

    // Start conversion
    ADCSRA |= (ONE << SIXTH_BIT);

    // Wait for conversion to complete
    while (ADCSRA & (ONE << SIXTH_BIT));

    // Return ADC result (combine ADCH and ADCL)
    uint16_t result = ADCL;
    result |= (uint16_t)(ADCH << 8);
    return result;
}