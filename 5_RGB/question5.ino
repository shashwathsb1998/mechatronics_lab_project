int i=0;
int j=0;
int k=0;
void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

}

void loop() {
  
  analogWrite(3, i);
  analogWrite(5, j);
  analogWrite(6, k);
  i=i+19;
  k=k+20;
  j=j+31;
  if(i>255)
  {
    i=0;
  }
  if(j>255)
  {
    j=0;
  }
  if(k>255)
  {
    k=0;
  }
  delay(100);

}
