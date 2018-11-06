#include <LiquidCrystal.h>

const int rs = 2, en = 3, d4 = 4, d5 = 8, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  int distance;
  distance = analogRead(A3);
  Serial.println(distance);
  lcd.print(distance);
  lcd.display();
  delay(200);
  lcd.clear();
}




