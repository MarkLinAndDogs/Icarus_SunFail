//Add 2 button features (completed)
//Add a sensor feature (if we can)
//Add a light feature, where the button on the sun can only activate once the other servo interacts with the sensor
//Try to brainstorm and improve on current code

//Servo set-up
#include <Servo.h>
Servo towerservo;  //create

//Tower button set-up
const int buttonTPin = 4;  //Placeholder pin number
int buttonTState = 0;
int prevButtonTState = 0;
bool T = false;

//Sun button set-up
const int buttonSPin = 8;  //Placeholder pin number
int buttonSState = 0;
int prevButtonSState = 0;
bool S = false;

void setup() {
  
  pinMode(buttonTPin, INPUT);
  pinMode(buttonSPin, INPUT);
  Serial.begin(9600);
  Serial.println("Start Tower Button")
}

void loop() {
  buttonTState = digitalRead(buttonTPin);

  //Read Tower Button
  if (buttonTState != prevButtonTState) {
    if (buttonTState == HIGH) {
      T = true;
      Serial.println("Start Sun button");
    }
  }
}

//
