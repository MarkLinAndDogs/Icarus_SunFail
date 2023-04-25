//Add 2 button features (completed)
//Placeholder comment
//Add a light feature, where the button on the sun can only activate once the other servo interacts with something (no clue on the work around as of now)
//Try to brainstorm and improve on current code

//Servo set-up
#include <Servo.h>
Servo towerservo;  //creates a servo variable for the tower
Servo sunservo;    //creates a servo variable for the sun

//Pin number for the led
const int sunledPin = 13;

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

//Servo counter setup


//Tower button set-up
const int buttonRPin = 2;  //Placeholder pin number
int buttonRState = 0;
int prevButtonRState = 0;
bool R = false;

void setup() {
  sunservo.attach(9);
  towerservo.attach(10);
  pinMode(buttonRPin, INPUT);
  pinMode(buttonTPin, INPUT);
  pinMode(buttonSPin, INPUT);
  pinMode(sunledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Start Tower Button");
  towerservo.write(0);
  sunservo.write(0);
}

void loop() {
  buttonTState = digitalRead(buttonTPin);

  //Read Tower Button
  if (buttonTState != prevButtonTState) {
    if (buttonTState == HIGH) {
      T = true;
      towerservo.write(110);
      Serial.println("Start Sun button");
    } else {
      towerservo.write(0);
    }
  }

  //if tower button is true, read the sun button
  if (T == true) {
    digitalWrite(sunledPin, HIGH);
    buttonSState = digitalRead(buttonSPin);
    if (buttonSState != prevButtonSState) {
      if (buttonSState == HIGH) {
        S = true;
        sunservo.write(110);
        Serial.println("Start Sun button");
      } else {
        sunservo.write(0);
      }
    }
  }

  if (S == true) {
    Serial.println("The End");
  }

  if (T == true && S == true) {
   buttonRState = digitalRead(buttonRPin);
    if (buttonRState != prevButtonRState) {
      if (buttonRState == HIGH) {
        R == true;
        S == false;
        digitalWrite(sunledPin, LOW);
      }
    }
  }

  prevButtonTState = buttonTState;
  prevButtonSState = buttonSState;
  prevButtonRState = buttonRState;
}

//Practice for the counter code
