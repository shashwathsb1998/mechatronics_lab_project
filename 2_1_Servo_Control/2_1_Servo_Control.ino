#include<Servo.h>
Servo servo1;
Servo servo2;
int switch1 = 7;
int switch2 = 8;
void setup() {
  // put your setup code here, to run once:
  servo1.attach(6);
  servo2.attach(5);
  Serial.begin(9600);
  pinMode(switch1,INPUT_PULLUP);
  pinMode(switch2,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:'
  int ang1 = servo1.read();
  int ang2 = servo2.read();
  int switch1_val = digitalRead(switch1);
  int switch2_val = digitalRead(switch2);
//  Serial.println(switch1_val);
  Serial.println(switch2_val);
  if(switch1_val == 0)
    {
      servo2.write(ang1+10);
      delay(200);
    }
   if(switch2_val == 0)
   {
    servo2.write(ang1-10);
    delay(200);
   }

}
