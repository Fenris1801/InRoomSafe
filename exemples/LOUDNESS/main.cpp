#include <avr/io.h>
#include <util/delay.h>
#include "LOUDNESS/loudness.h"
#include "LED/led.h"

#define loudnessChannel 0
#define threshold 180 // seuil de 0 a 1023
#define redLed _BV(PD4)

int main(void)
{
  loudnessInit(loudnessChannel);
  ledInit(redLed);

  while (true)
  {
    switchLedOnOff(redLed, soundDetected(loudnessChannel, threshold));
    _delay_ms(10);
  }
}
