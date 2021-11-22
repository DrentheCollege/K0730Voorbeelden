int ledpin = 8;

void setup() {
  pinMode(ledpin, OUTPUT);

  for (int i = 1; i <= 3; i++) {
    digitalWrite(ledpin, HIGH);   // turn the LED on
    delay(100);                  // wait
    digitalWrite(ledpin, LOW);    // turn the LED off
    delay(1000);                  // wait
  }
}

void loop() {
}


