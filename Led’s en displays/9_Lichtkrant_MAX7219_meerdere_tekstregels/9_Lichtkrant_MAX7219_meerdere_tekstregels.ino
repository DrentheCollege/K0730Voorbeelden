// Een lichtkrant met vaste teksten. 
//
// NOTE: MD_MAX72xx library must be installed and configured for the LED
// matrix type being used. Refer documentation included in the MD_MAX72xx
// library or see this link:
// https://majicdesigns.github.io/MD_MAX72XX/page_hardware.html
//

// MD_MAX72XX is version 3.0.2
// MD_Parola  is version 3.0.1

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 8 // Er zijn 8 ledmatrices aan elkaar gekoppeld
#define CS_PIN    10

// HARDWARE SPI. Dus DATA_PIN moet aangesloten zijn op pin 11 en CLK_PIN moet aangesloten zijn op pin 13
MD_Parola MyLedMatrix = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

textEffect_t scrollEffect = PA_SCROLL_LEFT;
textPosition_t scrollAlign = PA_LEFT;
int scrollPause = 1000;   // in milliseconds
int scrollSpeed = 25;     // default frame delay value
int displaycounter = -1;
int stringcounter = 0;
int Nrepeats = 1;         // Elke regel wordt zoveel keer herhaald. 
int Ntexts = 8;           // Er zijn nu 8 tekstregels gedefinieerd. 

// Global message buffers shared by Serial and Scrolling functions
#define  BUF_SIZE  76         // één meer dan het aantal karakters!
char curMessage[BUF_SIZE] = {""};

const char string_0[]  PROGMEM = "Dit is een tekst op de eerste regel.  Er mogen maximaal 75 karakters staan!";
const char string_1[]  PROGMEM = "Dit is een tekst op de tweede regel.  Er mogen maximaal 75 karakters staan!";
const char string_2[]  PROGMEM = "Dit is een tekst op de derde regel.   Er mogen maximaal 75 karakters staan!";
const char string_3[]  PROGMEM = "Dit is een tekst op de vierde regel.  Er mogen maximaal 75 karakters staan!";
const char string_4[]  PROGMEM = "Dit is een tekst op de vijfde regel.  Er mogen maximaal 75 karakters staan!";
const char string_5[]  PROGMEM = "Dit is een tekst op de zesde regel.   Er mogen maximaal 75 karakters staan!";
const char string_6[]  PROGMEM = "Dit is een tekst op de zevende regel. Er mogen maximaal 75 karakters staan!";
const char string_7[]  PROGMEM = "Dit is een tekst op de achtste regel. Er mogen maximaal 75 karakters staan!";

// Set up a table to refer to your strings.
const char* const string_table[] PROGMEM = {string_0, string_1, string_2, string_3, string_4, string_5, string_6, string_7};

void setup()
{
  Serial.begin(9600);
  MyLedMatrix.begin();
  MyLedMatrix.displayText(curMessage, scrollAlign, scrollSpeed, scrollPause, scrollEffect, scrollEffect);
}

void loop()
{
  if (MyLedMatrix.displayAnimate())
  {
    if (Nrepeats > 1) displaycounter = (displaycounter + 1) % Nrepeats;
    if (Nrepeats == 1) {
      displaycounter = displaycounter + 1;
      if (displaycounter > 1) displaycounter = 1;
    }
    if ( displaycounter == 1) {
      strcpy_P(curMessage, (char*)pgm_read_word(&(string_table[stringcounter]))); // Necessary casts and dereferencing, just copy.
      stringcounter = (stringcounter + 1) % Ntexts;
    }
    MyLedMatrix.displayReset();
  }
}
