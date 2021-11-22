/* Playmelody versie 3
 In deze versie hebben al die frequenties echte namen gekregen. Dat is zo'n lange lijst, die wil je niet in je programma hebben. Die staat in een apart bestandje pitches.h
 Dat wordt in het programma opgenomen door de regel #include "pitches.h"
 Het blokje void melodietje is nu veel makkelijker leesbaar geworden. 
 De buzzer wordt op pen 13 aangesloten. Let op + (pin 13) en - (Gnd) 
 */
 

#include "pitches.h" //Hierin wordt een lange lijst van tonen gedefinieerd. Ze staan in een tweede tabblad.

void setup () { // Hier staat helemaal niets...
} 

void loop()
{
  melodietje();  // Speel het melodietje dat hieronder is gedefinieerd.
} // End loop


void  melodietje(){
  
  int tijdsduur=750;
  tone(13, NOTE_G4,tijdsduur/4); //G4
  delay(1.3*tijdsduur/4);  

  tone(13, NOTE_C5,tijdsduur/4); //C5  
  delay(1.3*tijdsduur/8);    

  tone(13, NOTE_E5,tijdsduur/4); //E5                                                    
  delay(1.3*tijdsduur/8);   

  tone(13, NOTE_G5,tijdsduur/3); //G5
  delay(1.3*tijdsduur/4);   

  tone(13, NOTE_E5,tijdsduur/4); //E5
  delay(1.3*tijdsduur/4);  

  tone(13, NOTE_G5,tijdsduur/1); //G5
  delay(1.3*tijdsduur/1);  
}




