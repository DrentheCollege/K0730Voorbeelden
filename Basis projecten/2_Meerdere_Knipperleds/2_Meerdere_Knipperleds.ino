// Meerdere knipper LED's

const int LedPinRed = 10;
const int LedPinGreen = 11;

void setup() {
  pinMode(LedPinRed, OUTPUT);
  pinMode(LedPinGreen, OUTPUT);
}

void loop() {
  digitalWrite(LedPinRed, HIGH);  
  delay(50);
  digitalWrite(LedPinRed, LOW);
  delay(1000);
  digitalWrite(LedPinGreen, HIGH);  
  delay(50);
  digitalWrite(LedPinGreen, LOW);
  delay(100);  
}

