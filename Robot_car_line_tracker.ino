/*
  Robot car + line tracker

  The program's goal is to make the car robot follow a black line without going out of it.

  The program's theme is the use of functions to use simplify the program.
*/
#include "motor.h" // We include the library made for the motors of the car
#include "linetracker.h" // We include the library made for the line tracker

// We create our objects for the line tracker and assign each one the corresponding analog pin:
linetracker leftsensor(A2);
linetracker rightsensor(A0);
linetracker middlesensor(A1);

//Pins for the motors:
int Pin=3; // Pin for motor that will always be on.
int MotorA=7; // Motor A of the car connected to pin 7.
int MotorB=8;  // Motor B of the car connected to pin 8.
int PWMA=5; // PWMA (Pulse With Modulation A) connected to pin 5 .
int PWMB=6; // PWMB (Pulse With Modulation B) connected to pin 6.

motor Motor(Pin, MotorA, PWMA, MotorB, PWMB); //Object created using the motor library

int Speed=80; // Speed of the motors

void setup() { // This program will run once:
Motor.begin(); // Initialize the Motor object (set pins as outputs) 
Serial.begin(9600);
// Initalize each pin for the three sensor of the line tracker (set pins as inputs):
leftsensor.begin(); 
rightsensor.begin();
middlesensor.begin();
}

void loop() { // This program will run forever:
if (middlesensor.read() > 45){ 
  // If the middle sensor measurement is more than 45, go fordward at low speed by calling the function "forward"
  Motor.forward(Speed);
} else if (leftsensor.read() > 59){ 
  // Else if the left sensor measurement is more than 59, turn to the left at low speed by calling the function "left"
  Motor.left(Speed);
} else if (rightsensor.read() > 400){
  // Else if the right sensor measurement us more than 400, turn to the right at low speed by calling the function "right"
  Motor.right(Speed);
} else if (middlesensor.read() > 31 && middlesensor.read() < 45 ){
  // Else if the middle sensor is outside the line, turn 360 degrees until it finds the line again
  Motor.right(Speed);
}
}
