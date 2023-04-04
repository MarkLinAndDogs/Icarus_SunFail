//Add 2 button features
//Add a sensor feature (if we can)
//Add a light feature, where the button on the sun can only activate once the other servo interacts with the sensor
//Try to brainstorm and improve on current code

//Tower button set-up
const int buttonTPin = 4; //Placeholder pin number
int buttonTState = 0;

//Sun button set-up
const int buttonSPin = 8; //Placeholder pin number
int buttonSState = 0;

void setup() {
  pinMode(buttonTPin, INPUT);
  pinMode(buttonSPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonTState = digitalRead(buttonTPin);

}
