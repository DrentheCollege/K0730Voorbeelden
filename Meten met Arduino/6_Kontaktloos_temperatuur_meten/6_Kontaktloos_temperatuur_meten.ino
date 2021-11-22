// Kontaktloos temperatuur meten met een TMP006

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_TMP006.h"
#include <LiquidCrystal_I2C.h>

// SCL connects to the I2C clock pin. On the Uno, this is A5.
// SDA connects to the I2C data pin. On the Uno, this is A4.

Adafruit_TMP006 Sensor006(0x40); //Adafruit_TMP006 tmp006(0x41);  // start with a different i2c address!

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

const int Measure_Period = 100;          // Update measurement every 2000 msec.
unsigned long time_to_Measure = 0;
const int Display_Period = 1000;         // Update Display elke 1000 msec.
unsigned long time_to_Display = 0;

String LcdDegC; // voor het graden-teken op LCD
float Temp = 0;
int MaxTemp = 1000;

void setup() {
  Serial.begin(9600);
  LcdDegC += char(223);               // voor het graden-teken op LCD

  lcd.begin(16, 2);                   // set up the LCD's number of columns and rows:
  lcd.setCursor(0, 0);                // Schrijf op de eerste regel, nulde positie
  lcd.write("Temperatuurmeter");      // Mooi gecentreerde tekst!
  delay(1000);
}

void loop() {
  Temperatuur_Meting();
  Display_Temperatuur();
}

void Temperatuur_Meting() {
  if ((millis() - time_to_Measure) > Measure_Period)
  {
    Temp = 100 * Sensor006.readObjTempC(); // Meet de temperatuur. (x 100)
    time_to_Measure = millis();
  }
}

void   Display_Temperatuur() {
  if ((millis() - time_to_Display) > Display_Period)  {
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(Temp / 100, 2); // 2 decimalen
    lcd.print(" " + LcdDegC); // Graden teken op LCD
    lcd.print("C ");
    time_to_Display = millis();
  }
}

