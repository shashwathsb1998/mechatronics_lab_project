#include <LiquidCrystal.h>
#include<Servo.h>
LiquidCrystal lcd(2,3,4,8,12,13);
Servo myservo;
int clock_pin =2;
int datapin =3;
class Robot
{
 
  public:
  Servo base_servo;
  Servo object_servo;
  int r_led, g_led, b_led, em, LDR;
  Robot()
  {
    base_servo.attach(5);
    object_servo.attach(6);
    
    r_led = 9;
    pinMode(r_led, OUTPUT);
 
    b_led = 11;
    pinMode(b_led, OUTPUT);
    
    g_led = 10;
    pinMode(g_led, OUTPUT);
    
    em = 7;
    pinMode(em, OUTPUT);
    LDR = A3;
    Serial.begin(9600);
    Serial.println("Have completed initialization"); 
    base_servo.write(30);
  }
  void loop_led(int *led_values, int *arr);
  void print_lcd(int *values);
  void find_max_value(int *ldr, int *arr);
  void modify_intensity(int *max_value, int *led_val);
  int check_val(int *ldr_values);
  void glow_led(int colour);
  int sweep();
};

void Robot::loop_led(int* led_values, int *arr)
{
    analogWrite(r_led, led_values[0]);
    analogWrite(g_led, 0);
    analogWrite(b_led, 0);
    delay(150);
    int sum = analogRead(LDR);
    delay(150);
    sum =sum + analogRead(LDR);
    delay(150);
    sum =sum + analogRead(LDR);
    arr[0] = sum/3;
    Serial.print("IN LOOP_LED : ");
    Serial.print(arr[0]);
    delay(550);

    analogWrite(r_led, 0);
    analogWrite(g_led, led_values[1]);
    analogWrite(b_led, 0);
    delay(150);
    sum = analogRead(LDR);
    delay(150);
    sum =sum + analogRead(LDR);
    delay(150);
    sum =sum + analogRead(LDR);
    arr[1] = sum/3;
    arr[1] = analogRead(LDR);
    Serial.print(" IN LOOP_LED : ");
    Serial.print(arr[1]); 
    delay(550);

    analogWrite(r_led, 0);
    analogWrite(g_led, 0);
    analogWrite(b_led, led_values[2]);
    delay(150);
    sum = analogRead(LDR);
    delay(150);
    sum =sum + analogRead(LDR);
    delay(150);
    sum =sum + analogRead(LDR);
    arr[2] = sum/3;
    arr[2] = analogRead(LDR);
    Serial.print(" IN LOOP_LED : ");
    Serial.println(arr[2]); 
    delay(850);
}

