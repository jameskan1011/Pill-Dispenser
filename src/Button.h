#ifndef Button_H
#define Button_H

#include <Wire.h>
#include <Arduino.h>


extern int BUTTON_UP; // Button SET MENU'
extern int BUTTON_DOWN; // Button +
extern int BUTTON_ENTER; // Button -
extern int BUTTON_BACK; // SWITCH Alarm

extern int buttonPressed1;
extern int buttonPressed2;
extern int buttonPressed3;
extern int buttonPressed4;

extern int current_menu;
extern const int num_menus; // The number of menu items
extern const int MENU_ITEM_DISPLAY_TIME_DATE;
extern const int MENU_ITEM_SET_TIME;
extern const int MENU_ITEM_SET_NUM_PILLS;
extern const int MENU_ITEM_SET_INTERVAL;
extern const int MENU_ITEM_SET_START_TIME;

void handle_menu_action(int menu_item);
void InitButton();
void ReadButton();

#endif