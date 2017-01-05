int buttonPin;
int potPin = A0;
int fsrPin = A1;
int ledPin = 10;
boolean ledState = LOW;
boolean buttonValue;
boolean lastButtonValue = LOW;

void setup() {
  // put your setup code here, to run once:
  buttonPin = 9;
  potPin = A0;
  pinMode(buttonPin, INPUT);
  pinMode(potPin, INPUT);
  pinMode(fsrPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonValue = digitalRead(buttonPin);
  int potValue = analogRead(potPin);
  int fsrValue = analogRead(fsrPin);

  if (buttonValue != lastButtonValue) {
    //    Serial.println("The button has changed");
    //flip the state of ledState;
    lastButtonValue = buttonValue;
    if (buttonValue == HIGH) {
      ledState = !ledState;
    }
  }

  digitalWrite(ledPin, ledState);
  Serial.print(buttonValue);
  Serial.print(",");
  Serial.print(potValue);
  Serial.print(",");
  Serial.print(fsrValue);
  Serial.print(",");
  Serial.print(ledState);
  Serial.print(",");
  Serial.print("A");
  Serial.println();
}
