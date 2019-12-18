int analogVal;
int analogOut;
const int tempPin = A0;
const int ledPin = 5;

void setup() {
   pinMode(ledPin, OUTPUT);
}

void loop() {
  analogVal = analogRead(tempPin);
  analogOut = map(analogVal,0,1023,0,255);
  analogWrite(ledPin,analogOut);
  delay(100);
}
