int currentState = LOW;
int previousState = LOW;
int count = 0;

void setup() {
  pinMode(7, INPUT);
  Serial.begin(9600);
}

void loop() {
  currentState = digitalRead(7);
  if ((currentState == HIGH) && (previousState == LOW))
  {
    count++;
    Serial.println(count);
  }
  previousState = currentState;
  delay(50);
}
