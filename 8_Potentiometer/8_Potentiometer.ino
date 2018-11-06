void setup() {
  // put your setup code here, to run once:
  pinMode(A4, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Serial Working");

}

void loop() {
  int a  = analogRead(A4);
  Serial.println(a);
  delay(100);
  

}
