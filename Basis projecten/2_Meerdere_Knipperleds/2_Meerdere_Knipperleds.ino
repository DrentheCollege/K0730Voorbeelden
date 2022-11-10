// Meerdere knipper LED's

const int LedPinRed = 10;
const int LedPinYellow = 11;

void setup() {
  pinMode(LedPinRed, OUTPUT);
  pinMode(LedPinYellow, OUTPUT);
}

void loop() {
  digitalWrite(LedPinRed, HIGH); 
  digitalWrite(LedPinYellow, HIGH);  
  delay(1000);
  digitalWrite(LedPinRed, LOW);
  digitalWrite(LedPinYellow, LOW);
  delay(1000); 
}

