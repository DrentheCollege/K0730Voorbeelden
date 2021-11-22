//  Omschakelaar met Debouncer
Zie ook https://github.com/thomasfredericks/Bounce2/wiki

#include <Bounce2.h>

Bounce Debounce1 = Bounce(); // Instantiate a Bounce object

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
  Debounce1.attach(buttonpin);  // After setting up the button, setup the Bounce instance :
  Debounce1.interval(5); // interval in ms
}

void loop()
{
  Debounce1.update();                     // Update the Bounce instance :
  int buttonstate = !Debounce1.read();    // Get the updated value :
  if (buttonstate == HIGH && lastbuttonstate == LOW) ledstate = !ledstate;
  digitalWrite(ledpin, ledstate);
  lastbuttonstate = buttonstate;
}

