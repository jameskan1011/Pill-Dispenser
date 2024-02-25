#ifndef LCD_Display_H
#define LCD_Display_H

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

extern int currentPillType;
extern int pillsToTake1;
extern int pillsToTake2;
extern int pillsToTake3;
extern int pillsToTake4;

extern int intervalToTake1;
extern int intervalToTake2;
extern int intervalToTake3;
extern int intervalToTake4;

extern int startTimeToTake1;
extern int startTimeToTake2;
extern int startTimeToTake3;
extern int startTimeToTake4;

extern int storage;

extern String menuText;
extern int totalColumns;

void ClearLCD();
void InitLCD();
void scrollMessage();
void DisplayMenu();
void display_time_date();
void setNumPill();
void setInterval();
void setStartTimetoTake();
void manualDispense();

#endif