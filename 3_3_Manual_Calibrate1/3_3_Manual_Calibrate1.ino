#include <LiquidCrystal.h>
#include<Servo.h>
const int rs = 2, en = 3, d4 = 4, d5 = 8, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

Servo myservo;
int r = 9;
int g = 10;
int b = 11;
int push_button = 8;
void setup() {
  // put your setup code here, to run once:
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(push_button, INPUT_PULLUP);
   lcd.begin(16, 2);
  pinMode(A2, INPUT);
  myservo.attach(5);
  Serial.begin(9600);
  delay(2000);

}

long val_r = 0;
long val_g = 0;
long val_b = 0;
int state = 0 ;
int angle_inc =1;
int switch_val = 0;
int incomeByte = 0;
void loop() {
  if(Serial.available())
  {
    incomeByte = Serial.read();
  }
  if(incomeByte == 70)
  {
    state = 2;
  }

  if( state == 0)
  {
    myservo.write(30);
    state++;
  }
  else if (state == 1)
  {
      Serial.println("Currently calibrating, type OFF to stop");
      //lcd.println("R :" );
      lcd.print("R:");
      lcd.print(val_r);
      lcd.print("G:");
      lcd.print(val_g);
      lcd.print("B:");
      lcd.print(val_b);
      
      
      
      Serial.println(analogRead(A2));
      digitalWrite(r, HIGH);
      digitalWrite(g, LOW);
      digitalWrite(b, LOW);
      delay(50);
      val_r = analogRead(A2);
      for(int i =0; i<5; i++)
      {
      val_r = val_r + analogRead(A2);
      }
      val_r = val_r/6;
      digitalWrite(r, LOW);
      digitalWrite(g,HIGH);
      digitalWrite(b, LOW);
      delay(50);
      val_g = analogRead(A2);
      for(int i =0; i<5; i++)
      {
      val_g = val_g + analogRead(A2);
      
      }
      val_g = val_g/6;
      digitalWrite(r, LOW);
      digitalWrite(g,LOW);
      digitalWrite(b, HIGH);
      delay(50);
      val_b = analogRead(A2);
      for(int i =0; i<5; i++)
      {
      val_b = val_b + analogRead(A2);      
      }
      val_b = val_b/6;
      lcd.display();
      lcd.clear();
      digitalWrite(r,HIGH);
      
  }
  else
  {
    lcd.clear();
    lcd.print("done");
    Serial.println("manual calib done");
    lcd.display();
    lcd.clear();
    delay(100);
  }
  
 }

