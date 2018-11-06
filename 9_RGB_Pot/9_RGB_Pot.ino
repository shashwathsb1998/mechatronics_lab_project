void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  Serial.println("Serial Working");

}

void loop() {
  analogWrite(3,20);
  analogWrite(5,40);
  analogWrite(6,60);
  delay(100);
}
