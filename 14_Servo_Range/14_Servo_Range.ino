/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = -180;    // variable to store the servo position

void setup() {
  myservo.attach(5);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);

}

void loop() {
    // in steps of 1 degree
    myservo.write(pos);
    pos++;
    delay(15);   
    Serial.println(pos);
    // waits 15ms for the servo to reach the position
  if(pos>180)
  {
    pos=-180;
  }
}

