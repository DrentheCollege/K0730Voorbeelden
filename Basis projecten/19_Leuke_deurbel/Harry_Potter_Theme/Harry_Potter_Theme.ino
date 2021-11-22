/* Harry Potter Theme
*/
#include "pitches.h"
int buzzerpin = 12;

// notes in the melody:
int melody[] =
{
  NOTE_B5, NOTE_E5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_B6, NOTE_A6, NOTE_FS5, NOTE_E5, NOTE_G5,
  NOTE_FS5,  NOTE_DS5, NOTE_F5, NOTE_B4, NOTE_B4, NOTE_E5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_B6,
  NOTE_D6, NOTE_CS6, NOTE_C6, NOTE_GS6, NOTE_C6, NOTE_B6, NOTE_GS5, NOTE_GS4, NOTE_G5, NOTE_E5,
  NOTE_G5, NOTE_B6, NOTE_G5, NOTE_B6, NOTE_G5, NOTE_C6, NOTE_B5, NOTE_AS5, NOTE_FS5, NOTE_G5,
  NOTE_B5, NOTE_AS5, NOTE_AS4, NOTE_B4, NOTE_B5
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] =
{
  8, 6, 16, 8, 4, 8, 3, 3, 6, 16,
  8, 5, 4, 4, 8, 6, 16, 8, 4, 8,
  4, 8, 4, 8, 6, 16, 8, 4, 8, 3,
  8, 4, 8, 4, 8, 4, 8, 4, 8, 6,
  16, 8, 4, 8, 3
};

void setup()
{
  // iterate over the notes of the melody:
  int size = sizeof(melody) / sizeof(int);
  for (int thisNote = 0; thisNote < size; thisNote++)
  {
    // to calculate the note duration, take one second divided by the note type. e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzerpin, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 2.5;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzerpin);
  }
}

void loop()
{
  // no need to repeat the melody.
}
