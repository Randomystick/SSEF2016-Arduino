 // Topmost button | Red
const int inPinR = 4;
const int outPinR = 11;
int currentStateR = LOW;
int previousStateR = LOW;
int outStateR = LOW;

// Niddle button | Green
const int inPinG = 3;
const int outPinG = 10;
int currentStateG = LOW;
int previousStateG = LOW;
int outStateG = LOW;

// Lowest button | Blue
const int inPinB = 2;
const int outPinB = 9;
int currentStateB = LOW;
int previousStateB = LOW;
int outStateB = LOW;

void setup()
{
  pinMode(inPinR, INPUT);
  pinMode(outPinR, OUTPUT);

  pinMode(inPinG, INPUT);
  pinMode(outPinG, OUTPUT);

  pinMode(inPinB, INPUT);
  pinMode(outPinB, OUTPUT);
}

void loop()
{
  //RED
  currentStateR = digitalRead(inPinR);
  if ((currentStateR == HIGH) && (previousStateR == LOW))
  {
    if (outStateR == LOW)
        outStateR = HIGH;
    else
        outStateR = LOW;
  }
  previousStateR = currentStateR;
  digitalWrite(outPinR, outStateR);
  delay(10);


  //GREEN
  currentStateG = digitalRead(inPinG);
  if ((currentStateG == HIGH) && (previousStateG == LOW))
  {
    if (outStateG == LOW)
        outStateG = HIGH;
    else
        outStateG = LOW;
  }
  previousStateG = currentStateG;
  digitalWrite(outPinG, outStateG);
  delay(10);

  //BLUE
  currentStateB = digitalRead(inPinB);
  if ((currentStateB == HIGH) && (previousStateB == LOW))
  {
    if (outStateB == LOW)
        outStateB = HIGH;
    else
        outStateB = LOW;
  }
  previousStateB = currentStateB;
  digitalWrite(outPinB, outStateB);
  delay(10);
}

