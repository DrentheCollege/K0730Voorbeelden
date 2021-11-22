#include "LedControl.h"

LedControl MyLedmatrix = LedControl(11, 13, 10, 1); // DIN, CLK, CS, NRDEV

unsigned long delaytime = 50;           //Een variabele voor het wachten voordat we het display updaten.

void setup() {
  MyLedmatrix.shutdown(0, false);       // De MAX72XX IC is in slaapstand modus bij opstarten.
  MyLedmatrix.setIntensity(0, 8);       // Zet de helderheid op een medium niveau.
  MyLedmatrix.clearDisplay(0);          // Maak de dot matrix leeg (clear display).
}

void loop() {
  for (int row = 0; row < 8; row++) {   // Zet de ledjes stuk voor stuk aan.
    for (int col = 0; col < 8; col++) {
      MyLedmatrix.setLed(0, row, col, true); 
      delay(delaytime);
    }
  }
  for (int row = 0; row < 8; row++) {   // Zet de ledjes stuk voor stuk uit.
    for (int col = 0; col < 8; col++) {
      MyLedmatrix.setLed(0, row, col, false); 
      delay(delaytime);
    }
  }
}
