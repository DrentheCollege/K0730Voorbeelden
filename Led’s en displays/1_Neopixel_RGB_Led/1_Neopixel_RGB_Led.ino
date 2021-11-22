#include <Adafruit_NeoPixel.h>

#define Pixelpin  8     // Digital IO pin connected to the NeoPixels.
#define Numpixels 1     // Er is maar één pixels. 

Adafruit_NeoPixel Led = Adafruit_NeoPixel(Numpixels, Pixelpin, NEO_RGB + NEO_KHZ800); // Nodig om de Neopixel functies aan te zetten.


void setup() {
  Serial.begin(9600);
  Led.setBrightness(255); 
  Led.begin();
  Led.show(); // Initialize all pixels to 'off'
}

void loop() {
  Led.setPixelColor(0, 255, 0, 0); // rood
  Led.show();
  delay(1000);
  Led.setPixelColor(0, 0, 255, 0); // groen
  Led.show();
  delay(1000);
  Led.setPixelColor(0, 0, 0, 255); // blauw
  Led.show();
  delay(1000);
  Led.setPixelColor(0, 255, 255, 0); // geel
  Led.show();
  delay(1000);
  Led.setPixelColor(0, 255, 0, 255); // magenta
  Led.show();
  delay(1000);
  Led.setPixelColor(0, 0, 255, 255); // cyaan
  Led.show();
  delay(1000);
  Led.setPixelColor(0, 255, 255, 255); // wit
  Led.show();
  delay(1000);
  Led.setPixelColor(0, 255, 128, 0); // oranje
  Led.show();
  delay(1000);
  Led.setPixelColor(0, 200, 0, 100); // roze
  Led.show();
  delay(1000);
  Led.setPixelColor(0, 100, 0, 200); // paars
  Led.show();
  delay(4000);

}


