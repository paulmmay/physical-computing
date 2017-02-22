/*

  RCA Force Sensing Resistor

  Paul May
  2017

  This example code is in the public domain.

*/

int light_threshold;
int moderate_threshold;
int heavy_threshold;
String message;
int levelNumber;

void setup() {
  //The piezo is attached to pin AO, which is an iput
  pinMode(A0, INPUT);
  //start a serial connection
  Serial.begin(9600);
  //set a minimum threshold; play with this
  light_threshold = 200;
  moderate_threshold = 600;
  heavy_threshold = 800;
}


void loop() {
  //read from the FSR
  int val = analogRead(A0);
  //send the data over Serial
  //if the reading exceeds our threshold, send one message

  //pressure is below our light threshold
  if (val < light_threshold) {
    message = "no pressure";
    levelNumber = 0;
  }

  //pressure is above our light threshold
  //but below our moderate threshold
  if (val > light_threshold && val < moderate_threshold) {
    message = "light pressure";
    levelNumber = 1;
  }

  //pressure is above our moderate threshold
  //but below our heavy threshold
  if (val > moderate_threshold && val < heavy_threshold) {
    message = "moderate pressure";
    levelNumber = 2;
  }


  //pressure is above our heavy threshold
  if (val > heavy_threshold) {
    message = "heavy pressure";
    levelNumber = 3;
  }


  Serial.print(message);
  Serial.print(",");
  Serial.print(levelNumber);
  Serial.print(",");
  Serial.println(val);
}
