//  Audio

int buzzerpin = 12;
int tijdsduur = 750;

void setup () {     // Hier staat helemaal niets...
}

void loop() {
  tone(buzzerpin, 392, tijdsduur / 4); //G4
  delay(1.3 * tijdsduur / 4);
  tone(buzzerpin, 523, tijdsduur / 4); //C5
  delay(1.3 * tijdsduur / 8);
  tone(buzzerpin, 659, tijdsduur / 4); //E5
  delay(1.3 * tijdsduur / 8);
  tone(buzzerpin, 784, tijdsduur / 3); //G5
  delay(1.3 * tijdsduur / 4);
  tone(buzzerpin, 659, tijdsduur / 4); //E5
  delay(1.3 * tijdsduur / 4);
  tone(buzzerpin, 784, tijdsduur / 1); //G5
  delay(1.3 * tijdsduur / 1);
}

