/*

  RCA Piezo

  Paul May
  2017

  This example code is in the public domain.

*/

int threshold;

void setup() {
  //The piezo is attached to pin AO, which is an iput
  pinMode(A0, INPUT);
  //start a serial connection
  Serial.begin(9600);
  //set a minimum threshold; play with this
  threshold = 50;
}

void loop() {
  //read from the piezo
  int val = analogRead(A0);
  //send the data over Serial
  //if the reading exceeds our threshold, send one message
  if (val > threshold) {
    Serial.print("knock");
    Serial.print(",");
    Serial.print("1");
    Serial.print(",");
    Serial.println(val);
  }
  //send another message
  else {
    Serial.print("no knock");
    Serial.print(",");
    Serial.print("0");
    Serial.print(",");
    Serial.println(val);
  }
}
