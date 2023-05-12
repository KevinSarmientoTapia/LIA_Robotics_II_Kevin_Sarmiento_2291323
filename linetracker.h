// header file for Line Tracker

// define header file
#ifndef LINETRACKER_H
#define LINETRACKER_H
#include <Arduino.h>

class linetracker{ // initialize the class of the line tracker

private:
int AnalogPin;
int sensor;

public:
linetracker(){}; // Default Constructor
linetracker(int AnalogPin); // Constructor and pins
void begin(); // initialize the pins as outputs
int read(); // read and return values of the sensors
};
#endif
