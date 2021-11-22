//  Array's

int ledpins[3] = {10, 11, 12};

void setup() {
  for (int i = 0;  i < 3;  i++) {
    pinMode(ledpins[i], OUTPUT);
  }
}
void loop() {
  for (int i = 0;  i < 3;  i++) {
    digitalWrite(ledpins[i], HIGH);
    delay(50);
    digitalWrite(ledpins[i], LOW);
    delay(100);
  }
}

