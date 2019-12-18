//Super unreliable because of remnant charges making the light go crazy
//But can detect in proximity
#include <CapacitiveSensor.h>

CapacitiveSensor capSensor_2_4 = CapacitiveSensor(6,7);

const int pinR = 13;
const int pinG = 12;
const int pinB = 11;


void setup() {
  Serial.begin(9600);
  
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
  digitalWrite(pinG, LOW);
}

void loop() {
  long value1=capSensor_2_4.capacitiveSensor(30);
  Serial.println(value1);
  Serial.print("\t");
  delay(10);

  // First Pin | Red Light
  if (value1>70)
    digitalWrite(pinR, HIGH);
  else
    digitalWrite(pinR, LOW); }
  
  // Second Pin | Blue Light   

