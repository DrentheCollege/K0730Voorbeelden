// Een Functie gebruiken

int buttonPin = 2;     // the number of the pushbutton pin
int ledPin =  8;       // the number of the LED pin
int buttonState = 1;  // variable for reading the pushbutton status

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void Button(int k){
  k=!digitalRead(buttonPin);
}

void loop() {
Button(buttonState);
  if (buttonState) ledknipper();  if (Button) ledknipper();
}


void ledknipper() {
  for (int i = 1; i <= 5; i++) {
    digitalWrite(ledPin, HIGH);   // turn the LED on
    delay(50);                  // wait
    digitalWrite(ledPin, LOW);    // turn the LED off
    delay(500);                  // wait
  }
}

