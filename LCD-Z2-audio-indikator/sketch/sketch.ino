#include <LiquidCrystal.h>

#define pot A0

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7

int analogValue;
int volume;
int progressBar;

byte customChar[] = {
  B11111,
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
  lcd.createChar(0, customChar);

  pinMode(pot, INPUT);
}

void loop() {
  analogValue = analogRead(pot);
  volume = map(analogValue, 0, 1023, 0, 100);
  progressBar = map(analogValue, 0, 1023, 0, 16);

  lcd.setCursor(0, 0);
  lcd.print("Zvuk: ");
  lcd.print(volume);

  lcd.setCursor(0, 1);
  for (int i = 0; i < progressBar; i++) {
    lcd.write((byte)0);
  }

  if (analogValue != analogRead(pot)) lcd.clear();
}

