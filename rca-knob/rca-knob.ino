/*

  RCA Knob / Dial / Potentiometer

  Paul May
  2017

  This example code is in the public domain.

*/

int potValue;
int smoothValues[] = {0, 0, 0, 0, 0};
int smoothPosition = 0;
int smoothedValue = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  potValue = analogRead(A0);
  smoothValues[smoothPosition] = potValue;

  //get the average of the last 5 vals
  int smoothTotal = 0;
  int smoothAverage = 0;
  for (int i = 0; i <= 4; i++) {
    smoothTotal = smoothTotal + smoothValues[i];
  }
  if (smoothPosition == 4) {
    smoothedValue = smoothTotal / 5;
    smoothPosition = 0;
  }
  else {
    smoothPosition = smoothPosition + 1;
  }

  // print out the value you read:
  Serial.print("pot");
  Serial.print(",");
  Serial.print(potValue);
  Serial.print(",");
  Serial.println(smoothedValue);
}
