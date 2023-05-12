// MPU6050 header file:
 
// define mpu class
#ifndef MPU_H
#define MPU_H 
#include <Arduino.h> //We include the Arduino library
#include <Wire.h> // include wire.h library to be used for the mpu

class mpu{ // To open a class mpu

private: // Place where variables and functions will be hidden from the user

// Define I2C Address - change if reqiuired
const int i2c_addr = 0x3F;

//Variables for Gyroscope
int gyro_x;
int gyro_y; 
int gyro_z;
long gyro_x_cal; 
long gyro_y_cal;
long gyro_z_cal;
boolean set_gyro_angles;

long acc_x;
long acc_y; 
long acc_z; 
long acc_total_vector;
float angle_roll_acc;
float angle_pitch_acc;

float angle_pitch; 
float angle_roll;
int angle_pitch_buffer;
int angle_roll_buffer;
float angle_pitch_output;
float angle_roll_output;

// Setup timers and temp variables
long loop_timer;
int temp;

// Display counter
int displaycount = 0;

public: // Place where variables, functions and methods will be open for the user to use
mpu(){}; // default mpu constructor
void begin(); // Initialize the mpu class
int dataCount(); // Counter value
int dataRoll(); // Roll value
int dataPitch(); // Pitch value
void reset(); // Reset counter
void read_mpu_6050_data(); // read mpu data
void setup_mpu_6050_registers(); // setput mpu
};

#endif
