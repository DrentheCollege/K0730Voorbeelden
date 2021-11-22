// Een On/Off led met Touch sensor (aanraakschakelaar)

int TouchPin = 7; // Pin for capacitive touch sensor
int led = 13;
boolean currentState = LOW;
boolean lastState = LOW;
boolean LedState = LOW;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(TouchPin, INPUT);
}

void loop() {
  currentState = digitalRead(TouchPin);
  if (currentState == HIGH && lastState == LOW) {
    delay(5);
    if (LedState == HIGH)LedState = LOW;
    else LedState = HIGH;
  }
  lastState = currentState;
  digitalWrite(led, LedState);
}
