#include "LCD_Display.h"
#include "Button.h"
#include "RTC.h"
#include "ServoMotor.h"

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD I2C address and size

int currentPillType = 1;
int pillsToTake1 = 0;
int pillsToTake2 = 0;
int pillsToTake3 = 0;
int pillsToTake4 = 0;

int intervalToTake1 = 6;
int intervalToTake2 = 6;
int intervalToTake3 = 6;
int intervalToTake4 = 6;

int startTimeToTake1 = 8;
int startTimeToTake2 = 8;
int startTimeToTake3 = 8;
int startTimeToTake4 = 8;

int storage = 1;

String menuText = "";
int totalColumns = 16;

void ClearLCD(){
  lcd.clear();
}

void InitLCD(){
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pill Dispenser");
  lcd.setCursor(0, 1);
  lcd.print("Connecting to WIFI...");
}

void scrollMessage(int row, String message, int delayTime, int totalColumns) {
  if (message.length() > totalColumns) {
    String paddedMessage = message;
    for (int i=message.length(); i < totalColumns - 1; i++) {
      paddedMessage += " ";  
    } 
    paddedMessage += " "; 
    for (int position = 0; position < paddedMessage.length(); position++) {
      lcd.setCursor(0, row);
      lcd.print(paddedMessage.substring(position, position + totalColumns));
      delay(delayTime);
      ReadButton();
    }
  } else {
    String spaces = "";
    for (int i=0; i < totalColumns - message.length(); i++) {
      spaces += " ";
    }
    lcd.setCursor(0, row);
    lcd.print(message + spaces);
    ReadButton();
  }
}


void DisplayMenu(){
  lcd.setCursor(0, 0);
  lcd.print(" Pill Dispenser");
  if (current_menu == 0){
    menuText = "   INNOMAKERS";
  }
  else if (current_menu == 1){
    menuText = "Time & Date";
  }
  else if (current_menu == 2){
    menuText = "Pill Number";
  }
  else if (current_menu == 3){
    menuText = "Interval Setting";
  }
  else if (current_menu == 4){
    menuText = "Initial Time";
  }
  scrollMessage(1, menuText, 250, totalColumns);
}

void display_time_date() {
  // Display the current time on the LCD
  while (current_menu == MENU_ITEM_DISPLAY_TIME_DATE) {
  DateTime now = getTimeRTC(); //Call getTimeRTC() to get the current time and date
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  lcd.print(now.hour(), DEC);
  lcd.print(":");
  lcd.print(now.minute(), DEC);
  lcd.print(":");
  lcd.print(now.second(), DEC);
  lcd.setCursor(0, 1);
  lcd.print("Date: ");
  lcd.print(now.day(), DEC);
  lcd.print("/");
  lcd.print(now.month(), DEC);
  lcd.print("/");
  lcd.print(now.year(), DEC);
  delay(200);
  if (digitalRead(BUTTON_BACK) == HIGH) {
    lcd.clear();
    current_menu = 0;
    delay(100);
  }
 }
}

