#include "Button.h"
#include "LCD_Display.h"
#include "RTC.h"

int BUTTON_UP=33; // Button +
int BUTTON_DOWN=25; // Button -
int BUTTON_ENTER=26; // Enter
int BUTTON_BACK=27; // Back

int buttonPressed1 = 0;
int buttonPressed2 = 0;
int buttonPressed3 = 0;
int buttonPressed4 = 0;

int current_menu = 0;
const int num_menus = 6; // The number of menu items
const int MENU_ITEM_DISPLAY_TIME_DATE = 1;
const int MENU_ITEM_SET_NUM_PILLS = 2;
const int MENU_ITEM_SET_INTERVAL = 3;
const int MENU_ITEM_SET_START_TIME = 4;
const int MENU_ITEM_DISPENSE = 5;

void InitButton(){
  // pinMode(BUTTON_UP, INPUT_PULLUP);
  // pinMode(BUTTON_DOWN, INPUT_PULLUP);
  // pinMode(BUTTON_ENTER, INPUT_PULLUP);
  // pinMode(BUTTON_BACK, INPUT_PULLUP);
  pinMode(BUTTON_UP, INPUT);
  pinMode(BUTTON_DOWN, INPUT);
  pinMode(BUTTON_ENTER, INPUT);
  pinMode(BUTTON_BACK, INPUT);
}

void ReadButton(){
  if (digitalRead(BUTTON_UP) == HIGH) {
    current_menu++;
    if (current_menu >= num_menus) {
      current_menu = 0;
    }
    delay(200);
  }
  if (digitalRead(BUTTON_DOWN) == HIGH) {
    current_menu--;
    if (current_menu < 0) {
      current_menu = num_menus - 1;
    }
    delay(200);
  }
  if (digitalRead(BUTTON_ENTER) == HIGH) {
    handle_menu_action(current_menu);
    delay(200);
  }
  if (digitalRead(BUTTON_BACK) == HIGH) {
    ClearLCD();
    current_menu = 0;
    // lcd.print("Menu System");
    delay(200);
  }
  //delay(500);
}

void handle_menu_action(int menu_item) {
  // Handle menu item actions
  switch (menu_item) {
    case MENU_ITEM_DISPLAY_TIME_DATE:
      display_time_date();
      break;
    case MENU_ITEM_SET_NUM_PILLS:
      setNumPill();
      break;
    case MENU_ITEM_SET_INTERVAL:
      setInterval();
      break;
    case MENU_ITEM_SET_START_TIME:
      setStartTimetoTake();
      break;
    case MENU_ITEM_DISPENSE:
      manualDispense();
      break;
    default:
      break;
  }
}