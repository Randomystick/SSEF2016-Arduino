void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
}

void loop() {
  int minLevel = 1023;
  int maxLevel = 0;
  for (int i=0; i<500; i++)
  {
    int soundLevel = analogRead(A0);
    maxLevel = max(maxLevel, soundLevel);
    minLevel = min(minLevel, soundLevel);
  }
  int amplitude = maxLevel - minLevel;
  if (amplitude>50)
     digitalWrite(8, HIGH);
  else
     digitalWrite(8, LOW);
  delay(20);
  Serial.println(amplitude);

}
