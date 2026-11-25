#include "led.h"

void LedInit(unsigned char led)
{
    DDRD |= led;
    PORTD = 0;
}

void switchLedOnOff(unsigned char led, unsigned char onOff)
{
    if (onOff)
    {
        PORTD |= led;
    }
    else
    {
        PORTD &= ~led;
    }
}

void toggleLed(unsigned char led)
{
    PORTD ^= led;
}