#ifndef RTC_H
#define RTC_H 

#include <Wire.h>
#include <RTClib.h>
#include <Arduino.h>


void setupRTC();
DateTime getTimeRTC();

#endif