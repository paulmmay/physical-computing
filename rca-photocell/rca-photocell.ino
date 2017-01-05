
int lowerRange = 600;
int higherRange = 1000;
int lowerTone = 200;
int higherTone = 800;
int lightThreshold = 700;
int greenPin = 6;
int redPin = 7;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A1);
  // print out the value you read:
  Serial.println(sensorValue, DEC);
  // map the sensor value to a range suitable for making a tone
  float frequency = map(sensorValue, lowerRange, higherRange, lowerTone, higherTone);

  //output the tone
  tone(5, frequency, 10);

  // make a decision - is the light above a threshold
  if (sensorValue >= lightThreshold) {
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
  }
  else {
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, HIGH);
  }


}
