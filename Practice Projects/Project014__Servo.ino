#include <Servo.h>
const int potentio = A0;
int analogVal;
int analogOut;

Servo thebestservoever;

void setup() {
  thebestservoever.attach(6);
}

void loop() {
  analogVal = analogRead(potentio);
  analogOut = map(analogVal,0,1023,0,179);
  
  thebestservoever.write(0);
  delay(480);
  thebestservoever.write(analogOut);
  delay(480);
}
