int em =7;
int ir1 = A2;
void setup() {
  // put your setup code here, to run once:
  pinMode(em, OUTPUT);
  pinMode(ir1, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val =analogRead(ir1);
  if(val > 100)
  {
    digitalWrite(em,HIGH);
  }
  else
  {
    digitalWrite(em,LOW);
  }
}
