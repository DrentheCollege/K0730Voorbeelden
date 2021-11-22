int ledPin =  6;        // the number of the LED pin
int SensorPin = A0;       // Input van de potmeter
int meetwaarde = 0;       // Een spanning, te meten op A0
int PWMwaarde = 0;
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  meetwaarde = analogRead(SensorPin);        // lees de meetwaarde:
  PWMwaarde = map(meetwaarde, 0, 1023, 0, 255); // Zet de meetwaarde om naar iets tussen de 0 en 5000
  analogWrite(6, PWMwaarde);
  delay(100);
}

