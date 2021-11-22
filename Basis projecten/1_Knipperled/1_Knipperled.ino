// Een knipperLed

const int LedPin = 13;

void setup() {
  pinMode(LedPin, OUTPUT);
}

void loop() {
  digitalWrite(LedPin, HIGH);
  delay(50);
  digitalWrite(LedPin, LOW);
  delay(1000);
}