void setNumPill(){

  for (int currentPillType = 1; currentPillType <= 4; currentPillType++) {
    int pillsToTake = 0;      // the current reading from the input pin
    int lastButton3State = HIGH; 
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Pill Type ");
    lcd.print(currentPillType);
    lcd.setCursor(0, 1);
    lcd.print("Take:");
    if (currentPillType == 1){
      lcd.setCursor(10, 1);
      lcd.print(pillsToTake1);
    }
    else if (currentPillType == 2){
      lcd.setCursor(10, 1);
      lcd.print(pillsToTake2);
    }
    
    else if (currentPillType == 3){
      lcd.setCursor(10, 1);
      lcd.print(pillsToTake3);
    }
    
    else if (currentPillType == 4){
      lcd.setCursor(10, 1);
      lcd.print(pillsToTake4);
    }


    while (true) {
      int buttonPressed1 = digitalRead(BUTTON_UP);
      int buttonPressed2 = digitalRead(BUTTON_DOWN);
      int buttonPressed3 = digitalRead(BUTTON_ENTER);
      int buttonPressed4 = digitalRead(BUTTON_BACK);

      if (buttonPressed1 == HIGH) { // Increase number of pills
        pillsToTake++;
        // lcd.setCursor(0, 1);
        // lcd.print("increase");
        lcd.setCursor(10, 1);
        lcd.print(pillsToTake);
        delay(200);
      } else if (buttonPressed2 == HIGH) { // Decrease number of pills
        if (pillsToTake > 0) {
          pillsToTake--;
          // lcd.setCursor(0, 1);
          // lcd.print("decrease");
          lcd.setCursor(10, 1);
          lcd.print(pillsToTake);
          delay(200);
        }
        
      } else if (buttonPressed3 != lastButton3State) { // Finish setting pills for the current type      if (uttonPressed3 != lastButton3State){
          delay(10);
          if (buttonPressed3 == HIGH){
        switch (currentPillType) {
          case 1:
            pillsToTake1 = pillsToTake;
            break;
          case 2:
            pillsToTake2 = pillsToTake;
            break;
          case 3:
            pillsToTake3 = pillsToTake;
            break;
          case 4:
            pillsToTake4 = pillsToTake;
            break;
        }
          
        delay(500);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("All set !");
        break;
        }
      }
         lastButton3State = buttonPressed3; 
      }
    }
  }

void setInterval(){
  for (int currentPillType = 1; currentPillType <= 4; currentPillType++) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Pill Type ");
    lcd.print(currentPillType);
    lcd.setCursor(0, 1);
    lcd.print("Time interval:");
    if (currentPillType == 1){
      lcd.setCursor(14, 1);
      lcd.print(intervalToTake1);
    }
    else if (currentPillType == 2){
      lcd.setCursor(14, 1);
      lcd.print(intervalToTake2);
    }
    
    else if (currentPillType == 3){
      lcd.setCursor(14, 1);
      lcd.print(intervalToTake3);
    }
    
    else if (currentPillType == 4){
      lcd.setCursor(14, 1);
      lcd.print(intervalToTake4);
    }
    

    int intervalToTake = 6;      // default time interval is 6 hour
    int lastButton3State = HIGH; 

    while (true) {
      int buttonPressed1 = digitalRead(BUTTON_UP);
      int buttonPressed2 = digitalRead(BUTTON_DOWN);
      int buttonPressed3 = digitalRead(BUTTON_ENTER);
      int buttonPressed4 = digitalRead(BUTTON_BACK);

      if (buttonPressed1 == HIGH) { // Increase number of pills
        intervalToTake++;
        if (intervalToTake > 12){
          intervalToTake = 0;
        }
        lcd.setCursor(15,1);
        lcd.print(" ");
        lcd.setCursor(14, 1);
        lcd.print(intervalToTake);
        delay(200);
      } else if (buttonPressed2 == HIGH) { // Decrease number of pills
          intervalToTake--;
          if (intervalToTake < 0){
          intervalToTake = 12;
        }
        lcd.setCursor(15,1);
        lcd.print(" ");
        lcd.setCursor(14, 1);
        lcd.print(intervalToTake);
        delay(200);
        
        
      } else if (buttonPressed3 != lastButton3State) { // Finish setting pills for the current type      if (uttonPressed3 != lastButton3State){
          delay(10);
          if (buttonPressed3 == HIGH){
        switch (currentPillType) {
          case 1:
            intervalToTake1 = intervalToTake;
            break;
          case 2:
            intervalToTake2 = intervalToTake;
            break;
          case 3:
            intervalToTake3 = intervalToTake;
            break;
          case 4:
            intervalToTake4 = intervalToTake;
            break;
        }
          
        delay(500);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("All set !");
        break;
        }
      }
         lastButton3State = buttonPressed3; 
      }
    }
}

