//Header file for obstacle mode

// Define obstacle mode header file
#ifndef OBSTACLEMODE_H
#define OBSTACLEMODE_H
#include <Arduino.h> //We include the Arduino library
#include <NewPing.h> // Includes the library "<NewPing.h>" to be able to use the ultrasonic sensor.
#include <Servo.h> // Includes the library Servo motor to program the servo motor.

class obstaclemode{ // To open a class called obstacle mode

private: // Place where variables and functions will be hidden from the user
int distance;
int distance_right;
int distance_left;
int servo;

public: // Place where variables, functions and methods will be open for the user to use
obstaclemode(){}; // default constructor 
obstaclemode(int servo); // constructor to set pins
void begin(); // initialize pins for the class
int Rightdistance(); // Read distance right
int Leftdistance();  // Read distance left
int frontdistance(); // Read front distance 
};

#endif
