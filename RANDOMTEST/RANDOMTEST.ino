int red = 9;
int g = 10;
int b = 11;
void setup() {
  // put your setup code here, to run once:
  pinMode(red,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(b,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(red,LOW);
  digitalWrite(g,LOW);
  digitalWrite(b,HIGH);

}
