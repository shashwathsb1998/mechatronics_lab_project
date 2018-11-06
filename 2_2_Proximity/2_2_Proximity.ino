
void setup() {
  // put your setup code here, to run once:
        Serial.begin(9600);
        pinMode(A4,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val =  analogRead(A4);
  Serial.println(val);
  

}
