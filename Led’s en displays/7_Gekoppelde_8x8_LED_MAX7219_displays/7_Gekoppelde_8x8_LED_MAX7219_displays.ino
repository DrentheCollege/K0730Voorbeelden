#include "LedControl.h"
int NRDEV = 4;
int displayteller = 0;

LedControl MyLedmatrix = LedControl(11, 13, 10, NRDEV); // DIN, CLK, CS, NRDEV
#include "Tekens.h" // In deze versie staan de bitmaps niet in PROGMEM

// Elke bitmap beschrijft 8 rijen led's. Er zijn natuurlijk allerlei speciale bitmapszoals pijlen, vraagtekens enz. te bedenken.
// Zie voor een goed conversieprogramma https://xantorohara.github.io/led-matrix-editor/

unsigned long delayTime = 10; // Delay between Frames
int Rotation = 0;

void setup(){
  Serial.begin(9600);
  for (int i = 0; i <= NRDEV; i++) {
    MyLedmatrix.shutdown(i, false);       // De MAX72XX IC is in slaapstand modus bij opstarten.
    MyLedmatrix.setIntensity(i, 1);       // Zet de helderheid op een medium niveau.
    MyLedmatrix.clearDisplay(i);          // Maak de dot matrix leeg (clear display).
  }
}

void loop() {
  for (displayteller == 0; displayteller < NRDEV; displayteller++) {

    for (int i = 0; i < DunneCijfers_LEN; i++) {
      displayImage(DunneCijfers[i]);
      delay(delayTime);
    }
    delay(1000);
    for (int i = 0; i < Pijlen_LEN; i++) {
      displayImage(Pijlen[i]);
      delay(delayTime);
    }
    delay(1000);
    MyLedmatrix.clearDisplay(displayteller);          // Maak de dot matrix leeg (clear display).
  }
  Rotation = (Rotation + 1) % 4;
  displayteller=0;
}

void displayImage(const byte* image) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (Rotation == 0) MyLedmatrix.setLed(displayteller, i, j, bitRead(image[i], 7 - j));
      if (Rotation == 1) MyLedmatrix.setLed(displayteller, j, 7 - i, bitRead(image[i], 7 - j));
      if (Rotation == 2) MyLedmatrix.setLed(displayteller, 7 - i, 7 - j, bitRead(image[i], 7 - j));
      if (Rotation == 3) MyLedmatrix.setLed(displayteller, 7 - j, i, bitRead(image[i], 7 - j));
    }
  }
}
