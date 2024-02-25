#include "LCD_Display.h"
#include "RTC.h"

RTC_DS3231 rtc;

void setupRTC(){
  Wire.begin();
  rtc.begin();
  //rtc.adjust(DateTime(__DATE__, __TIME__));
  if (!rtc.begin()) {
    // lcd.print("RTC not found!");
    while (1);
  }

  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

DateTime getTimeRTC(){
  DateTime now = rtc.now();
  return now;
};
