// 21 Dec: working


#include <LiquidCrystal.h>
#include <elapsedMillis.h>
#include <CapacitiveSensor.h>

elapsedMillis timerCOOLDOWN;
elapsedMillis tiltsensorBUFFER;

// == Capacitive Sensor Framework ==
CapacitiveSensor capSensor_12_13 = CapacitiveSensor(6,7);
elapsedMillis CapStimer;
#define CapSinterval 5000
long oldValue;
long newValue;

const int numReadings = 10;
int readings[numReadings];
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average
int storedValue;


// == LCD Framework ==
LiquidCrystal lcd(13,12,11,10,9,8);


// == LED Framework ==
const int LEDPin = A2;
elapsedMillis timerLED;               //measures duration of LED state
#define intervalLED1 250             //how long LED is on/off
#define intervalLED2 100


// == Music Framework ==
const int SpeakerPin = 5;
int note;               // to indicate which note is being played. Value of 0 rep first note
int note2;
elapsedMillis timerMUSIC;             //measures how long the sound has been playing
#define intervalMUSIC1 250            //how long the freq is played
#define intervalMUSIC2 100


// == Tri-colour LED Framework ==
const int ledPinR = 4;
const int ledPinG = 3;
const int ledPinB = 2;
int brightR;
int brightG;
int brightB;
int triLEDrepeat;
elapsedMillis timerTriLED;
#define intervalTriLED 50


// == Tilt Sensor Framework ==
int currentState = LOW;
int previousState = LOW;
int count = 0;
int TSPin = A0;


// == Timer Framework ==
elapsedMillis timerAlarm;
elapsedMillis timerAlarm2;

//____________________________________________________________________________________


void setup() {
  Serial.begin(9600);

  timerCOOLDOWN = 0;
  tiltsensorBUFFER = 0;
  
  // ~~ LCD Set-up ~~
  lcd.begin(16,2);
  lcd.print("Object secure");

    
  // ~~ LED Set-up ~~
  pinMode(LEDPin, OUTPUT);
  digitalWrite(LEDPin, LOW);
  timerLED = 0;


  // ~~ Music Set-up ~~
  timerMUSIC = 0;
  note = 0;
  note2 = 0;


  // ~~ Tri-colour LED Set-up ~~
  pinMode(ledPinR, OUTPUT);
  pinMode(ledPinG, OUTPUT);
  pinMode(ledPinB, OUTPUT);


  // ~~ Tilt Sensor Set-up ~~
  pinMode(TSPin, INPUT);
  timerAlarm = 0;
  timerAlarm2 = 0;

}   // END SET-UP

//____________________________________________________________________________________


void loop() {
  // Finding Average CapSensor Reading:
  total = total - readings[readIndex];                         // subtract the last reading
  readings[readIndex] = capSensor_12_13.capacitiveSensor(30); // read from the sensor
  total = total + readings[readIndex];                       // add the reading to the total
  readIndex = readIndex + 1;                                // advance to the next position in the array
  if (readIndex >= numReadings) {                          // if the end of the array is reached,
    readIndex = 0; }                                      // wrap around to the beginning:
  average = total / numReadings;                         // calculate the average:

  newValue = average;
  if (CapStimer > CapSinterval) {             // stores a new value for oldValue
    CapStimer -= CapSinterval;               // every x ms
    oldValue = average;
 }
  Serial.println(oldValue);
  Serial.print("\t");
  Serial.println(newValue);
 

  //  C A P A C I T I V E  S E N S O R
  if ( ((millis()) >= 5100) &&  ((newValue - oldValue) >= 10) && (tiltsensorBUFFER > 5000) ){
    timerLED = 0;
    timerMUSIC = 0;    
    timerAlarm = 0;
    timerAlarm2 = 0;
    timerTriLED = 0;
    
    // When object touched | LCD
    
    lcd.home();
    lcd.print("WARNING:        ");
    lcd.setCursor(0,1);
    lcd.print("Intruder Alert! ");

    while ((timerAlarm <= 500) && (timerCOOLDOWN > 100)) {
    
        // When object touched | LED
        if (timerLED > intervalLED1) {
          timerLED -= intervalLED1;         //reset timer
          digitalWrite(LEDPin, !digitalRead(LEDPin)); }
        
        // When object touched | Music
        switch(note)
        {
        case 0:       //for first note
            tone (SpeakerPin,262,250);
            break;
        case 1:      //for second note
            tone (SpeakerPin,310,250);
            break;
        }
        if (timerMUSIC >= intervalMUSIC1)
        {
           timerMUSIC -= intervalMUSIC1;
           note = !note; }
      
        } // CLOSING "WHILE" FUNCTION
 
    digitalWrite(LEDPin, LOW);
    lcd.clear();
    lcd.home();
    lcd.print("Intruder alarm");
    lcd.setCursor(0,1);
    lcd.print("was sounded.");
    timerCOOLDOWN = 0; }



  //  T I L T  S E N S O R
  currentState = digitalRead(TSPin);
  if ( ((millis()) >= 1000) && (currentState == HIGH) && (previousState == LOW)) {
    count++;
    // Serial.println(count);         // TILT SENSOR COUNTER
    timerLED = 0;
    timerMUSIC = 0;
    timerAlarm = 0;
    timerAlarm2 = 0;
    timerTriLED = 0;
    tiltsensorBUFFER = 0;

    
    // When object moved | LCD    
    lcd.home();
    lcd.print("WARNING!!!      ");
    lcd.setCursor(0,1);
    lcd.print("Object stolen!! ");


    while ((timerAlarm2 <= 200) && (timerCOOLDOWN > 100)) {
    
      // When object moved | LED
      if (timerLED > intervalLED2) {
        timerLED -= intervalLED2;
        digitalWrite(LEDPin, !digitalRead(LEDPin)); }

      // When object moved | Music
      switch(note2) {
        case 0:
          tone (SpeakerPin, 1000,250);
          break;
        case 1:
          tone (SpeakerPin, 2000, 250);
          break;
      }
      if (timerMUSIC >= intervalMUSIC2) {
        timerMUSIC -= intervalMUSIC2;
        note2 = !note2;
      } 


    // When object moved | Tri-colour LED
    
      brightR=random(2);
      brightG=random(2);
      brightB=random(2);
      if (timerTriLED >= intervalTriLED)
      {
        timerTriLED -= intervalTriLED;
        digitalWrite(ledPinR, brightR);
        digitalWrite(ledPinG, brightG);
        digitalWrite(ledPinB, brightB);
      }
    

    } // CLOSING "WHILE" LOOP
    digitalWrite(LEDPin, LOW);
    digitalWrite(ledPinR, LOW);
    digitalWrite(ledPinG, LOW);
    digitalWrite(ledPinB, LOW);
    lcd.clear();
    lcd.home();
    lcd.print("WARNING: OBJECT");
    lcd.setCursor(0,1);
    lcd.print("WAS STOLEN!!");
    timerCOOLDOWN = 0;
    delay(100);
  } // CLOSING "IF" FUNCTION
  previousState = currentState;
  delay(50);


}   // END LOOP

