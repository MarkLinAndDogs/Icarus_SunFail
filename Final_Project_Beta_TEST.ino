//Servo set-up
#include <Servo.h>
Servo towerservo;  //creates a servo variable for the tower
Servo sunservo;    //creates a servo variable for the sun

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

//Tower Servo counter setup
int tservoVal = 0;
int tcounter = 0;
int countercurrentState = 0;
int counterpreviousState = 0;

// This code is the basic set-up for all of the inputs.
void setup() {
  sunservo.attach(9);
  towerservo.attach(10);
  pinMode(buttonTPin, INPUT);
  pinMode(buttonSPin, INPUT);
  Serial.begin(9600);
  Serial.println("Start Tower Button");
  towerservo.write(0);
  sunservo.write(0);
}

// Overview of all of the servo code
void loop() {
  //These two read the buttons
  buttonTState = digitalRead(buttonTPin);
  tservoVal = digitalRead(buttonTPin);

  //This reads & applies the counter for the servo to move step by step.
  if (tservoVal == HIGH) {
    countercurrentState = 1;
  } else {
    countercurrentState = 0;
  }

  // The entire Tower code.
  if (countercurrentState != counterpreviousState) {
    if (countercurrentState == 1) {
      tcounter = tcounter + 1;
      if (tcounter >= 5) {
        towerservo.write(75);
      } else {
        towerservo.write(10 * tcounter);
      }
      Serial.println(tcounter);
    }
  }

  // The sun code.  It reads off from the Tower code with the counter.  Once the counter is at max, then the sun code can work
  if (tcounter == 3) {
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

  //The end code.
  if (S == true) {
    Serial.println("The End");
  }

  //Button state code
  prevButtonTState = buttonTState;
  prevButtonSState = buttonSState;
  counterpreviousState = countercurrentState;
}
