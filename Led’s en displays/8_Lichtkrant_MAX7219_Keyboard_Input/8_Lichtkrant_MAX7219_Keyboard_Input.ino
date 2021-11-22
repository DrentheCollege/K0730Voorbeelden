// Demonstrates the use of the Parola library scrolling function to display text received from the serial interface
// Dit werkt met de nieuwe libraries!!
// De seriele monitor moet op 9600 Baud en op Nieuwe Regel staan!
//
// User can enter text on the serial monitor and this will display as a scrolling message on the display.
// NOTE: MD_MAX72xx library must be installed and configured for the LED matrix type being used. 
// Refer documentation included in the MD_MAX72xx library or see this link:
// https://majicdesigns.github.io/MD_MAX72XX/page_hardware.html
//

// 4 december 2018. Update i.v.m. Nieuwe libraries
// MD_MAX72XX is version 3.0.2
// MD_Parola is version 3.0.1

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include <SoftwareSerial.h>
#include <EEPROM.h>
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 8 // Er zijn 8 ledmatrices aan elkaar gekoppeld
#define CS_PIN    10

// HARDWARE SPI. DATA_IN móet aangesloten zijn op pin 11 en CLK_PIN móet aangesloten zijn op pin 13.
// Alleen Chipselect op 10 is vrij te kiezen. 

MD_Parola MyLedMatrix = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

textEffect_t scrollEffect = PA_SCROLL_LEFT;
textPosition_t scrollAlign = PA_LEFT;
int scrollPause = 2000; // in milliseconds
int scrollSpeed = 25;    // default frame delay value

// Global message buffers shared by Serial and Scrolling functions
#define	BUF_SIZE	75
char curMessage[BUF_SIZE] = { "" };
char newMessage[BUF_SIZE] = { "" };
bool newMessageAvailable = true;

void setup()
{
  // Enable the next line to clear the message from eeprom.
  EEPROM.write(0,1);
  Serial.begin(9600);
  Serial.print("\n[Scrolling display.....]\nType a message for the scrolling display\nEnd message line with a newline");
  MyLedMatrix.begin();
  MyLedMatrix.displayText(curMessage, scrollAlign, scrollSpeed, scrollPause, scrollEffect, scrollEffect);
  getMessageFromEeprom();   // Get the last message from EEPROM
}

void loop()
{
  readSerial();
  if (MyLedMatrix.displayAnimate())
  {
    if (newMessageAvailable)
    {
      strcpy(curMessage, newMessage);
      newMessageAvailable = false;
      storeMessageInEeprom();
    }
    MyLedMatrix.displayReset();
  }
}

void readSerial(void)
{
  static char *cp = newMessage;
  while (Serial.available())
  {
    *cp = (char)Serial.read();
    if ((*cp == '\n') || (cp - newMessage >= BUF_SIZE - 2)) // end of message character or full buffer
    {
      *cp = '\0';        // restart the index for next filling spree and flag we have a message waiting
      cp = newMessage;
      newMessageAvailable = true;
    }
    else cp++;           // move char pointer to next position
  }
}

void storeMessageInEeprom() { // Store the message in EEPROM
  EEPROM.write(0, 251);
  int i = 0;
  char c = curMessage[i];
  while (c != 0) {
    EEPROM.write(i + 1, c);
    i++;
    c = curMessage[i];
  }
  EEPROM.write(i + 1, 0);
}

void getMessageFromEeprom() { // Retrieve the message from EEPROM
  if (EEPROM.read(0) != 251) {
    strcpy(curMessage, "Enter new message:");
    newMessage[0] = '\0';
  } else {
    int i = 0;
    char c = EEPROM.read(i + 1);
    while (c != 0) {
      curMessage[i++] = c;
      c = EEPROM.read(i + 1);
    }
    curMessage[i] = '\0';
    newMessageAvailable = false;
  }
}
