#include <LiquidCrystal.h>

const int rs = 2, en = 3, d4 = 4, d5 = 8, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int buttonState = LOW, led=11;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int distance;
  distance = analogRead(A3);
  if(distance>600){
    buttonState = HIGH;
  }
  else{
    buttonState = LOW;
  }
  digitalWrite(led, buttonState);
  Serial.println(distance);
  Serial.println(buttonState);
  lcd.println(distance);
  lcd.println(buttonState);
  lcd.display();
  delay(200);
  lcd.clear();
}




