const int inPinR = 4;
const int outPinR = 11;
int currentStateR = LOW;
int previousStateR = LOW;
int outStateR = LOW;

void setup()
{
  pinMode(inPinR, INPUT);
  pinMode(outPinR, OUTPUT);
}

void loop()
{
  currentStateR = digitalRead(inPinR);
  if ((currentStateR == HIGH) && (previousStateR == LOW))
  {
    if (outStateR == LOW)
        outStateR = HIGH);
    else
        outStateR = LOW;
  }
  previousStateR = currentStateR;
  digitalWrite(outPinR, outStateR);
  delay(10);
}

