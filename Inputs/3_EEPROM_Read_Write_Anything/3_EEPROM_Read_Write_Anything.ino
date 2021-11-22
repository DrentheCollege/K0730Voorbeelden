// Het schrijven en ophalen van gegevens uit EEPROM
/*
   EEPROM Read and Write Anything

   In de EEprom is geheugen voor het opslaan van het Arduino programma
   maar ook zijn er 512 "geheugenplaatssen" waar in elk een getal van 0-255 kan worden opgeslagen.
   Je kunt geen grotere getallen opslaan, geen negatieve getallen, geen komma getallen en geen karakters.
   Maar toch is zo'n EEPROM erg handig want de inhoud blijft bewaard, ook als de Arduino wordt uitgezet!
   Je kunt zelfs een andere sketch uploaden die die zelfde gegevens gaat gebruiken.
*/

#include <EEPROM.h>
#include "EEPROMAnything.h"


// Een structure kan allerlei variabelen bevatten. Zo'n structure kan in één keer opgeslagen worden.
// ----------------------------------------------------------------------------
struct
{
  long Long;        //Long variables are extended size variables for number storage, and store 32 bits (4 bytes), from -2,147,483,648 to 2,147,483,647.
  float Float;      //Datatype for floating-point numbers, a number that has a decimal point.
  //Floating-point numbers are often used to approximate analog and continuous values because they have greater resolution than integers.
  //Floating-point numbers can be as large as 3.4028235E+38 and as low as -3.4028235E+38.
  int Integer;      //Integers are your primary datatype for number storage, and store a 2 byte value. This yields a range of -32,768 to 32,767
  boolean Boolean;  //Boolean variabelen zijn false of true, 0 of 1
}
data; // De naam van de 'structure'
// ----------------------------------------------------------------------------

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Defining some values.");
  data.Long = 1234567890;
  data.Float = 12345.67890;
  data.Integer = 12345;
  data.Boolean = true;

  EEPROM_writeAnything(0, data);
  Serial.println("Writing all values as a structure to EEPROM: ");
  delay(10);

  // Delete all values;
  data.Long = 0;
  data.Float = 0;
  data.Integer = 0;
  data.Boolean = false;

  Serial.println("Erasing all values!");
  Serial.println("Reading all values from EEPROM: ");
  EEPROM_readAnything(0, data);
  Serial.print("Long integer= ");
  Serial.println(data.Long);
  Serial.print("Floating = ");
  Serial.println(data.Float, 5);
  Serial.print("Integer = ");
  Serial.println(data.Integer);
  Serial.print("Boolean = ");
  Serial.println(data.Boolean);
  while (1); // Dit is een oneindige loop. Hier blijft het programma dus "hangen".
}
