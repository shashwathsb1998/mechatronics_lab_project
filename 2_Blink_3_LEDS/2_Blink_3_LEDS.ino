void setup() {  
  // initialize the LED pin as an output:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(11, LOW);
}
