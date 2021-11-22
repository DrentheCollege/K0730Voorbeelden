// Hobbyelectronica Backpack shield

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C MyDisplay(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

int SensorPin = A0;       // Input van de potmeter
int meetwaarde = 0;       // Een spanning, te meten op A0
float echtewaarde = 0;    // float is een getal met decimalen

const int Measure_Period = 600;    // Update measurement every 600 msec.
unsigned long time_to_Measure = 0;

void setup()
{
  MyDisplay.begin(16, 2);
  MyDisplay.setCursor(0, 0);
  MyDisplay.print("Spanning in Volt");
}

void loop()
{
  Spannings_Meting();
}

void Spannings_Meting() {
  if ((millis() - time_to_Measure) > Measure_Period)  {
    meetwaarde = analogRead(SensorPin);        // lees de meetwaarde:
    echtewaarde = map(meetwaarde, 0, 1023, 0, 5000) / 1000.; // Reken de meetwaarde om naar 0-5 Volt door te delen door 1000
    time_to_Measure = millis();
    MyDisplay.setCursor(0, 1);
    MyDisplay.print(echtewaarde, 2);
    MyDisplay.print("  Volt");
  }
}

