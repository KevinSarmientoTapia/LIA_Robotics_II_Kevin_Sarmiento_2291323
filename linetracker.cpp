// CPP file for Line Tracker
#include "linetracker.h" // includes the line tracker header file we created

linetracker::linetracker(int AnalogPin){ // constructor to specify the pin in which the sensor is connected
  int sensor;
  this->AnalogPin=AnalogPin;
  this->sensor=sensor;
}

void linetracker::begin(){ // initialize the pins as outputs
  pinMode(AnalogPin, INPUT);
}

int linetracker::read(){ // read and return values of the sensors
  sensor=analogRead(AnalogPin);
  return sensor;
}
