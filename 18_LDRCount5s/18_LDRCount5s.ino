int count = 0;
int currdistance, prevdistance;
void setup() {
  Serial.begin(9600);
}

void loop() {
  currdistance = analogRead(A3);
  Serial.println(count);
  if(currdistance>500 && prevdistance<500 && millis()<5000)
  {
    count++;
  }
  if(millis()>5000)
  {
    Serial.println("Time limit crossed");
  }
  prevdistance = currdistance;
}


