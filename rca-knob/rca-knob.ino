/*
RCA Potentiometer
*/



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
  int leftSensorValue = analogRead(A2);
  int rightSensorValue = analogRead(A3);
  
  
  // print out the value you read:
  Serial.print(leftSensorValue,DEC);
  Serial.print(",");
  Serial.print(rightSensorValue,DEC);
  Serial.print("\n");
}
