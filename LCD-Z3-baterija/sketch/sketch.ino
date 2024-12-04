#include <LiquidCrystal.h>

#define pot A0

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7

int analogValue;
int percentage;
int batteryIndex;

byte bat0[] = {
  B01110,
  B11011,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111
};

byte bat20[] = {
  B01110,
  B11011,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111,
  B11111
};

byte bat40[] = {
  B01110,
  B11011,
  B10001,
  B10001,
  B10001,
  B11111,
  B11111,
  B11111
};

byte bat60[] = {
  B01110,
  B11011,
  B10001,
  B10001,
  B11111,
  B11111,
  B11111,
  B11111
};

byte bat80[] = {
  B01110,
  B11011,
  B10001,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte bat100[] = {
  B01110,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

void setup() {
  lcd.begin(16, 2);

  lcd.createChar(0, bat0);
  lcd.createChar(1, bat20);
  lcd.createChar(2, bat40);
  lcd.createChar(3, bat60);
  lcd.createChar(4, bat80);
  lcd.createChar(5, bat100);

  pinMode(pot, INPUT);
}

void loop() {
  analogValue = analogRead(pot);
  percentage = map(analogValue, 0, 1023, 0, 100);

  lcd.setCursor(0, 0);
  lcd.print("Baterija: ");
  lcd.print(percentage);
  lcd.print("%");

  displayBatteryPercentage(percentage, 15, 0);

  if (analogValue != analogRead(pot)) lcd.clear();
}

void displayBatteryPercentage(int percentage, int x, int y) {
  lcd.setCursor(x, y);
  batteryIndex = map(percentage, 0, 100, 0, 5);

  lcd.write((byte)batteryIndex);
} 

