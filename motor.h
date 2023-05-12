// header file for motor class

// To define the Button class:
#ifndef MOTOR_H
#define MOTOR_H
#include <Arduino.h> //We include the Arduino library

class motor{ // To open a class called Button

private: // Place where variables and functions will be hidden from the user
int Pin; // Pin for motor that will always be on.
int MotorA; // Motor A of the car
int MotorB; // Motor B of the car
int PWMA; // PWMA (Pulse With Modulation A)
int PWMB; // PWMB (Pulse With Modulation B) 

public: // Place where variables, functions and methods will be open for the user to use
motor(){};//default constructor
motor(int Pin, int MotorA, int PWMA, int MotorB, int PWMB);//constructor
void begin();//initialize pins for motors
void forward(int x);//go fordward
void backward(int x);//go backward
void left(int x);//turn left
void right(int x);//turn right
void Stop();//stop
void forward_left(int x);//keep going forward turning to the left
void forward_right(int x);//keep going forward turning to the right
};

#endif