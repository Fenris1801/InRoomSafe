#include "button.h"

void btnInit(unsigned char btn)
{
    DDRD &= ~btn;
    PORTD |= btn;
}

unsigned char btnIsPressed(unsigned char btn)
{
    return !(PIND & btn);
}