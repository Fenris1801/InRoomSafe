#include <avr/io.h>
#include "loudness.h"

void loudnessInit(unsigned char channel)
{
    DDRC &= ~_BV(channel);  // broche A<channel> en entree (A0..A5 = PC0..PC5)
    PORTC &= ~_BV(channel); // pas de pull-up : elle fausserait la mesure
    DIDR0 |= _BV(channel);  // coupe l'entree numerique de la broche (moins de bruit)

    ADMUX = _BV(REFS0);                              // reference = 5 V (AVcc)
    ADCSRA = _BV(ADEN)                               // active l'ADC
             | _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0); // horloge ADC = 16 MHz / 128 = 125 kHz
}

unsigned int loudnessRead(unsigned char channel)
{
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F); // choisit l'entree A<channel>
    ADCSRA |= _BV(ADSC);                       // lance une conversion
    while (ADCSRA & _BV(ADSC))                 // attend la fin (~100 us)
    {
    }
    return ADC; // resultat sur 10 bits
}

unsigned char soundDetected(unsigned char channel, unsigned int threshold)
{
    return loudnessRead(channel) > threshold;
}
