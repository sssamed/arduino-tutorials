#include <LiquidCrystal.h>

#define tempSensorPin A0

LiquidCrystal lcd(9, 8, 7, 6, 5, 4); // rs, en, d4, d5, d6, d7

const int redLedPin = 10;
const int greenLedPin = 11;
const int relayPin = 12;

const int buttonDownPin = 2;
const int buttonUpPin = 3;

int temperature;
int setTemperature = 30;

int analogValue;
float voltage;

void setup() {
  pinMode(buttonDownPin, INPUT_PULLUP);
  pinMode(buttonUpPin, INPUT_PULLUP);

  pinMode(tempSensorPin, INPUT);

  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(relayPin, OUTPUT);

  lcd.begin(16, 2);

  lcd.print("Temp. regulator");
  delay(2000);
  
  lcd.clear();
}

void loop() {
  if (!digitalRead(buttonUpPin) && setTemperature < 100) {
    setTemperature++;
    delay(200);
    lcd.clear();
  }

  if (!digitalRead(buttonDownPin) && setTemperature > 0) {
    setTemperature--;
    delay(200);
    lcd.clear();
  }

  if (analogRead(tempSensorPin) != analogValue) lcd.clear();

  analogValue = analogRead(tempSensorPin);

  voltage = analogValue * (5000 / 1024.0);

  temperature = voltage / 10;

  if (temperature > setTemperature) {
    digitalWrite(relayPin, LOW);
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
  } else {
    digitalWrite(relayPin, HIGH);
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
  }

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Set point: ");
  lcd.print(setTemperature);
  lcd.print((char)223);
  lcd.print("C");
}
