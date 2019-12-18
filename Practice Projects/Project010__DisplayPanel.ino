#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

void setup() {
  lcd.begin(16,2);
}

void loop() {
  lcd.home();
  lcd.print("hello");
  delay(1000);

  lcd.setCursor(0,1);
  lcd.print("world");
  delay(1000);

  lcd.clear();
  delay (1000);
}

