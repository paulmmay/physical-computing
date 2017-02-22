/*
   
 RCA Knob / Dial / Potentiometer
 
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
Integer values[] = {0, 0, 0, 0};
String dirtyValues[] = {};

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
  background(colours[0]);
  if (myPort.available() > 0) {
    while (myPort.available() > 0) { //as long as there is data coming from serial port, read it and store it 
      serialVal = myPort.readStringUntil(lf);
    }
    if (serialVal != null) {  //if the string is not empty, print the following;
      //println(serialVal);

      //unpack the message from the arduino
      //we're expecting information separated by commas
      //for the accompanying Arduino code, we expect pot,NN,NN from the Arduino over serial
      dirtyValues = serialVal.split(",");

      //let's discard pot just keep NN and NN
      values[0] = parseInt(trim(dirtyValues[1]));
      values[1] = parseInt(trim(dirtyValues[2]));

    }
  }
  fill(colours[10]);
  noStroke();
  float mappedXposition = map(values[1], 0, 1023, 100, width-100);
  ellipse(mappedXposition, height/2, 50, 50);
}