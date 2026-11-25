#ifndef BUZZER_h
#define BUZZER_h

struct Note
{
    unsigned int freq;
    unsigned int durationMs;
};

void buzzerInit(unsigned char buzzer);
void mksound(unsigned char buzzer, unsigned int freqHz, unsigned int durationMs);
void playMelody(unsigned char buzzer, const Note melody[], unsigned char length);

#endif // BUZZER_h
