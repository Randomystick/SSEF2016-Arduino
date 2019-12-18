#include "pitches.h"


int melody[] = {NOTE_A3, NOTE_F4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_C4, NOTE_A3, NOTE_B3, NOTE_C4, NOTE_D4, NOTE_B3, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_C5, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_D4};
int noteDurations[] = {2,4,4,4,4,2,2,2,2,2,2,4,4,4,4,2,2,2,2,2};
void setup(){

}


void loop()
{
  for (int thisNote = 0; thisNote < 20; thisNote++)
  {
    int noteDuration = 850/noteDurations[thisNote];
    tone(3, melody[thisNote],noteDuration);
    delay(noteDuration*1.1);
  }

}
