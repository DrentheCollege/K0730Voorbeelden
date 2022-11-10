const int LeftbuttonPin = 2;
const int RightbuttonPin = 3;
const int RedledPin   =  7;
const int YellowledPin =  8;

int LeftbuttonState = 0;
int RightbuttonState = 0;

void setup() {
  pinMode(RedledPin,   OUTPUT);
  pinMode(YellowledPin, OUTPUT);
  pinMode(LeftbuttonPin,  INPUT_PULLUP);
  pinMode(RightbuttonPin, INPUT_PULLUP);
}

void loop() {
  LeftbuttonState   = digitalRead(LeftbuttonPin);
  RightbuttonState = digitalRead(RightbuttonPin);

  if (LeftbuttonState == LOW) {
    digitalWrite(RedledPin, HIGH);
  } else {
    digitalWrite(RedledPin, LOW);
  }
  if (RightbuttonState == LOW) {
    digitalWrite(YellowledPin, HIGH);
  } else {
    digitalWrite(YellowledPin, LOW);
  }
}

