#include "Buzzer.h"
#include <Arduino.h>

int buzzerPin = 5; // set the buzzer pin number
int beepInterval = 500; // set the interval between beeps in milliseconds
int playing = 0;

void setupBuzzer() {
  pinMode(buzzerPin, OUTPUT); // set the buzzer pin as an output
}

void tone(byte pin, int freq) {
  ledcSetup(0, 2000, 8); // setup beeper
  ledcAttachPin(pin, 0); // attach beeper
  ledcWriteTone(0, freq); // play tone
  playing = pin; // store pin
}

void noTone() {
  ledcDetachPin(playing); // detach beeper
  playing = 0; // reset playing
}

void beep(int freq, int duration) {
  tone(buzzerPin, freq); // play tone
  delay(duration); // wait for duration
  noTone(); // stop playing
}

void onBuzzer() {
  beep(1000, beepInterval); // play tone with frequency of 1000 Hz
}

void offBuzzer() {
  noTone(); // stop playing
}
