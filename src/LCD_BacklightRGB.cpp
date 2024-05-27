// LCD_BacklightRGB.cpp
#include "LCD_BacklightRGB.h"
#include <Arduino.h>

#define COMMON_ANODE

LCD_BacklightRGB::LCD_BacklightRGB(int redPin, int greenPin, int bluePin) {
    _redPin = redPin;
    _greenPin = greenPin;
    _bluePin = bluePin;
}

void LCD_BacklightRGB::begin() {
    pinMode(_redPin, OUTPUT);
    pinMode(_greenPin, OUTPUT);
    pinMode(_bluePin, OUTPUT);
}

void LCD_BacklightRGB::setRGB(int red, int green, int blue) {
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
    analogWrite(_redPin, red);
    analogWrite(_greenPin, green);
    analogWrite(_bluePin, blue);
}