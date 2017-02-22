/*
   
 RCA Piezo
 
 Paul May
 2017
 
 This example code is in the public domain. 
 
 */


import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;      // Data received from the serial port
int lf = 10;
String serialVal;
color[] colours = {
  #F2f2f2, #ADDAEA, #cccccc, #FAFAFA, #6F0D0D, #E8E8E8, #B0D748, #DB4050, #222222, #98B8E0, #ffb90f, #1e90ff
};

PFont font;
PFont bigfont;

void setup() 
{
  smooth();
  size(720, 400);
  //My serial connection is at port 1
  String portName = Serial.list()[1];
  println(Serial.list());
  myPort = new Serial(this, portName, 9600);
  //set the initial background colour
  background(colours[0]);
}

void draw() {
  if (myPort.available() > 0) {
    while (myPort.available() > 0) { //as long as there is data coming from serial port, read it and store it 
      serialVal = myPort.readStringUntil(lf);
    }
    if (serialVal != null) {  //if the string is not empty, print the following;
      println(serialVal);

      noStroke();
      Integer values[] = {0, 0, 0, 0};
      String dirtyValues[] = {};
      
      //unpack the message from the arduino
      //we're expecting information separated by commas
      //for the accompanying Arduino code, we expect "no knock,0,NN" or "knock,1,NN" to be sent from the Arduino over serial
      //where NN is the value
      dirtyValues = serialVal.split(",");

      //let's discard knock and no knock, and just keep 0,NN and 1,NN
      values[0] = parseInt(trim(dirtyValues[1]));

      //show a filled box when the led state is high
      if (values[0] == 1) {
        background(colours[10]);
      } else {
        background(colours[0]);
      }
    }
  }
}