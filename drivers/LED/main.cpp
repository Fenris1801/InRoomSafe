#include <avr/io.h>
#include <util/delay.h>
#include "LED/led.h"

unsigned char Delay (unsigned long a);

#define redLed _BV(PD2)

int main(void)
{
    ledInit(redLed);
    
    while(true)
    {  
      toggleLed(redLed);
      Delay(350000); 
    }
}

unsigned char Delay (unsigned long a) 
{
    volatile unsigned long b;
    for(b=0;b<a;b++){
    };
    return 1;
}