#ifndef ServoMotor_H
#define ServoMotor_H 

#include <Wire.h>
#include <Arduino.h>
#include <ESP32Servo.h>

// extern int pos1;
// extern int pos2;
// extern int pos3;
// extern int pos4;

void setupServo();
void dispensePill(int pillType);

#endif