#include <avr/io.h>
#include <util/delay.h>
#include "BUZZER/buzzer.h"

#define buzzer _BV(PD5)

const Note errorSound[] = {
    {150, 150},
    {0, 60},
    {150, 150},
    {0, 60},
    {110, 700},
};

const unsigned char errorSoundLength = sizeof(errorSound) / sizeof(errorSound[0]);

int main(void)
{
  buzzerInit(buzzer);

  while (true)
  {
    playMelody(buzzer, errorSound, errorSoundLength);
    _delay_ms(2000);
  }
}
