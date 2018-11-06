int em = 7;
void setup() {
  // put your setup code here, to run once:
  pinMode(em, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(em ,LOW);
  delay(500);
  digitalWrite(em, HIGH);
  delay(500);
}
