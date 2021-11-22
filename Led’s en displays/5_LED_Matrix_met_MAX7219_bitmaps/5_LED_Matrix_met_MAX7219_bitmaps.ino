#include "LedControl.h"

LedControl MyLedmatrix = LedControl(11, 13, 10, 1); // DIN, CLK, CS, NRDEV
#include "Tekens.h"                                 // In deze versie staan de bitmaps niet in PROGMEM

// Elke bitmap beschrijft 8 rijen led's. 
// Er zijn natuurlijk allerlei speciale bitmapszoals pijlen, vraagtekens enz. te bedenken.
// Zie voor een goed conversieprogramma https://xantorohara.github.io/led-matrix-editor/

unsigned long delayTime = 400; // Delay between Frames
int Rotation = 0;
void setup()
{
  MyLedmatrix.shutdown(0, false);       // De MAX72XX IC is in slaapstand modus bij opstarten.
  MyLedmatrix.setIntensity(0, 5);       // Zet de helderheid op een medium niveau.
  MyLedmatrix.clearDisplay(0);          // Maak de dot matrix leeg (clear display).
}

void loop() {
  for (int i = 0; i < Hoofdletters_LEN; i++) {
    displayImage(Hoofdletters[i]);
    delay(delayTime);
  }
  delay(2000);
  for (int i = 0; i < Kleineletters_LEN; i++) {
    displayImage(Kleineletters[i]);
    delay(delayTime);
  }
  delay(2000);
  for (int i = 0; i < DikkeCijfers_LEN; i++) {
    displayImage(DikkeCijfers[i]);
    delay(delayTime);
  }
  delay(2000);
  for (int i = 0; i < DunneCijfers_LEN; i++) {
    displayImage(DunneCijfers[i]);
    delay(delayTime);
  }
  delay(2000);
  for (int i = 0; i < Pijlen_LEN; i++) {
    displayImage(Pijlen[i]);
    delay(delayTime);
  }
  delay(2000);
  Rotation = (Rotation + 1) % 4;
}

void displayImage(const byte* image) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (Rotation == 0) MyLedmatrix.setLed(0, i, j, bitRead(image[i], 7 - j));
      if (Rotation == 1) MyLedmatrix.setLed(0, j, 7 - i, bitRead(image[i], 7 - j));
      if (Rotation == 2) MyLedmatrix.setLed(0, 7 - i, 7 - j, bitRead(image[i], 7 - j));
      if (Rotation == 3) MyLedmatrix.setLed(0, 7 - j, i, bitRead(image[i], 7 - j));
    }
  }
}
