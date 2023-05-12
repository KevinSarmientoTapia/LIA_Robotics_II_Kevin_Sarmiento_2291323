/*
 Robot car + obstacle mode

 The program's goal is to make the car automatically avoid obstacles that it finds on its way.
*/
#include "motor.h" // We include the library made for the motors of the car
#include <NewPing.h> // Includes the library "<NewPing.h>" to be able to use the ultrasonic sensor.
#include "obstaclemode.h" // includes obstacle mode class

#include <Servo.h> // Includes the library Servo motor to program the servo motor.

Servo myservo; // Creates servo object to control a servo.

obstaclemode ob(10); // Obstacle mode object with pin connected to the servo

int Pin=3; // Pin for motor that will always be on.
int MotorA=7; // Motor A of the car connected to pin 7.
int MotorB=8;  // Motor B of the car connected to pin 8.
int PWMA=5; // PWMA (Pulse With Modulation A) connected to pin 5 .
int PWMB=6; // PWMB (Pulse With Modulation B) connected to pin 6.

motor Motor(Pin, MotorA, PWMA, MotorB, PWMB); //Object created using the motor library

int Speed=100; // The car will run in a medium speed (100) to give time to the program to work properly.

void setup() {
  // put your setup code here, to run once:
Motor.begin(); // Initialize the Motor object (set pins as outputs) 
ob.begin(); // Initialize obstacle mode class
}

void loop() {
 int distance = ob.frontdistance(); // Stores the distance's value.
 if (distance < 22) {
   /* If distance is less than 22, then the robot will stop, move backward and the servo motor will turn to the right (0°) and the left (180°),
      the variables "Distance_right" and "Distance_left" will store the values of the distance at the right and at the left.
   */
   Motor.Stop(); // Stops the car
   delay(300);
   Motor.backward(Speed); // Move car backward
   delay(300);
   Motor.Stop(); // Stops the car
   delay(300);
   int Distance_right = ob.Rightdistance(); // read distance at the right
   delay(300);   
   int Distance_left = ob.Leftdistance(); // read distance at the left
   delay(300);
    if ( Distance_left < 22) {
      // If the distance at the left is greater than the distance at the left, then the car will turn to the right and keep going forward
      Motor.Stop(); // Stops the car
      delay(200);
      Motor.backward(Speed); // Move car backward
      delay(200);
      Motor.left(Speed); // Move car to the left
      delay(500);
      Motor.Stop(); // Stops the car
      delay(300);
      myservo.write(90); // move servo to the middle   
    } else if ( Distance_right < 22 &&Distance_left > 22){
      // Else, if the distance at the right is greater than the distance at the right, then the car will turn to the left and keep going forward
      Motor.Stop(); // Stops the car
      delay(200);
      Motor.backward(Speed); // Move car backward
      delay(200);
      Motor.right(Speed); // Move car to the right
      delay(500);
      Motor.Stop(); // Stops the car
      delay(300); 
      myservo.write(90); // move servo to the middle   
    } else if (Distance_left > 22 && Distance_right > 22){
      // However, if both distances are lower than 22, it means that the car is in a corner, so it will turn 180° and move forward 
      Motor.Stop(); // Stops the car
      delay(200);
      Motor.backward(Speed); // Move car backward
      delay(200);
      Motor.right(Speed); // Move car to the right
      delay(1000);
      Motor.Stop(); // Stops the car
      delay(300);  
      myservo.write(90); // move servo to the middle        
    }   
 } else {
   // If the distance is not less than 22, the car will just move forward.
 Motor.forward(Speed); // Move car fordward
 }
}
