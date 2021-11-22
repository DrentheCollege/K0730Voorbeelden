int buttonPin = 2;     // the number of the pushbutton pin
int ledPin =  13;      // the number of the LED pin
int buttonState = 1;   // variable for reading the pushbutton status

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.println("De start van het programma. Dit is de setup…");
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    Serial.println("De button is ingedrukt");
    Serial.print("De variabele buttonState is ");
    Serial.println(buttonState);
  }
  if (buttonState == LOW) {
    digitalWrite(ledPin, HIGH);   // turn the LED on
  }
  else {
    digitalWrite(ledPin, LOW);   // turn the LED off
  }
}

