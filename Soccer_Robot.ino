/*
 * Soccer Robot code:
 * 
 * This code includes all of the modes of the car: IR, Line tracker and Obstacle mdoe and bew features such as contro servo to kick ball and change of speed.
*/
#include "motor.h" // We include the library made for the motors of the car
#include "ir.h" // We include the library made for the IR 
#include "linetracker.h" // We include the library made for the line tracker
#include "obstaclemode.h" // We include the library made for the obstacle mode
#include <NewPing.h> // Includes the library "<NewPing.h>" to be able to use the ultrasonic sensor.
obstaclemode ob(10); // object of the obstacle mode
linetracker leftsensor(A2); // object of the left sensor of the line trcaker
linetracker rightsensor(A0); // object of the right sensor of the line tracker
linetracker middlesensor(A1); // object of the middle sensor of the line tracker
int IR=9; // IR pin
ir ir(IR); // object created for the IR
//Pins for the motors:
int Pin=3; // Pin for motor that will always be on.
int MotorA=7; // Motor A of the car connected to pin 7.
int MotorB=8;  // Motor B of the car connected to pin 8.

int PWMA=5; // PWMA (Pulse With Modulation A) connected to pin 5 .
int PWMB=6; // PWMB (Pulse With Modulation B) connected to pin 6.

motor Motor(Pin, MotorA, PWMA, MotorB, PWMB); //Object created using the motor library

int Speed=100; // Speed of the motors
#include <Servo.h> // Includes the library Servo motor to program the servo motor.

Servo myservo; // Creates servo object to control a servo for Ultrasonic sensor.
Servo myservo2; // Creates servo object to control a servo for Soccer robot arm.

// angle to move the servo number 2 to kick the ball
int kick_left=45;
int middle=90;
int kick_right=135;

void setup() 
{
// Initialize every class
leftsensor.begin(); 
rightsensor.begin();
middlesensor.begin();
Motor.begin(); 
ob.begin();
myservo2.attach(11);
Serial.begin(9600); 
}

void loop() 
{

  if(digitalRead(IR)==0) // Wait for a key to be pressed
  {  
    ir.read();
     //Function that reads the pressed key and stores it in the variable (key_code)
    //Action to perform according to the key pressed.
    int key_code=ir.keycode();
    switch(key_code) // switch case to chose what to do depending on the key pressed
    {
      case 25:
        Serial.println("fordward");
        Motor.forward(Speed); // Move car fordward
        break;
      case 9:
        Serial.println("left");
        Motor.left(Speed); // Move car to the left
        break;
      case 1:
        Serial.println("Stop");
        Motor.Stop(); // Stops the car
        myservo.write(90); 
        break;
      case 49:
        Serial.println("right");
        Motor.right(Speed); // Move car to the right
        break;
      case 42:
        Serial.println("backward");
        Motor.backward(Speed); // Move car backward
        break;
      case 12:
        Serial.println("one");
        // Line tracker
        if (middlesensor.read() > 45){ 
        // If the middle sensor measurement is more than 45, go fordward at low speed by calling the function "forward"
        Motor.forward(80);
        } else if (leftsensor.read() > 59){ 
        // Else if the left sensor measurement is more than 59, turn to the left at low speed by calling the function "left"
        Motor.left(80);
        } else if (rightsensor.read() > 400){
        // Else if the right sensor measurement us more than 400, turn to the right at low speed by calling the function "right"
        Motor.right(80);
        } else if (middlesensor.read() > 31 && middlesensor.read() < 45 ){
        // Else if the middle sensor is passed the end of the line, turn 360 until it finds the line again
        Motor.right(80);
        } 
        break;
      case 6:
        Serial.println("two");
        Speed=255; // change to max speed
        break;
      case 31:
        Serial.println("three");
        Speed=127; // change to middle speed
        break;
      case 4:
        Serial.println("four");
        // kick ball to the left
        myservo2.write(kick_left);  
        break;
      case 14:
        Serial.println("five");
        // kick ball to the middle
        myservo2.write(middle);  
        break;
      case 23:
        Serial.println("six");
        // kick ball to the right
        myservo2.write(kick_right);  
        break;
      case 17:
        Serial.println("seven");
        // Obstacle mode
        int distance = ob.frontdistance(); // Stores the distance's value.
        if (distance < 22) {
         /* If distance is less than 22, then the robot will stop, move backward and the servo motor will turn to the right (0°) and the left (180°),
         the variables "Distance_right" and "Distance_left" will store the values of the distance at the right and at the left.
        */
         Motor.Stop(); // Stops the car
        delay(300);
        Motor.backward(90); // Move car backward
        delay(300);
        Motor.Stop(); // Stops the car
        delay(300);
        int Distance_right = ob.Rightdistance(); // check right distance
        delay(300);   
        int Distance_left = ob.Leftdistance(); // check left distance
        delay(300);
        if ( Distance_left < 22) {
        // If the distance at the left is greater than the distance at the left, then the car will turn to the right and keep going forward
        Motor.Stop(); // Stops the car
        delay(200);
        Motor.backward(90); // Move car backward
        delay(200);
        Motor.left(90); // Move car to the left
        delay(500);
        Motor.Stop(); // Stops the car
        delay(300);
        myservo.write(90);    
        } else if ( Distance_right < 22 &&Distance_left > 22){
        // Else, if the distance at the right is greater than the distance at the right, then the car will turn to the left and keep going forward
        Motor.Stop(); // Stops the car
        delay(200);
        Motor.backward(90); // Move car backward
        delay(200);
        Motor.right(90); // Move car to the right
        delay(500);
        Motor.Stop(); // Stops the car
        delay(300); 
        myservo.write(90);    
        } else if (Distance_left > 22 && Distance_right > 22){
        // However, if both distances are lower than 22, it means that the car is in a corner, so it will turn 180° and move forward 
        Motor.Stop(); // Stops the car
        delay(200);
        Motor.backward(90); // Move car backward
        delay(200);
        Motor.right(90); // Move car to the right
        delay(1000);
        Motor.Stop(); // Stops the car
        delay(300);  
        myservo.write(90);        
         }   
       } else {
       // If the distance is not less than 25, the car will just move forward.
       Motor.forward(90); // Move car fordward
       }
        break;
      case 19:
        Serial.println("eight");
        break;
      case 21:
        Serial.println("nine");
        break;
    }
  }

}
