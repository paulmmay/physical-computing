/*
   RCA Button

   Paul May
   2017

*/

const int buttonPin = 11;     // the number of the pushbutton pin
const int ledPin =  14;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int lastButtonState = 0;     // variable for checking the last pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  // initialize a Serial connection to the computer
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    Serial.print("down");
    Serial.print(",");
    Serial.println("1");
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    Serial.print("up");
    Serial.print(",");
    Serial.println("0");
  }
}
