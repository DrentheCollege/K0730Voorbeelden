// Een schakelaar Debouncen

const int buttonpin = 7;
const int ledpin = 13;
int ledstate = LOW;
int buttonstate;
int lastbuttonstate;

void setup()
{
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  pinMode(buttonpin, INPUT_PULLUP);
}

void loop()
{
  buttonstate = !debounce( buttonpin);
  if (buttonstate == HIGH && lastbuttonstate == LOW) ledstate = !ledstate;
  lastbuttonstate = buttonstate;
  digitalWrite(ledpin, ledstate);
}

boolean debounce(int pin)
{
  boolean state;
  boolean previousState;
  previousState = digitalRead(pin);
  for (int counter = 0; counter < 10; counter++)
  {
    delay(1);                   //wait 1 millisecond
    state = digitalRead(pin);   //read the pin
    if (state != previousState)
    {
      counter = 0;              //reset the counter
      previousState = state;
    }
  }
  return state;
}