void setStartTimetoTake(){
  for (int currentPillType = 1; currentPillType <= 4; currentPillType++) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Pill Type ");
    lcd.print(currentPillType);
    lcd.setCursor(0, 1);
    lcd.print("Start Time:");
    if (currentPillType == 1){
      lcd.setCursor(11, 1);
      lcd.print(startTimeToTake1);
    }
    else if (currentPillType == 2){
      lcd.setCursor(11, 1);
      lcd.print(startTimeToTake2);
    }
    
    else if (currentPillType == 3){
      lcd.setCursor(11, 1);
      lcd.print(startTimeToTake3);
    }
    
    else if (currentPillType == 4){
      lcd.setCursor(11, 1);
      lcd.print(startTimeToTake4);
    }
    
    lcd.setCursor(13, 1);
    lcd.print(":00");

    int startTimeToTake = 8;      // default time interval is 6 hour
    int lastButton3State = HIGH; 

    while (true) {
      int buttonPressed1 = digitalRead(BUTTON_UP);
      int buttonPressed2 = digitalRead(BUTTON_DOWN);
      int buttonPressed3 = digitalRead(BUTTON_ENTER);
      int buttonPressed4 = digitalRead(BUTTON_BACK);

      if (buttonPressed1 == HIGH) { // Increase number of pills
        startTimeToTake++;
        if (startTimeToTake > 23){
          startTimeToTake = 0;
        }
          lcd.setCursor(12,1);
          lcd.print(" ");
          lcd.setCursor(11, 1);
          lcd.print(startTimeToTake);
          lcd.setCursor(13, 1);
          lcd.print(":00");
          delay(200);
          
      } else if (buttonPressed2 == HIGH) { // Decrease number of pills
          startTimeToTake--;
          if (startTimeToTake < 0){
          startTimeToTake = 23;
        }
        lcd.setCursor(12,1);
        lcd.print(" ");
        lcd.setCursor(11, 1);
        lcd.print(startTimeToTake);
        lcd.setCursor(13, 1);
        lcd.print(":00");
        delay(200);
        
        
      } else if (buttonPressed3 != lastButton3State) { // Finish setting pills for the current type      if (uttonPressed3 != lastButton3State){
          delay(10);
          if (buttonPressed3 == HIGH){
        switch (currentPillType) {
          case 1:
            startTimeToTake1 = startTimeToTake;
            break;
          case 2:
            startTimeToTake2 = startTimeToTake;
            break;
          case 3:
            startTimeToTake3 = startTimeToTake;
            break;
          case 4:
            startTimeToTake4 = startTimeToTake;
            break;
        }
          
        delay(500);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Dispensing...");
        break;
        }
      }
         lastButton3State = buttonPressed3; 
      }
    }
}

void manualDispense(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dispense pill");
  lcd.setCursor(0, 1);
  lcd.print("Storage: ");
  lcd.setCursor(9, 1);
  lcd.print(storage);

  int lastButton3State = HIGH;

  while (true) {
  int buttonPressed1 = digitalRead(BUTTON_UP);
  int buttonPressed2 = digitalRead(BUTTON_DOWN);
  int buttonPressed3 = digitalRead(BUTTON_ENTER);
  int buttonPressed4 = digitalRead(BUTTON_BACK);

  if (buttonPressed1 == HIGH) { // Increase number of pills
    storage++;
    if (storage > 4){
      storage = 1;
    }
      lcd.setCursor(10, 1);
      lcd.print(storage);
      delay(200);
      
  } else if (buttonPressed2 == HIGH) { // Decrease number of pills
      storage--;
      if (storage < 1){
      storage = 4;
    }
    lcd.setCursor(10, 1);
    lcd.print(storage);
    delay(200);
    
    
  } else if (buttonPressed3 != lastButton3State) { // Finish setting pills for the current type      if (uttonPressed3 != lastButton3State){
      delay(10);
      if (buttonPressed3 == HIGH){
    dispensePill(storage);
    }
      
    delay(500);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Dispensing...");
    break;
    }
  }
      lastButton3State = buttonPressed3; 
  }