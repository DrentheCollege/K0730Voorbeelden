// Hobbyelectronica Backpack shield

#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 MyDisplay(0x27);  // Set the MyDisplay I2C address

int SensorPin = A0;       // Input van de potmeter
int meetwaarde = 0;       // Een spanning, te meten op A0
float echtewaarde = 0;    // float is een getal met decimalen

void setup()
{
  MyDisplay.begin(16, 2);
  MyDisplay.setCursor(0, 0);
  MyDisplay.print("Spanning in Volt");
}


void loop()
{
  MyDisplay.setCursor(0, 1);
  meetwaarde = analogRead(SensorPin);                      // lees de meetwaarde:
  echtewaarde = map(meetwaarde, 0, 1023, 0, 5000) / 1000.; // Reken de meetwaarde om naar floating point 0-5 Volt door te delen door 1000
  MyDisplay.print(echtewaarde, 2);                         // Zet op het display met twee decimalen
  MyDisplay.print("  Volt");
  delay(600);
}

