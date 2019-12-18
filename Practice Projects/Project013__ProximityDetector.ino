const int transistorPin = A5; 
int transistorValue;

void setup() {
  Serial.begin(9600);
  pinMode (transistorPin, INPUT);
}

void loop() {
  transistorValue = analogRead(transistorPin);
  Serial.println(transistorValue);
  delay(20);
}
