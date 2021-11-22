#include <Adafruit_NeoPixel.h>

#define Pixelpin  8         // Digital IO pin connected to the NeoPixels.
#define Numpixels 3         // Er zijn 3 pixels. 

Adafruit_NeoPixel Led = Adafruit_NeoPixel(Numpixels, Pixelpin, NEO_RGB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  Led.setBrightness(255);
  Led.begin();
  Led.show();                          // Initialize all pixels to 'off'
}

void loop() {
  Led.setPixelColor(0, 255, 0, 0);     // Zet de 1e Led op rood
  Led.show();
  delay(2000);

  Led.setPixelColor(0, 0, 0, 0);       // Zet de 1e Led uit
  Led.setPixelColor(1, 230, 145, 1);   // Zet de 2e Led op oranje
  Led.show();
  delay(1000);

  Led.setPixelColor(1, 0, 0, 0);        // Zet de 2e Led uit
  Led.setPixelColor(2, 0, 255, 0);      // Zet de 3e Led op groen
  Led.show();
  delay(1000);
  Led.setPixelColor(2, 0, 0, 0);        // Zet de 3e Led uit
}

