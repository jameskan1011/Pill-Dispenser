#include "IR_Counter.h"
#include <Arduino.h>


int irSensorPin = 23;
unsigned long lastReadingTime = 0;
unsigned long readingInterval = 0.05;
int sensorDetectionCount = 0;
bool detectionEventOccurred = false;

void setupIR(){
  pinMode(irSensorPin, INPUT);
}

void count(){
    if (millis() - lastReadingTime >= readingInterval) {
    // Update last reading time
    lastReadingTime = millis();
    
    // Read IR sensor value
    int irSensorValue = digitalRead(irSensorPin);

    // Check if the sensor has detected something and a detection event has not already occurred
    if (irSensorValue == LOW && !detectionEventOccurred) {
      // Set the detection event flag to true and increment the sensor detection count
      detectionEventOccurred = true;
      sensorDetectionCount++;
    } else if (irSensorValue == HIGH) {
      // If the sensor value is low and a detection event has occurred, reset the detection event flag
      detectionEventOccurred = false;
    }

    // Print IR sensor value and detection count to the serial monitor
    Serial.println(sensorDetectionCount);
  }
}