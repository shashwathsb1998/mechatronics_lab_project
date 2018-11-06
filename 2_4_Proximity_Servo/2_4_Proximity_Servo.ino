#include<Servo.h>
Servo servo1;
int servopin = 6;
int ir1 = A2;
int led1 = 11;
void setup() {
  // put your setup code here, to run once:
  servo1.attach(servopin);
  pinMode(ir1,INPUT);
  pinMode(led1,OUTPUT);
  Serial.begin(9600);

}
int dir  = 1;
int state = 0;
void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(ir1);
  int  ang1 = servo1.read();
  if(val > 100)
  {
    state = 0;
    digitalWrite(led1,HIGH);
  }
  else
  {
    state = 1;
    digitalWrite(led1,LOW);
  }
  
  if(state == 1)
  {
    Serial.println("In Sweep Mode");
    if(ang1  ==  180)
    {
      dir  = -1;
    }
    if(ang1 == 0)
    {
      dir = 1;
    }
    servo1.write(ang1 + dir);
  }
  if(state == 0)
{
  Serial.println("Obstacle is nearby");
  Serial.println(val);
}


}