void Robot::find_max_value(int *ldr, int *arr)
{
  if(ldr[0] > ldr[1])
  {
    if(ldr[0] > ldr[2])
    {
      arr[0] = ldr[0];
      arr[1] = 0;
    }
    else
    {
      arr[0] = ldr[2];
      arr[1] = 2;

    }
  }
  else
  {
    if(ldr[1] > ldr[2])
    {
      arr[0] = ldr[1];
      arr[1] = 1;
    }
    else
    {
      arr[0] = ldr[2];
      arr[1] = 2;

    }
    
  }
}
void Robot::modify_intensity(int * max_val, int *led_val)
{
  if(max_val[1] == 0)
  {
    led_val[1] = led_val[1] - 5;
    led_val[2] = led_val[2] - 5;
  }
  if(max_val[1] == 1)
  {
    led_val[0] = led_val[0] - 5;
    led_val[2] = led_val[2] - 5;
  }
  if(max_val[1] == 2)
  {
    led_val[0] = led_val[0] - 5;
    led_val[1] = led_val[1] - 5;
  }
}
int Robot::check_val(int *ldr_values)
{
  int i = 0;
  int max_val = -1;
  int min_val = 500;
  while(i<3)
  {
    if(ldr_values[i] > max_val)
    {
      max_val = ldr_values[i];
    }
    if(ldr_values[i] < min_val)
    {
      min_val = ldr_values[i];
    }
    i++;
  }
  if(max_val - min_val > 10)
  {
    return 1;
  }
  else
  {
    return 0;
  }
  
}
void Robot::glow_led(int colour)
{
  if(colour == 0)
  {
    digitalWrite(r_led, HIGH);
    digitalWrite(g_led, LOW);
    digitalWrite(b_led, LOW);
  }
   if(colour == 1)
  {
    digitalWrite(r_led, LOW);
    digitalWrite(g_led, HIGH);
    digitalWrite(b_led, LOW);
  }
   if(colour == 2)
  {
    digitalWrite(r_led, LOW);
    digitalWrite(g_led, LOW);
    digitalWrite(b_led, HIGH);
  }
}
int Robot::sweep()
{
  base_servo.write(30);
  int lowest = 1000;
  int i = 0;
  int lowest_servo = 0;
  while(i < 150)
  {
    int current_val = analogRead(LDR);
    if(current_val < lowest)
    {
      lowest = current_val;
      lowest_servo = base_servo.read();
    }
    base_servo.write(i);
    i++;
    delay(100);
  }
  return lowest_servo;
}
//void Robot::print_lcd(int *ldr)
//{
//  lcd.clear();
//  lcd.print("Hello World");
//  lcd.display();
//}
Robot r1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Please enter auto or manual");

}
int state = 0;
int led_val[3] = {255, 255, 255};
int incoming_byte;
int count  =0;
int max_val[2];
int start_colour = 0;
int end_colour = 0;
int lowest_servo = 0;
int i = 30;
void loop()
{
  r1.glow_led(2);
  if(state == 0   && Serial.available())
  {
    incoming_byte = Serial.read();
  }
  if(incoming_byte == 79 && state == 0)
  {
    state = 1;
  }
  if(incoming_byte == 76 && state == 0)
  {
    state = 2;
  }
  if(state == 2 && Serial.available())
  {
    incoming_byte = Serial.read();  
  }
  if(incoming_byte == 79 && state == 2)
  {
    state = 3;
  }
  if(state == 3 && Serial.available())
  {
    incoming_byte = Serial.read();  
  }
  if(state == 4 && Serial.available())
  {
    incoming_byte = Serial.read();  
  }
  if(incoming_byte == 82 && state == 3)
  {
    state = 4;
    start_colour  = 0;
    incoming_byte = 0;
  }
  if(incoming_byte == 71 && state == 3)
  {
    state = 4;
    start_colour  = 1;
    incoming_byte = 0;

  }
  if(incoming_byte == 66 && state == 3)
  {
    state = 4;
    start_colour  = 2;
    incoming_byte = 0;

  }
  if(incoming_byte == 82 && state == 4)
  {
    state = 5;
    end_colour  = 0;
  }
  if(incoming_byte == 71 && state == 4)
  {
    state = 5;
    end_colour  = 1;
  }
  if(incoming_byte == 66 && state == 4)
  {
    state = 5;
    end_colour  = 2;
  }
  
//  Serial.println(incoming_byte);
  if(state == 1) // This is auto_calibration_state
  {
    
    int ldr[3];
    r1.loop_led(led_val, ldr);
    Serial.println();
    r1.find_max_value(ldr, max_val);
    r1.modify_intensity(max_val, led_val);
    if(r1.check_val(ldr))
    {
     state = 1;
    }
    else
    {
      Serial.println("Auto calibration Complete");
      state = 3;
    }
  }  
  if (state == 2) // This is manual_calibration_state
  {
    Serial.println("PLease type done when done");
    int ldr[3];
    r1.loop_led(led_val, ldr);
    lcd.clear();
    lcd.print("R:");
    lcd.print(ldr[0]);
    lcd.print("G:");
    lcd.print(ldr[1]);
    lcd.print("B:");
    lcd.print(ldr[2]);
    lcd.display();
  }
  if (state == 3)
  {
    Serial.println("Please enter 2 colours");
  }
  if(state == 4)
  {
    Serial.println("First colour received please enter next colour");
  }
  if(state == 5)
  {
    if(count == 0)
    {
      Serial.println("Both colours received, proceeding to work");
      count++;
      r1.base_servo.write(30);

    }
     if(count  == 1)
    {
      int ang = r1.base_servo.read();
      r1.base_servo.write(ang+1);
      delay(100);
    }
  }
  

}


