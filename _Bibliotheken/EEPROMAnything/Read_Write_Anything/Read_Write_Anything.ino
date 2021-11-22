/*
 * EEPROM Read and Write Anything
 *
 * In de EEprom is geheugen voor het opslaan van het Arduino programma
 * maar ook zijn er 512 "geheugenplaatssen" waar in elk een getal van 0-255 kan worden opgeslagen.
 * Je kunt geen grotere getallen opslaan, geen negatieve getallen, geen komma getallen en geen karakters.
 * Maar toch is zo'n EEPROM erg handig want de inhoud blijft bewaard, ook als de Arduino wordt uitgezet! 
 * Je kunt zelfs een andere sketch uploaden die die zelfde gegevens gaat gebruiken. 
 */

#include <EEPROM.h>
#include "EEPROMAnything.h"

struct config_t // Een structure kan allerlei variabelen bevatten. Zo'n structure kan in één keer opgeslagen worden. 
{
  long longvalue;  //Long variables are extended size variables for number storage, and store 32 bits (4 bytes), from -2,147,483,648 to 2,147,483,647.
  float floatvalue; //Datatype for floating-point numbers, a number that has a decimal point. Floating-point numbers are often used to approximate analog and continuous values because they have greater resolution than integers. Floating-point numbers can be as large as 3.4028235E+38 and as low as -3.4028235E+38. 
  int integervalue; //Integers are your primary datatype for number storage, and store a 2 byte value. This yields a range of -32,768 to 32,767 
  boolean TrueFalse;//Boolean variabelen zijn false of true, 0 of 1
} 
configuration; // De naam van de 'structure'

void setup()
{
  Serial.begin(9600);
//  EEPROM_readAnything(0, configuration);
// ...
}
void loop()
{
  configuration.longvalue=1234567890;
  configuration.floatvalue=12345.67890;  
  configuration.integervalue=12345;
  configuration.TrueFalse=true;

  EEPROM_writeAnything(0, configuration);
  delay(10);  

// Delete all values;
  configuration.longvalue=0;
  configuration.floatvalue=0;  
  configuration.integervalue=0;
  configuration.TrueFalse=false;

  Serial.println("All values deleted!");
  Serial.println("--------------------");  
  Serial.println("Reading all values from EEPROM: ");    
  EEPROM_readAnything(0, configuration);
  Serial.print("longvalue= ");
  Serial.println(configuration.longvalue);
  Serial.print("floatvalue= ");
  Serial.println(configuration.floatvalue,5);
  Serial.print("integervalue= ");
  Serial.println(configuration.integervalue);  
  Serial.print("TrueFalse= ");
  Serial.println(configuration.TrueFalse);  
  while(1);

}

