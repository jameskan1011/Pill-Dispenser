#include "ServoMotor.h"
#include <Arduino.h>
#include "IR_Counter.h"

Servo servo1; 
Servo servo2; 
Servo servo3; 
Servo servo4; 

// int pos1 = 0;
// int pos2 = 0;
// int pos3 = 0;
// int pos4 = 0;

void setupServo() {
  servo1.attach(16);
  servo1.write(0);
  servo2.attach(17);
  servo2.write(0);
  servo3.attach(18);
  servo3.write(0);
  servo4.attach(19);
  servo4.write(0);
}

void dispensePill(int pillType) {
  switch(pillType) {
      case 1:
        for (int pos1 = 0; pos1 <= 180; pos1 += 10) { // goes from 0 degrees to 180 degrees
		// in steps of 1 degree
	      servo1.write(pos1);    // tell servo to go to position in variable 'pos'
	      delay(100);             // waits 15ms for the servo to reach the position
        count();
	}
	      for (int pos1 = 180; pos1 >= 0; pos1 -= 10) { // goes from 180 degrees to 0 degrees
		    servo1.write(pos1);    // tell servo to go to position in variable 'pos'
		    delay(100);             // waits 15ms for the servo to reach the position
        count();
	}
        
        break;
      case 2:
        for (int pos2 = 0; pos2 <= 180; pos2 += 10) { // goes from 0 degrees to 180 degrees
		// in steps of 1 degree
	      servo2.write(pos2);    // tell servo to go to position in variable 'pos'
	      delay(100);             // waits 15ms for the servo to reach the position
        count();
	}
	      for (int pos2 = 180; pos2 >= 0; pos2 -= 10) { // goes from 180 degrees to 0 degrees
		    servo2.write(pos2);    // tell servo to go to position in variable 'pos'
		    delay(100);             // waits 15ms for the servo to reach the position
        count();
	}
        break;
      case 3:
        for (int pos3 = 0; pos3 <= 180; pos3 += 10) { // goes from 0 degrees to 180 degrees
		// in steps of 1 degree
	      servo3.write(pos3);    // tell servo to go to position in variable 'pos'
	      delay(100);             // waits 15ms for the servo to reach the position
        count();
	}
	      for (int pos3 = 180; pos3 >= 0; pos3 -= 10) { // goes from 180 degrees to 0 degrees
		    servo3.write(pos3);    // tell servo to go to position in variable 'pos'
		    delay(100);             // waits 15ms for the servo to reach the position
        count();
	}
        break;
      case 4:
        for (int pos4 = 0; pos4 <= 180; pos4 += 10) { // goes from 0 degrees to 180 degrees
		// in steps of 1 degree
	      servo4.write(pos4);    // tell servo to go to position in variable 'pos'
	      delay(100);             // waits 15ms for the servo to reach the position
        count();
	}
	      for (int pos4 = 180; pos4 >= 0; pos4 -= 10) { // goes from 180 degrees to 0 degrees
		    servo4.write(pos4);    // tell servo to go to position in variable 'pos'
		    delay(100);             // waits 15ms for the servo to reach the position
        count();
	}
        break;
      default:
        // handle invalid pill type
        Serial.println("Invalid pill type!");
}
}
