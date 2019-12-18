int analogVal;
float voltage;
float temperature;
const int tempPin = A0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  analogVal = analogRead(tempPin);
  voltage = (analogVal/1024.0)*5.0;
  temperature = 100*voltage-50;
  Serial.println(temperature);
  delay(100);
}


