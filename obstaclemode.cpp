//cpp file for obstacle mode
#include "obstaclemode.h" // include header obstacle mode file
#include <NewPing.h> // Includes the library "<NewPing.h>" to be able to use the ultrasonic sensor.
#include <Servo.h> // Includes the library Servo motor to program the servo motor.

#define TRIGGER_PIN  13 // Trigger pin is 13
#define ECHO_PIN     12 // Echo pin is 12
#define MAX_DISTANCE 400 // Maximum distance we want to measure (in centimeters).

extern NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
extern Servo myservo; // Creates servo object to control a servo.

obstaclemode::obstaclemode(int servo){ // constructor to set pins
  int distance_left;
  int distance_right;
  int distance;
  this->servo = servo;
  this->distance_left=distance_left;
  this->distance_right=distance_right;
  this->distance=distance;
}

void obstaclemode::begin(){ // initialize pins for the class
myservo.attach(servo); // Sets the pin of the servo motor.
}

int obstaclemode::Rightdistance(){ // Read distance right
  // This function stores the value of the distance when the robot looks at the right.
  myservo.write(180);
  delay(300);
  distance_right = sonar.ping_cm();
  delay(300);
  return distance_right;
}

int obstaclemode::Leftdistance(){ // Read distance left
  // This function stores the value of the distance when the robot looks at the left.
  myservo.write(0);
  delay(300);
  distance_left = sonar.ping_cm();
  delay(300);
  return distance_left;
}

int obstaclemode::frontdistance(){ // Read front distance 
  distance = sonar.ping_cm();
  return distance;
}
