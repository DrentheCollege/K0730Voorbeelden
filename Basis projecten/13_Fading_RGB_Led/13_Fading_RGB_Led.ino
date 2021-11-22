// RGB Auto Fader. Loopt door het spectrum van kleuren heen in 255 stappen.

int RedLed   = 9;
int GreenLed = 10;
int BlueLed  = 11;

int R = 0;
int G = 0;
int B = 0;

void setup() {
  Serial.begin(9600);   // initialize serial communications at 9600 bps:
  pinMode(RedLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);
  pinMode(BlueLed, OUTPUT);
}

void loop() {
  for (int ColorValue = 0; ColorValue <= 255; ColorValue++) {
    Conversion(ColorValue);
    analogWrite(RedLed, R);
    analogWrite(GreenLed, G);
    analogWrite(BlueLed, B);
    delay(50);
  }
  for (int ColorValue = 255; ColorValue >= 0; ColorValue--) {
    Conversion(ColorValue);
    analogWrite(RedLed, R);
    analogWrite(GreenLed, G);
    analogWrite(BlueLed, B);
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




