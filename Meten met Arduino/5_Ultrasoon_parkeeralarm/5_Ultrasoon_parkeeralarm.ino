// Declaraties voor de ultrasoon sensor
#include <NewPing.h>
#define TRIGGER_PIN  9                   // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     10                  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 100                 // Maximum distance in cm. Maximum distance is 400-500 cm.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
const int Measure_Period = 50;          // Update measurement every 100 msec.
unsigned long time_to_Measure = 0;
int afstand = 0;

// Declaraties voor de beeper
#include <NewTone.h>
int BeeperPin                 =  2;     // the number of the Beeper pin
int BeeperState              = LOW;     // BeeperState used to set the Beeper
long BeeperOnTime            = 150;     // milliseconds of on-time
long BeeperOffTime           = 250;     // milliseconds of off-time
unsigned long BeeperLasttime = 0;

// Declaraties voor het I2C display
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C MyDisplay(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
const int Display_Period = 500; // Update display every 500 msec
unsigned long time_to_Display = 0;

void setup() {
  Serial.begin(9600);
  MyDisplay.begin(16, 2);
  MyDisplay.print("Ultrasoon");
  delay(2000);
  MyDisplay.setCursor(0, 0);
  MyDisplay.print("Afstand in cm   ");
}

void loop() {
  Ultrasoon_Meting();   // Every 50 msec
  Update_LCD_Display(); // Every 100 msec
  Beeper();
}

void Ultrasoon_Meting() {
  if ((millis() - time_to_Measure) > Measure_Period)  {
    afstand = sonar.ping() / 29 / 2; // Send ping, get ping time, convert microseconds (uS) to cm.
    time_to_Measure = millis();
  }
}

void Beeper() {
  if (BeeperState == HIGH && (millis() - BeeperLasttime) > BeeperOnTime)  {
    BeeperState = LOW;  // Turn it off
    noNewTone(BeeperPin);
    BeeperLasttime = millis();
  }
  if (afstand < 15 && afstand > 0 && BeeperState == LOW && (millis() - BeeperLasttime) > BeeperOffTime)  {
    BeeperState = HIGH;  // Turn it on
    NewTone(BeeperPin, 440);
    BeeperLasttime = millis();
  }
}

void Update_LCD_Display() {
  if ((millis() - time_to_Display) > Display_Period) {
    MyDisplay.setCursor(0, 0);
    MyDisplay.print("Afstand in cm");
    if (afstand > 0) {
      MyDisplay.setCursor(0, 1);
      MyDisplay.print("                ");
      MyDisplay.setCursor(0, 1);
      MyDisplay.print(afstand);
    }
    time_to_Display = millis();
  }
}

