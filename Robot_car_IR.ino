/*
  Robot car + IR

  The program's goal is to control the car by using an IR (Infrared Remote)by making a class.
*/
#include "motor.h" // We include the library made for the motors of the car
#include "ir.h"

int IR=9;
ir ir(IR);
//Pins for the motors:
int Pin=3; // Pin for motor that will always be on.
int MotorA=7; // Motor A of the car connected to pin 7.
int MotorB=8;  // Motor B of the car connected to pin 8.

int PWMA=5; // PWMA (Pulse With Modulation A) connected to pin 5 .
int PWMB=6; // PWMB (Pulse With Modulation B) connected to pin 6.

motor Motor(Pin, MotorA, PWMA, MotorB, PWMB); //Object created using the motor library

int Speed=127; // Speed of the motors
#include <Servo.h> // Includes the library Servo motor to program the servo motor.

Servo myservo; // Creates servo object to control a servo for Ultrasonic sensor.

void setup() 
{
Motor.begin(); // Initialize the Motor object (set pins as outputs) 
myservo.attach(10); // Sets the pin of the servo motor.
Serial.begin(9600); // Initialize the serial monitor.
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
        Speed=127; // reduce speed to 127
        break;
      case 6:
        Serial.println("two");
        Speed=255; // change to maz speed
        break;
      case 31:
        Serial.println("three");
        Speed=80; // very low speed
        break;
    }
  }

}
