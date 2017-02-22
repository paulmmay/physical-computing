

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
  //change line 21 to match your computer's configuration
  //on my computer - my USB port, which receives the 
  //serial data is port 1, so I use Serial.list()[1].

  String portName = Serial.list()[1];
  println(Serial.list());
  myPort = new Serial(this, portName, 9600);
  //background(colours[0]);
}

void draw() {
  background(colours[0]);
  while (myPort.available() > 0) { //as long as there is data coming from serial port, read it and store it 
    serialVal = myPort.readStringUntil(lf);
  }
  if (serialVal != null) {  //if the string is not empty, print the following;
    println(serialVal);

    noStroke();
    Integer values[] = {0, 0, 0, 0};
    String dirtyValues[] = {};
    dirtyValues = serialVal.split(",");

    //the button
    values[0] = parseInt(trim(dirtyValues[0]));
    //the pot
    values[1] = parseInt(trim(dirtyValues[1]));
    //the fsr
    values[2] = parseInt(trim(dirtyValues[2]));
    //the led state
    values[3] = parseInt(trim(dirtyValues[3]));

    //mapped values
    float mappedFSR = map(values[2], 0, 1000, 0, height/2);
    fill(colours[6]);
    ellipse(width/2, height/2, values[1], values[1]);

    //output the FSR data
    fill(colours[7]);
    ellipse((width/2)/2, height/2, mappedFSR, mappedFSR);


    //output the button data
    fill(colours[10]);
    int boxHeight = 100;

    //show a filled box when the led state is high
    if (values[3] == 1) {
      rect(width/2+width/4-boxHeight/2, height/2-boxHeight/2, boxHeight, boxHeight);
    }

    //show a stroke/flash when the button is pushed
    int flashHeight = 20;
    fill(colours[11]);
    if (values[0] == 1) {
      rect(0, 0, width, flashHeight);
      rect(0, height-flashHeight, width, flashHeight);
    }
  }
}