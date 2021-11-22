// Een Functie gebruiken

int buttonPin = 2;     // the number of the pushbutton pin
int ledPin =  8;       // the number of the LED pin
int buttonState = 1;  // variable for reading the pushbutton status

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

boolean Button(){
  if(!digitalRead(buttonPin)) return 1;
 else return 0;
}

void loop() {
  if (Button) ledknipper();
}

void ledknipper() {
  for (int i = 1; i <= 5; i++) {
    digitalWrite(ledPin, HIGH);   // turn the LED on
    delay(50);                  // wait
    digitalWrite(ledPin, LOW);    // turn the LED off
    delay(500);                  // wait
  }
}

