#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int delayTime = 200;
String s = "Rudolf";

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
}


void loop() {
  lcd.clear();

  for (int i = 0; i < s.length(); i++) {
    scrollInFromRight(s[i], i);
  }

  delay(5000);
}

void scrollInFromRight(char letter, int position) { 
  for (int i = 15; i >= position; i--) { 
    lcd.setCursor(i + 1, 0);
    lcd.print(" ");
    lcd.setCursor(i, 0);
    lcd.print(letter); 
    delay(delayTime);
  }
}
