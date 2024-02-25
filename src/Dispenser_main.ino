#include "RTC.h"
#include "LCD_Display.h"
#include "Button.h"
#include "Buzzer.h"
#include "ServoMotor.h"
#include "IR_Counter.h"
//#include "Firebase_data.h"
#define ONBOARD_LED  2


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  InitButton();
  setupRTC();
  setupBuzzer();
  setupServo();
  InitLCD();
  //setupFirebase();
  // pinMode(ONBOARD_LED, OUTPUT);

}

void loop() {
  DateTime now = getTimeRTC();
  ReadButton();
  DisplayMenu();
  checkMedicationTime(now);
   //sendDataToFirebase("Pill1/number", 2);

  //Serial.println(now.hour());
  // put your main code here, to run repeatedly:

}

void checkMedicationTime(DateTime now){
  
  //DateTime now = getTimeRTC();
  if (now.hour() == startTimeToTake1) {
      Serial.println("pills A");

      sensorDetectionCount = 0;

      for(int i =0; i < pillsToTake1;){
      if (sensorDetectionCount == i) 
       {
      Serial.print("Dispense Pill: ");
      Serial.println(i);
      dispensePill(1);
      i++;
       }
       else {
          dispensePill(1);
        }
       count();
    }
      // Update the next medication time for A
      startTimeToTake1 = startTimeToTake1 + intervalToTake1;
    }

  else if (now.hour() == startTimeToTake2) {
    Serial.println("pills B");

     sensorDetectionCount = 0;

    
    // Dispense pills for medication type 2
   for(int i =0; i < pillsToTake2;){
      if (sensorDetectionCount == i) 
       {
      Serial.print("Dispense Pill: ");
      Serial.println(i);
      dispensePill(2);
      i++;
       }
       else {
          dispensePill(2);
        }
       count();
    }
    // Update the next medication time for B
    startTimeToTake2 = startTimeToTake2 + intervalToTake2;
  }

  else if (now.hour() == startTimeToTake3) {
    Serial.println("pills C");

     sensorDetectionCount = 0;
    
    for(int i =0; i < pillsToTake3;){
      if (sensorDetectionCount == i) 
       {
      Serial.print("Dispense Pill: ");
      Serial.println(i);
      dispensePill(3);
      i++;
       }
       else {
          dispensePill(3);
        }
       count();
    }
    
    startTimeToTake3 = startTimeToTake3 + intervalToTake3;
  }

  else if (now.hour() == startTimeToTake4) {
    Serial.println("pills D");

     sensorDetectionCount = 0;
    
    for(int i =0; i < pillsToTake4;){
      if (sensorDetectionCount == i) 
       {
      Serial.print("Dispense Pill: ");
      Serial.println(i);
      dispensePill(4);
      i++;
       }
       else {
          dispensePill(4);
        }
       count();
    }
    
    startTimeToTake4 = startTimeToTake4 + intervalToTake4;
  }
  else 
  offBuzzer();
}
