#include <avr/io.h>
#include <util/delay.h>
#include <util/delay_basic.h>
#include "buzzer.h"

// _delay_ms veut une constante : on boucle sur 1 ms pour une duree variable
static void waitMs(unsigned int ms)
{
    while (ms--)
        _delay_ms(1);
}

void buzzerInit(unsigned char buzzer)
{
    DDRD |= buzzer;
    PORTD &= ~buzzer;
}

void mksound(unsigned char buzzer, unsigned int freqHz, unsigned int durationMs)
{
    if (freqHz == 0 || durationMs == 0)
        return;

    unsigned long loops = F_CPU / (8UL * freqHz);
    if (loops > 0xFFFF)
        loops = 0xFFFF;

    unsigned long toggles = (unsigned long)freqHz * durationMs * 2UL / 1000UL;

    while (toggles--)
    {
        PORTD ^= buzzer;
        _delay_loop_2((unsigned int)loops);
    }

    PORTD &= ~buzzer;
}

void playMelody(unsigned char buzzer, const Note melody[], unsigned char length)
{
    for (unsigned char i = 0; i < length; i++)
    {
        if (melody[i].freq == 0)
            waitMs(melody[i].durationMs);
        else
            mksound(buzzer, melody[i].freq, melody[i].durationMs);
    }
}
