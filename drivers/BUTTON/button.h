#ifndef BUTTON_h
#define BUTTON_h

#include <avr/io.h>

void btnInit(unsigned char btn);
unsigned char btnIsPressed(unsigned char btn);

#endif // BUTTON_h
