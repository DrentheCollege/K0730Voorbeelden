/* Klassieke LCD met veel aansluitingen
  De aansluitingen:
   LCD RS pin to digital pin 12, LCD Enable pin to digital pin 11
   LCD D4 pin to digital pin 5,  LCD D5 pin to digital pin 4
   LCD D6 pin to digital pin 3,  LCD D7 pin to digital pin 2
   LCD R/W pin to ground,
   10K resistor, ends to +5V and ground, wiper to LCD VO pin (pin 3)
*/

#include <LiquidCrystal.h>

LiquidCrystal MyDisplay(12, 11, 5, 4, 3, 2); // initialize the library with the numbers of the interface pins

void setup() {
  MyDisplay.begin(16, 2);                 // set up the LCD's number of columns and rows:
  MyDisplay.print("Hello World!!");       // Print a message to the MyDisplay.
  MyDisplay.clear();
  MyDisplay.print("Demo LCD Display!");   // Print a message to the MyDisplay.
}

void loop() {

  // Het printen van een veranderend getal
  for (int k = 0; k <= 10; k++) {
    MyDisplay.clear();
    MyDisplay.setCursor(0, 0);
    MyDisplay.print("Een getal.....");
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
    MyDisplay.scrollDisplayLeft(); //Elke keer dat dit wordt gebruikt springt de tekst één positie naar links.
    delay(200);
  }
  delay(500); // Nu naar rechts scrollen
  for (int k = 0; k <= 23; k++) {
    MyDisplay.scrollDisplayRight(); //Elke keer dat dit wordt gebruikt springt de tekst één positie naar links.
    delay(200);
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
