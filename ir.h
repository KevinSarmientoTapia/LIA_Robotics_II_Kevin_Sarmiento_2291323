// header file for IR class

// To define the IR class:
#ifndef IR_H
#define IR_H
#include <Arduino.h> //We include the Arduino library

class ir{ // To open a class called ir

private: // Place where variables and functions will be hidden from the user
int IR; 
long duration[32]; 
int x=0; 
byte bits[32]; 
int start_pulse; 
int key_code=0; 

public: // Place where variables, functions and methods will be open for the user to use
ir(){}; //default constructor
ir(int IR); //constructor to define IR pin
void read(); // read IR pulse
int keycode(); // read key_code pressed and returns the value
};

#endif
