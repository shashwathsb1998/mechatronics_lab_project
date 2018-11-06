#include<Servo.h>
Servo servo1;
int servopin = 6;
int switch1 = 7;
int incomeByte = 0;
void setup() {
  // put your setup code here, to run once:
  servo1.attach(servopin);
  Serial.begin(9600);
  pinMode(switch1,INPUT_PULLUP);

}
int dir  = 1;
void loop() {
  // put your main code here, to run repeatedly:
  int state = 0;
  int ang1 = servo1.read();
  if(Serial.available())
  {
    incomeByte = Serial.read();
  }
  if(incomeByte == 78)
  {
    state = 1;
  }
  else if(incomeByte == 70)
  {
    state = 2;
  }
  else
  {
    state = 0;
  }
  if(state == 1)
  {
    
    if(ang1  ==  180)
    {
      dir  = -1;
    }
    if(ang1 == 0)
    {
      dir = 1;
    }
    servo1.write(ang1 + dir);
    Serial.println(ang1+dir);
  }
  if(state == 2)
{
  Serial.println("Servo is off");
}
if (state ==0)
{
  Serial.println("Prev command was invalid, pls put valid command");
}
  

}
