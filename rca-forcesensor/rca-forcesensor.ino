/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
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
  int sensorValue = analogRead(A1);
  // print out the value you read:
  Serial.println(sensorValue,DEC);
  
  if (sensorValue >= 700) {
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
  }
  else {
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
  }

   float frequency = map(sensorValue, 600, 1000, 200, 800);
   // change the pitch, play for 10 ms:
   tone(5, frequency, 10);

   
//  delay(1);        // delay in between reads for stability
}
