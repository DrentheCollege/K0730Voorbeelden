// RGB Auto Fader. Loopt door het spectrum van kleuren heen in 255 stappen.

#include <Adafruit_NeoPixel.h>
#define PIN            8
#define NUMPIXELS      1
Adafruit_NeoPixel Led = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);

int R = 0;
int G = 0;
int B = 0;

void setup() {
  Serial.begin(9600);   // initialize serial communications at 9600 bps:
  Led.begin();
  Led.show(); // Initialize all pixels to 'off'
  Led.setBrightness(255); // Op Brightness 255 gaat de 9 V batterij érg snel leeg....
}

void loop() {
  for (int ColorValue = 0; ColorValue <= 255; ColorValue++) {
    Conversion(ColorValue);
    Led.setPixelColor(0, Led.Color(R, G, B));
    Led.show();
    delay(50);
  }
  for (int ColorValue = 255; ColorValue >= 0; ColorValue--) {
    Conversion(ColorValue);
    Led.setPixelColor(0, Led.Color(R, G, B));
    Led.show();
    delay(50);
  }
}

int Conversion(int ColorValue) {
  if (ColorValue < 85) {
    R = 255 - ColorValue * 3;
    G = 0;
    B = ColorValue * 3;
  }
  else if (ColorValue < 170) {
    ColorValue = ColorValue - 85;
    R = 0;
    G = ColorValue * 3;
    B = 255 - ColorValue * 3;
  }
  else {
    ColorValue = ColorValue - 170;
    R = ColorValue * 3;
    G = 255 - ColorValue * 3;
    B = 0;
  }
}




