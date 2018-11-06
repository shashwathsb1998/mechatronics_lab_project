const int buttonPin1 = 7; 
const int ledPin1 =  11;      
const int buttonPin2 = 8; 
const int ledPin2 =  12;      
const int buttonPin3 = 9; 
const int ledPin3 =  13;      
// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;
int buttonState3 = 0;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(ledPin3, OUTPUT);
  pinMode(buttonPin3, INPUT_PULLUP);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  
  if (buttonState1 == HIGH) {
    digitalWrite(ledPin1, HIGH);    
  } else {
    digitalWrite(ledPin1, LOW);
  }
  if (buttonState2 == HIGH) {
    digitalWrite(ledPin2, HIGH);    
  } else {
    digitalWrite(ledPin2, LOW);
  }
  if (buttonState3 == HIGH) {
    digitalWrite(ledPin3, HIGH);    
  } else {
    digitalWrite(ledPin3, LOW);
  }
}
