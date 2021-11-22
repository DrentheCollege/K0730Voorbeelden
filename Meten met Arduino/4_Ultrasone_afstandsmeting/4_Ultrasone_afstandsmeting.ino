
#include <NewPing.h>
#define TRIGGER_PIN  9    // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     10   // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance in cm. Maximum distance is 400-500 cm.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int afstand = 0;

const int Measure_Period = 500;          // Update measurement every 500 msec. 29ms should be the shortest delay between pings.
unsigned long time_to_Measure = 0;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C MyDisplay(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address


void setup() {
  MyDisplay.begin(16, 2);
  MyDisplay.print("Ultrasoon");
  delay(2000);
  MyDisplay.setCursor(0, 0);
  MyDisplay.print("Afstand in cm   ");
}

void loop() {
  Ultrasoon_Meting();
}

void Ultrasoon_Meting() {
  if ((millis() - time_to_Measure) > Measure_Period)  {
    afstand = sonar.ping() / 58; // Send ping, get ping time, convert microseconds to cm.
    time_to_Measure = millis();
    MyDisplay.setCursor(0, 1);
    MyDisplay.print("               ");
    MyDisplay.setCursor(0, 1);
    MyDisplay.print(afstand);
  }
}

