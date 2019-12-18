int analogVal;
const int ldrPin = A4;
const int ledPin = 5;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  analogVal = analogRead(ldrPin);
  Serial.println(analogVal);
  if (analogVal<600)
      digitalWrite(ledPin, HIGH);
  else
      digitalWrite(ledPin, LOW);
  delay(20);

}
