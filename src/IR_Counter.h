#ifndef IR_Counter_H
#define IR_Counter_H 

#include <Wire.h>
#include <Arduino.h>

extern int irSensorPin;
extern unsigned long lastReadingTime;
extern unsigned long readingInterval;
extern int sensorDetectionCount;
extern bool detectionEventOccurred;

void setupIR();
void count();

#endif