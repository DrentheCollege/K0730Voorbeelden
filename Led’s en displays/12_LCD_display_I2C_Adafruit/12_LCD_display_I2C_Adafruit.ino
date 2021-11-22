// Adafruit Backpack shield
// 5V to Arduino 5V pin, GND to Arduino GND pin, CLK to Analog #5 (Geel), DAT to Analog #4 (Oranje)

/*
  De LiquidCrystal library kent de volgende commando's:
  void noDisplay();
  void display();
  void noBlink();
  void blink();
  void noCursor();
  void cursor();
  void scrollDisplayLeft();
  void scrollDisplayRight();
  void leftToRight();
  void rightToLeft();
  void autoscroll();
  void noAutoscroll();
*/

#include "Wire.h"  // include the library code:
#include "Adafruit_LiquidCrystal.h"

Adafruit_LiquidCrystal MyDisplay(0);

void setup() {
  MyDisplay.begin(16, 2);
  MyDisplay.begin(16, 2);   // set up the lcd's number of columns and rows:
  MyDisplay.print("Hello World!!");   // Print a message to the LCD.
  MyDisplay.clear();
}

void loop() {
  // Het printen van een veranderend getal
  MyDisplay.clear();
  MyDisplay.setCursor(0, 0);
  MyDisplay.print("Een getal.....");
  for (int k = 0; k <= 10; k++) {
    MyDisplay.setCursor(0, 1);
    MyDisplay.print(k);
    delay(500);
  }
  delay(1000);
  MyDisplay.clear();

  // Het schrijven van een twee-regelige tekst
  MyDisplay.setCursor(0, 0);
  MyDisplay.print("Regel 1: ");
  MyDisplay.setCursor(0, 1);
  MyDisplay.print("Regel 2: ");
  delay(1000);
  MyDisplay.clear();

  MyDisplay.setCursor(0, 0);
  MyDisplay.print("Left and right scrolling");
  delay(500); // Naar links scrollen
  for (int k = 0; k <= 23; k++) {
    MyDisplay.scrollDisplayLeft();          //Elke keer dat dit wordt gebruikt springt de tekst één positie naar links.
    //     MyDisplay.scrollDisplayRight();  //Elke keer dat dit wordt gebruikt springt de tekst één positie naar rechts.
    delay(200);
  }
  delay(500); // Nu naar rechts scrollen
  for (int k = 0; k <= 23; k++) {
    MyDisplay.scrollDisplayRight(); //Elke keer dat dit wordt gebruikt springt de tekst één positie naar links.
    delay(400);
  }
  delay(500);
  MyDisplay.clear();
  MyDisplay.setCursor(0, 0);
  MyDisplay.print("Graden teken");
  MyDisplay.setCursor(0, 1);
  MyDisplay.print(char(223));
  MyDisplay.print("C");
  delay(2000);
}
