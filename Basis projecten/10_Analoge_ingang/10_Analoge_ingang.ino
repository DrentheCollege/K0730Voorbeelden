int SensorPin = A0;     // Input van de potmeter
int meetwaarde = 0;     // Een spanning, te meten op A0
float echtewaarde = 0;  // float is een getal met decimalen

void setup() {
  Serial.begin(9600);  // maak een seriële communicatie op 9600 bps:
}

void loop() {
  meetwaarde = analogRead(SensorPin);               // lees de meetwaarde:
  echtewaarde = map(meetwaarde, 0, 1023, 0, 5000);  // Zet de meetwaarde om naar iets tussen de 0 en 5000
  echtewaarde = echtewaarde / 1000.;                // Reken om naar 0-5 Volt door te delen door 1000
  Serial.print("Spanning in Volt: ");
  Serial.println(echtewaarde, 3);  //Schrijf de echtewaarde in 3 decimalen naar de Seriële monitor
  delay(100);
}