#ifndef Buzzer_H
#define Buzzer_H 

#include <Wire.h>
#include <Arduino.h>

extern int buzzerPin; // set the buzzer pin number
extern int beepInterval; 
extern int playing;

void setupBuzzer();
void onBuzzer();
void offBuzzer();
void tone(byte pin, int freq);
void notone();
void beep(int freq, int duration);

#endif