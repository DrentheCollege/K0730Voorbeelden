// Een RGB–Led met potmeter

int SensorPin = A0;       // Input van de potmeter
int meetwaarde = 0;       // Een spanning, te meten op A0
int PWMwaarde = 0;

int RedLed = 9;
int GreenLed = 10;
int BlueLed = 11;

int R = 0;
int G = 0;
int B = 0;

void setup() {
  Serial.begin (9600);
}

void loop() {
  meetwaarde = analogRead(SensorPin);        // lees de meetwaarde:
  PWMwaarde = map(meetwaarde, 0, 1023, 0, 170); // Zet de meetwaarde om naar iets tussen de 0 en 255 of 170
  Conversion(PWMwaarde);
  analogWrite(RedLed, R);
  analogWrite(GreenLed, G);
  analogWrite(BlueLed, B);
  delay(100);
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


