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

int pos = 0;    // variable to store the servo position

void setup() {
  pinMode(A2,INPUT);
  myservo.attach(5);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);

}

void loop() {
    // in steps of 1 degree
    pos=analogRead(A2);
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);    
    Serial.println(pos);
    // waits 15ms for the servo to reach the position
  
}

