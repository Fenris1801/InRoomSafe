#ifndef LOUDNESS_h
#define LOUDNESS_h

void loudnessInit(unsigned char channel);
unsigned int loudnessRead(unsigned char channel);
unsigned char soundDetected(unsigned char channel, unsigned int threshold);

#endif // LOUDNESS_h
