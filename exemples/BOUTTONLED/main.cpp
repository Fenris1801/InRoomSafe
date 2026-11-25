#include <avr/io.h>
#include <util/delay.h>
#include "LED/led.h"
#include "BUTTON/button.h"

unsigned char Delay(unsigned long a);

#define bluebtn _BV(PD3)
#define redLed _BV(PD2)

int main(void)
{

  btnInit(bluebtn);
  ledInit(redLed);

  while (true)
  {
    if (btnIsPressed(bluebtn) == 1)
      toggleLed(redLed);
  }
}

unsigned char Delay(unsigned long a)
{
  volatile unsigned long b;
  for (b = 0; b < a; b++)
  {
  };
  return 1;
}