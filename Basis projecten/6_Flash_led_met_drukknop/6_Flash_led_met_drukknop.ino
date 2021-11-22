// Een Flash led met drukknop

int buttonPin = 2;     // the number of the pushbutton pin
int ledPin =  13;      // the number of the LED pin
int buttonState = 1;   // variable for reading the pushbutton status

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    for (int i = 1; i <= 3; i++) {
      digitalWrite(ledPin, HIGH);   // turn the LED on
      delay(50);                    // wait
      digitalWrite(ledPin, LOW);    // turn the LED off
      delay(500);                   // wait
    }
  }
}

