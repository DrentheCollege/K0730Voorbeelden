#include <Wire.h>
#include <dht11.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
dht11 DHT11sensor;

const int Measure_Period = 2000;          // Update measurement every 2000 msec.
unsigned long time_to_Measure = 0;
int meetwaarde = 2;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("DHT11 sensor: ");
  lcd.setCursor(0, 0);
  DHT11sensor.attach(2); // DHT11 met -, + en data
}

void loop() {
  DHT11_Meting();
}

void DHT11_Meting() {
  if ((millis() - time_to_Measure) > Measure_Period)  {
    meetwaarde = (meetwaarde + 1) % 3;
    if (meetwaarde == 0)  {
      int chk = DHT11sensor.read();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Vochtigheit:       ");
      lcd.setCursor(0, 1);
      lcd.print((float)DHT11sensor.humidity, 0);
      lcd.print(" %");
    }
    if (meetwaarde == 1)  {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temperatuur:    ");
      lcd.setCursor(0, 1);
      lcd.print((float)DHT11sensor.temperature,1);
      lcd.print(" ");
      lcd.print(char(223));
      lcd.print("C");
    }
    if (meetwaarde == 2)  {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Dauwpunt:       ");
      lcd.setCursor(0, 1);
      lcd.print((float)DHT11sensor.dewPoint(), 2);
      lcd.print(" ");
      lcd.print(char(223));
      lcd.print("C");
    }
    time_to_Measure = millis();
  }
}


