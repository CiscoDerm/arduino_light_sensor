#include <Grove_LED_Bar.h>

const int lightSensorPin = A8;
const int motorPin = 2;  // Utilisez le port 2 pour la connexion PWM (modifiez si nécessaire)

Grove_LED_Bar bar(9, 8, 0);

void setup() {
  Serial.begin(9600);
  pinMode(lightSensorPin, INPUT);

  // Configuration de la LED Bar
  bar.begin();
}

void loop() {
  int lightValue = analogRead(lightSensorPin);
  Serial.println("Luminosité : " + String(lightValue));

  // Afficher la luminosité sur la LED Bar
  int barLevel = map(lightValue, 0, 800, 0, 10);

  // Walk through the levels
  for (int i = 0; i <= barLevel; i++) {
    bar.setLevel(i);
    delay(100);
  }

  // Contrôler le moteur avec la PWM en fonction de la luminosité
  int motorSpeed = map(lightValue, 0, 1023, 0, 255);
  analogWrite(motorPin, motorSpeed);

  delay(1000);
}
