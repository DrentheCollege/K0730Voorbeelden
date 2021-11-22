// These variables store the flash pattern and the current state of the Led

int Led1Pin                =  2;      // the number of the Led pin
int Led1State              = LOW;     // LedState used to set the Led
long Led1OnTime            = 50;     // milliseconds on-time
long Led1OffTime           = 450;     // milliseconds off-time
unsigned long Led1Lasttime = 0;

int Led2Pin                =  3;      // the number of the Led pin
int Led2State              = LOW;     // LedState used to set the Led
long Led2OnTime            = 250;     // milliseconds on-time
long Led2OffTime           = 250;     // milliseconds off-time
unsigned long Led2Lasttime = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(Led1Pin, OUTPUT);
  pinMode(Led2Pin, OUTPUT);
}

void loop()
{
  Led1();
  Led2();
}

void Led1() {
  if (Led1State == HIGH && (millis() - Led1Lasttime) > Led1OnTime)  {
    Led1State = LOW;  // Turn it off
    Led1Lasttime = millis();
    digitalWrite(Led1Pin, Led1State);  // Update the actual Led
  }
  if (Led1State == LOW && (millis() - Led1Lasttime) > Led1OffTime)  {
    Led1State = HIGH;  // Turn it on
    Led1Lasttime = millis();
    digitalWrite(Led1Pin, Led1State);  // Update the actual Led
  }
}

void Led2() {
  if (Led2State == HIGH && (millis() - Led2Lasttime) > Led2OnTime)  {
    Led2State = LOW;  // Turn it off
    Led2Lasttime = millis();
    digitalWrite(Led2Pin, Led2State);  // Update the actual Led
  }
  if (Led2State == LOW && (millis() - Led2Lasttime) > Led2OffTime)  {
    Led2State = HIGH;  // Turn it on
    Led2Lasttime = millis();
    digitalWrite(Led2Pin, Led2State);  // Update the actual Led
  }
}

