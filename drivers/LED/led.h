#ifndef LED_h
#define LED_h

#include <avr/io.h>

void ledInit(unsigned char led);
void switchLedOnOff(unsigned char led, unsigned char onOff);
void toggleLed(unsigned char led);

#endif // LED_h