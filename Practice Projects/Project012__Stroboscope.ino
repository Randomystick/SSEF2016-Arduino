const int ledPin = 5;
int analogVal;
int lowDelay;
int period;

void setup() {
  pinMode (ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogVal = analogRead(A0);
  lowDelay = map(analogVal,0,1023,30,1000);
  
  digitalWrite (ledPin, HIGH);
  delay(10);
  digitalWrite (ledPin, LOW);
  delay(lowDelay);
  period = (10+lowDelay);
  Serial.println( 60000/period);

}
