#include <Wire.h>
#include <DHT.h>
#include <LiquidCrystal_PCF8574.h>

int dhtPin = 2;

LiquidCrystal_PCF8574 MyDisplay(0x27);  // Set the MyDisplay I2C address
DHT DHT11sensor(dhtPin, DHT11);

const int Measure_Period = 2000;          // Update measurement every 2000 msec.
unsigned long time_to_Measure = 0;
int meetwaarde = 2;
float temperatuur;
float vochtigheid;

void setup() {
  Serial.begin(9600);
  MyDisplay.begin(16, 2);
  MyDisplay.setBacklight(255);
  MyDisplay.print("DHT11 sensor: ");
  MyDisplay.setCursor(0, 0);
  DHT11sensor.begin();
}

void loop() {
  DHT11_Meting();
}

void DHT11_Meting() {
  if ((millis() - time_to_Measure) > Measure_Period)  {
    meetwaarde = (meetwaarde + 1) % 3;
    if (meetwaarde == 0)  {
      int chk = DHT11sensor.read();
      MyDisplay.clear();
      MyDisplay.setCursor(0, 0);
      MyDisplay.print("Vochtigheit:       ");
      MyDisplay.setCursor(0, 1);
      vochtigheid = DHT11sensor.readHumidity();
      MyDisplay.print((float) vochtigheid, 0);
      MyDisplay.print(" %");
    }
    if (meetwaarde == 1)  {
      MyDisplay.clear();
      MyDisplay.setCursor(0, 0);
      MyDisplay.print("Temperatuur:    ");
      MyDisplay.setCursor(0, 1);
      temperatuur = DHT11sensor.readTemperature();
      MyDisplay.print((float) temperatuur,1);
      MyDisplay.print(" ");
      MyDisplay.print(char(223));
      MyDisplay.print("C");
    }
    if (meetwaarde == 2)  {
      MyDisplay.clear();
      MyDisplay.setCursor(0, 0);
      MyDisplay.print("Hitte Index:       ");
      MyDisplay.setCursor(0, 1);
      float hitteIndex = DHT11sensor.computeHeatIndex(temperatuur, vochtigheid, false);
      MyDisplay.print((float) hitteIndex, 2);
      MyDisplay.print(" ");
      MyDisplay.print(char(223));
      MyDisplay.print("C");
    }
    time_to_Measure = millis();
  }
}


