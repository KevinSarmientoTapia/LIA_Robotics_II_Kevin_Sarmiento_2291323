/*
  mpu class

  This class simplifies the Wire.h libary to be used with the MPU 6050.
*/

// Include Wire Library for I2C
#include <Wire.h>
#include "mpu.h" // Includes the created mpu header file

mpu mpu; //we create our mpu object

int displaycount; // vairable to store the counter value of the class
int angle_pitch_output; // variable to store the pitch angle obtained with the class
int angle_roll_output; // variable to store the roll angle obtained with the class

void setup() {
mpu.begin(); // we initialize the mpu class                                          
}

void loop(){

angle_roll_output=mpu.dataRoll(); // variable to store the data of the roll angle
angle_pitch_output=mpu.dataPitch(); // variable to store the data of the pitch angle
displaycount=mpu.dataCount(); // variable to store the data of the counter

if (displaycount > 100) { // if displaycount is more than 100 print the pitch and roll angle value:

  Serial.print("Pitch: "); 
  Serial.print(angle_pitch_output);
  Serial.print("       ");
  Serial.print("Roll: ");
  Serial.println(angle_roll_output);
  
  }

mpu.reset(); // reset the counter
}
