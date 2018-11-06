int led1 = 11;
void setup() {
  // put your setup code here, to run once:
        Serial.begin(9600);
        pinMode(A2,INPUT);
        pinMode(led1,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val =  analogRead(A2);
  Serial.println(val);
  if(val > 500)
  {
    digitalWrite(led1,HIGH);
  }
  else
  {
    digitalWrite(led1, LOW);
  }
  

}
